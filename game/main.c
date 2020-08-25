/** (C) Matt Hughson 2020 */

#include "LIB/neslib.h"
#include "LIB/nesdoug.h"
#include "BG/game_area.h"
#include "BG/title_screen.h"
#include "BG/options_screen.h"
#include "BG/boot_screen.h"
#include "BG/sound_screen.h"
#include "BG/ty_screen.h"
#include "../include/stdlib.h"
#include "main.h"

/*

..::TODO::..

FEATURES:

//must have
--

//should have
--

//nice to have
* Ghost pieces.
* Lock-delay settings (off, 10 frames, 20 frames)
* Options on the Pause screen (quit, music, sfx).
* Store blocks. (classic only?)
* Update mode order and names to be (will require more space):
	* Kraken, Classic, Kraken Alt* Description of modes in option screen.
* Game over screen (polished).
* Points kicker
* Trigger sound test on Konami Code.
* Special Thanks screen
* Allow players to start on any level up to 29.

//investigate
* Number of rows that hit the tentacle adds a delay to next attack.
* Screen shake on hit. (others say this is annoying)
* Hard drop trails. (likely too much cpu)
* Drought reduction: have a max number of turns a piece can drought. If hit that max, for it to be played.

//sound
* Kraken hit.
* Kraken hitx4
* landing should be louder


COMPLETE:
* Start level 29.
	* Select + Start on level 9.
* Disable hard drop (not on hold - People either want it or not).
	* Added 3 settings: off, tap, hold.
* Test NES rotations (confirmed)
* Delay at start of match (maybe only high levels?)
* Kill screen ideas:
- Remove lock delay.
- Shrink the play area. << THIS
- 2 block drops.
* Hard drop on HOLD.
* Reset on A+B+SEL+START
* Option to disable hard-drop (or require a slight hold to trigger hard drop.)
	* No hold setting, just on or off.
* Add ARE (spawn delay) Maybe 5 frames, and switch lock delay to 15.
* Clean up sound test.
* Hi-score display (per mode).
	* Couldn't find a good spot during gameplay, so currently only in the options.
* Option to turn off SFX.
* Update to use NES block layouts.
	* Update to have all blocks start face down. (was just T block actually).
* Score for Classic mode.
	* 1 lines:		2 lines:		3 lines:		4 lines:
	* 40 * (n + 1)	100 * (n + 1) 	300 * (n + 1) 	1200 * (n + 1)
	* + 1 point for ever row soft/hard dropped over. [cut]
* Clean up options:
	* Remove credits. [done]
	* Remove "block type". [done]
	* Re-add tower. [cut]
	* Starting level. [done]
* Credits on boot.
* More clear path out of options.
	* Change flow to go through options on the way to gameplay state.
* Safe zone issues.
* Faster start.
* Fast music when tentacle is maxed out.
* Better lock delay (consistent).
* Wall kicks
* Multiple tentacles. - possibly if when reaching top they go into name table.
* Pal swap based on time of day/night.
* Option to return to main menu on game over.
* Non-Nintendo blocks. (not fun :()
* Hard drop (up on d-pad).
* Option screen.
* Credits screen.
* Time based tentacle movement (rather than on landing).
* Option to choose between Kraken and Klassic gameplay. (classic may require score, ability to go back to main menu).
* Push start flashing text.

CUT:
* See if tentacles can be made to work with name tables.
	* Want to keep animation.
* When on Level 29, display MAX instead.
	* Doge suggested showing levels beyond 29.
	* Added "Kill Screen"
* Last chance move on hard drop (maybe optional).
	* Feels weird. See commented out code in movement().
* Sound on hit tentacle.
	* Really need mutliple sounds for 4 line hit too.
* Sound on drop and then lock.
	* Don't like that it won't be consistent between lockdelay and just slow falling.

BUGS:
* Flicker on hard drop.
* Can get game over when spawned piece clears a line. Wouldn't be so bad if the line didn't get cleared.
* Kraken eye is all glitches when hitting tentacle on hardware.
	* Krysio kart only. Need resistor on pins?
* "When I was in the middle of playing a game the sound test came up, i was on a pink stage but couldn't catch the level." - KittyFae

COMPLETE:
* Flickering sprites when pressing select during Kraken modes.
* Blocks are not falling fast enough on soft drop
	* Was falling every 3 frames instead of 2 frames.
* Bad wall kick: http://harddrop.com/fumen/?m115@fhB8NemL2SAy3WeD0488AwkUNEjhd5DzoBAAvhA+qu?AA
	* Discovered a couple problems on top of special case for lines is now only lines.
* SKULL doesn't clear on game over.
* Game Over eat into side of nametable (1 tile too far).
* "the way nestris does it is it declares you dead when two pieces overlap which happens when there's a piece where the next piece spawns"
* Garbage in nametable after playing "timed", quiting to main menu, and entering options and changing a few settings.
	* likely writing too many values in display_options, not sure why not 100% though.
	* suspect you can hit this change an option with a high score at the same time PUSH START is toggled on/off
* Quick fall rate sometimes: https://clips.twitch.tv/FuriousIntelligentClipzMau5
* After quiting to main menu, previous match "next" block continues to show.
* S and Z are too high when flat (or too low when vert)
* If starting on level 10+, level up is happening on wrong level (happens as
  soon as player hits 110 lines, regardles of starting level).
* Next block is hidden during line clear.
* When hitting game over, final sprite switches.
	* I think this is because the vram buffer is cleared at the start of game over, 
	  before it has a chance to copy over the new block to the nametable.
* CNR - Horz input has to be pressed again if line is cleared.
* Hitch when tentacle retracts on hitting max (because of delays).
* At level 29, the blocks never trigger game over.
* Music isn't playing on main menu.
* Moving tentacle keeps moving after reaching max (possibly fixed with multi-tentacle attack).
* Tentacles are not budgeted.
* Graphical corruption on Game Over (rarely)
* Hard drop puts blocks 1 tile too far (rarely).
* Sprite flicker when blocks land.

CUT:
* Sprites do not draw when transitioning between name tables.
	* Don't care enough to redo how transitions work.

SCRIPT IDEAS:

* LAND - Make every move count! Rewards deliberate play. Punishes sloppy.
* TIME - Race to get as much done as possible before the Kraken attacks. Rewards fast play. Punishes overthinking.
* CLASSIC - The traditional block dropping puzzle mechanics you know and love.

* Story -

The Kraken cometh...

From the deepest trenches of the ocean, the Kraken has come to lay waste to your city!

The archers have slung every arrow.
The burning tar has run dry.
Every piece of military weaponary has been dispatch.

And yet... the Kraken moves forward, climbing the towering walls of your seaside fortress.

With no ammunition left, the city itself moves from a barricade, to weapon!

The stones of the walls are broken off, and hurdled down at hidious creature. And it just might be enough to
slow it down till morning, when surely help will arrive...

* Manual:
- Have a page with text book lore about the Kraken, with some cool pictures.
- A page for each mode.
- A making of section about how the game was created.

*/

void on_reset (void)
{
	// POKE(0x300, 255);
	// POKE(0x301, 255);
}

void main (void)
{
	ppu_off(); // screen off

	// load the palettes
	//pal_bg(palette_bg);
	//pal_spr(palette_sp);

	// use the second set of tiles for sprites
	// both bg and sprites are set to 0 by default
	bank_spr(1);

	set_vram_buffer(); // do at least once, sets a pointer to a buffer
	clear_vram_buffer();

	// TODO: This is actually the gameplay setup.
	off_nt = 0;
	cur_nt = 2;

	vram_adr(NTADR_A(0,0));
	vram_unrle(title_screen);
	vram_adr(NTADR_C(0,0));
	vram_unrle(game_area);

	scroll(0, 0x1df); // shift the bg down 1 pixel
	//set_scroll_y(0xff);

	ppu_on_all(); // turn on screen

	//music_play(0);

	attack_style = ATTACK_ON_TIME;// ATTACK_ON_LAND;
	music_on = 1;
	sfx_on = 1;
	hard_drops_on = 1;
	block_style = BLOCK_STYLE_CLASSIC;
	state = 0xff; // uninitialized so that we don't trigger a "leaving state".
	cur_garbage_type = 0;

	pal_bright(0);
	go_to_state(STATE_BOOT);
	fade_from_black();

	// infinite loop
	while (1)
	{
		ppu_wait_nmi(); // wait till beginning of the frame

		//set_music_speed(1);

		++tick_count;
		++tick_count_large;

		pad1 = pad_poll(0); // read the first controller
		pad1_new = get_pad_new(0); // newly pressed button. do pad_poll first

		clear_vram_buffer(); // do at the beginning of each frame

		// Quick reset.
		if (state != STATE_MENU)
		{
			if (pad1 & PAD_A && pad1 & PAD_B && pad1 & PAD_SELECT && pad1 & PAD_START)
			{
				go_to_state(STATE_MENU);
			}
		}

		switch(state)
		{
			case STATE_BOOT:
			{
				if (tick_count == 120 || pad1_new & PAD_START)
				{
					fade_to_black();
					go_to_state(STATE_TY);
					fade_from_black();
				}
				break;
			}
			case STATE_TY:
			{
				// 120, means wait 240 frames from 120 (previous state).
				if (tick_count == 104 || pad1_new & PAD_START)
				{
					fade_to_black();
					go_to_state(STATE_MENU);
					fade_from_black();
				}
				break;
			}
			case STATE_MENU:
			{
				draw_menu_sprites();

				if (tick_count % 128 == 0)
				{
					multi_vram_buffer_horz(text_push_start, sizeof(text_push_start)-1, get_ppu_addr(0, 12<<3, 12<<3));
				}
				else if (tick_count % 128 == 96)
				{
					multi_vram_buffer_horz(clear_push_start, sizeof(clear_push_start)-1, get_ppu_addr(0, 12<<3, 12<<3));
				}

				if (pad1_new != 0)
				{
					if (pad1_new & konami_code[cur_konami_index])
					{
						++cur_konami_index;
					}
					else
					{
						cur_konami_index = 0;
					}
				}

				if (pad1_new & PAD_START)
				{
					srand(tick_count_large);

					if (cur_konami_index >= KONAMI_CODE_LEN)
					{
						SFX_PLAY_WRAPPER(SOUND_LEVELUP_MULTI);
						music_stop();
						go_to_state(STATE_SOUND_TEST);
					}
					else
					{
						fade_to_black();
						go_to_state(STATE_OPTIONS);
						fade_from_black();
					}
				}
				break;
			}

			case STATE_OPTIONS:
			{
				if (tick_count % 128 == 0)
				{
					multi_vram_buffer_horz(text_push_start, sizeof(text_push_start)-1, get_ppu_addr(0, 12<<3, 12<<3));
				}
				else if (tick_count % 128 == 96)
				{
					multi_vram_buffer_horz(clear_push_start, sizeof(clear_push_start)-1, get_ppu_addr(0, 12<<3, 12<<3));
				}

				if (pad1_new & PAD_START)
				{
					music_stop();
					SFX_PLAY_WRAPPER(SOUND_START);

					fade_to_black();
					ppu_off();
					vram_adr(NTADR_A(0,0));
					vram_unrle(title_screen);
					ppu_on_all();
					fade_from_black();

					// little cheat to start at very high levels.
					if (cur_level == 9 && pad1 & PAD_SELECT)
					{
						cur_level = 29;
					}
					else if (pad1 & PAD_A)
					{
						cur_level += 10;
					}
					go_to_state(STATE_GAME);
				}

				if (pad1_new & PAD_B)
				{
					fade_to_black();
					go_to_state(STATE_MENU);
					fade_from_black();
				}
				else if (pad1_new & PAD_RIGHT)
				{
					switch (cur_option)
					{

					case 0: // starting level

						if (cur_level < 9 )
						{
							++cur_level;
						}
						else 
						{
							cur_level = 0;
						}
						break;

					case 1: // Attack style

						//attack_style = (attack_style + 1) % ATTACK_NUM;

						if (attack_style < ATTACK_NUM - 1)
						{
							++attack_style;
							display_highscore();
						}
						break;

					case 2: // Music off/on

						//music_on = (music_on + 1) % 2;

						if (music_on == 0)
						{
							music_on = 1;
							MUSIC_PLAY_WRAPPER(MUSIC_TITLE);
							music_pause(0);
						}

						// if (music_on == 0)
						// {
						// 	music_stop();
						// }
						// else
						// {
						// 	music_play(MUSIC_TITLE);
						// }
						break;

					case 3: // sound fx on/off
					{
						if (sfx_on == 0)
						{
							sfx_on = 1;
						}
						break;
					}

					case 4: // hard drops
					{
						if (hard_drops_on < NUM_HARD_DROP_SETTINGS - 1)
						{
							++hard_drops_on;
						}
					}

					default:
						break;
					}

					SFX_PLAY_WRAPPER(SOUND_MENU_HIGH);
					display_options();
				}
				else if (pad1_new & PAD_LEFT)
				{
					switch (cur_option)
					{

					case 0: // starting level

						if (cur_level != 0)
						{
							--cur_level;
						}
						else
						{
							cur_level = 9;
						}
						break;

					case 1: // Attack style
						// if (attack_style == 0)
						// {
						// 	attack_style = ATTACK_NUM;
						// }
						// attack_style = (attack_style - 1) % ATTACK_NUM;

						if (attack_style != 0)
						{
							--attack_style;
							display_highscore();
						}

						break;

					case 2: // Music off/on
						// if (music_on == 0)
						// {
						// 	music_on = 2;
						// }
						// music_on = (music_on - 1) % 2;

						if (music_on != 0)
						{
							music_on = 0;
							music_pause(1);
							music_stop();
						}

						// if (music_on == 0)
						// {
						// 	music_stop();
						// }
						// else
						// {
						// 	music_play(MUSIC_TITLE);
						// }

						break;

					case 3: // sound fx off/on
					{
						if (sfx_on != 0)
						{
							sfx_on = 0;
						}
						break;
					}
					case 4: // hard drops
					{
						if (hard_drops_on != 0)
						{
							--hard_drops_on;
						}
						break;
					}

					default:
						break;
					}

					SFX_PLAY_WRAPPER(SOUND_MENU_LOW);
					display_options();
				}
				else if (pad1_new & PAD_DOWN)
				{
					cur_option = (cur_option + 1) % NUM_OPTIONS;
					SFX_PLAY_WRAPPER(SOUND_MENU_LOW);
					display_options();
				}
				else if (pad1_new & PAD_UP)
				{
					if (cur_option == 0)
					{
						cur_option = NUM_OPTIONS;
					}
					cur_option = (cur_option - 1) % NUM_OPTIONS;
					SFX_PLAY_WRAPPER(SOUND_MENU_HIGH);
					display_options();
				}
				break;
			}

			case STATE_GAME:
			{
				if (hit_reaction_remaining > 0)
				{
					--hit_reaction_remaining;
				}

				if (row_to_clear >= 0)
				{

					--attack_row_status[row_to_clear];
					if (attack_row_status[row_to_clear] == 0)
					{
						row_to_clear = -1;
					}
				}

				// delay a frame for perf.
				if (attack_style != ATTACK_NEVER && attack_queued)
				{
//PROFILE_POKE(PROF_R);
					// TODO: Perf - Very expensive.
					add_block_at_bottom();
//PROFILE_POKE(PROF_W);
					clear_rows_in_data(BOARD_END_Y_PX_BOARD);
					attack_queued = 0;
					attack_queue_ticks_remaining = attack_delay;
				}

				if (kill_row_queued)
				{
					add_row_at_bottom();
					kill_row_queued = 0;
				}

//PROFILE_POKE(PROF_G);

				if (delay_spawn_remaining != -1)
				{
					// This would normally be done in movement(), but since that isn't being
					// called we want to make sure charge DAS works.
					if (horz_button_delay > 0)
					{
						--horz_button_delay;
					}
					--delay_spawn_remaining;
					if (delay_spawn_remaining == 0)
					{
						spawn_new_cluster();
						delay_lock_remaining = -1;
					}
				}
				else
				{
					movement();
				}
				
//PROFILE_POKE(PROF_B);

				draw_gameplay_sprites();

//PROFILE_POKE(PROF_W);

				if (attack_style == ATTACK_ON_TIME && attack_queue_ticks_remaining != 0)
				{
					--attack_queue_ticks_remaining;

					if (attack_queue_ticks_remaining == 0)
					{
						attack_queued = 1;
						attack_queue_ticks_remaining = attack_delay;
					}
				}

				// STRESS MUSIC!

				local_t = 0;
				for (local_iy = 0; local_iy < STRESS_MUSIC_LEVEL * 10; ++local_iy)
				{
					if (game_board[local_iy + ((BOARD_OOB_END + 1) * 10)] != 0)
					{
						// music is stressed even if it doesn't start playing this frame.
						local_t = 1;

						if (cur_gameplay_music == MUSIC_GAMEPLAY)
						{
							cur_gameplay_music = MUSIC_STRESS;
							MUSIC_PLAY_WRAPPER(MUSIC_STRESS);
							break;
						}
					}
				}

				if (local_t == 0 && cur_gameplay_music == MUSIC_STRESS)
				{
					cur_gameplay_music = MUSIC_GAMEPLAY;
					MUSIC_PLAY_WRAPPER(MUSIC_GAMEPLAY);
				}

				if (pad1_new & PAD_START)
				{
					go_to_state(STATE_PAUSE);
				}

#if DEBUG_ENABLED
				// if (pad1_new & PAD_START)
				// {

				// 	memcpy(temp_pal, palette_bg, sizeof(palette_bg));
				// 	pal_id += 2;
				// 	pal_id = pal_id % 20;
				// 	temp_pal[1] = pal_changes[pal_id];
				// 	temp_pal[2] = pal_changes[pal_id + 1];
				// 	pal_bg(temp_pal);
				// 	debug_display_number(pal_id >> 1, 0);

				// 	//debug_copy_board_data_to_nt();
				// 	//go_to_state(STATE_OVER);
				// }
#endif
//PROFILE_POKE(PROF_CLEAR);
				break;
			}

			case STATE_PAUSE:
			{
				oam_clear();

				// if ((tick_count % 60) < 30)
				// {
				// 	draw_sprites();
				// }
				// else
				// {
				// 	oam_clear();
				// }


				if (pad1_new & PAD_START)
				{
					go_to_state(STATE_GAME);
				}
				break;
			}

			case STATE_OVER:
			{
				if (pad1_new & PAD_B)
				{
					//go_to_state(STATE_GAME);
					go_to_state(STATE_MENU);
				}
				if (pad1_new & PAD_A)
				{
					//go_to_state(STATE_GAME);
					go_to_state(STATE_GAME);
				}
				break;
			}

			case STATE_SOUND_TEST:
			{				
				// MUSIC
				//

				if (pad1_new & PAD_DOWN && test_song < 15)
				{
					++test_song;
					display_song();
				}
				else if (pad1_new & PAD_UP && test_song > 0)
				{
					--test_song;
					display_song();
				}

				if (pad1_new & PAD_B)
				{
					if (test_song == test_song_active)
					{
						test_song_active = 0xff;
						music_stop();
					}
					else
					{
						test_song_active = test_song;
						// ignore settings.
						music_play(test_song);
					}
				}


				// SOUND
				//

				if (pad1_new & PAD_RIGHT && test_sound < 31)
				{
					++test_sound;
					display_sound();
				}
				else if (pad1_new & PAD_LEFT && test_sound > 0)
				{
					--test_sound;
					display_sound();
				}

				if (pad1_new & PAD_A)
				{
					// Intentionally not using wrapper so this plays regardless of settings.
					sfx_play(test_sound, 0);
				}

				// EXIT
				//

				if (pad1_new & PAD_SELECT || pad1_new & PAD_START)
				{
					go_to_state(STATE_MENU);
				}
				break;
			}
		}
	}
}

void draw_menu_sprites(void)
{
	static unsigned char t;

	// clear all sprites from sprite buffer
	oam_clear();

	// FLAGS
	t = tick_count % 64;
	if (t > 48)
	{
		local_ix = 0x69;
	}
	else if (t > 32)
	{
		local_ix = 0x68;
	}
	else if (t > 16)
	{
		local_ix = 0x67;
	}
	else
	{
		local_ix = 0x66;
	}

	oam_spr(10 << 3, 23 << 3, local_ix, 0);
	oam_spr(22 << 3, 23 << 3, local_ix, 0);

	// TENTACLES
	oam_spr(19 << 3, 14 << 3, 0x60, 1);
	oam_spr(20 << 3, 14 << 3, 0x61, 1);

	oam_spr(19 << 3, 15 << 3, 0x70, 1);
	oam_spr(20 << 3, 15 << 3, 0x71, 1);

	oam_spr(19 << 3, 16 << 3, 0x80, 1);
	oam_spr(20 << 3, 16 << 3, 0x81, 1);

	oam_spr(19 << 3, 17 << 3, 0x90, 1);
	oam_spr(20 << 3, 17 << 3, 0x91, 1);
}

void draw_gameplay_sprites(void)
{
	static char shake_offset;
	static unsigned char speed;
	static unsigned char i;
	static unsigned char j;

//PROFILE_POKE(0x5f); // green
	// clear all sprites from sprite buffer
	oam_clear();
//PROFILE_POKE(0x9f); // blue
	// push a single sprite
	// oam_spr(unsigned char x,unsigned char y,unsigned char chrnum,unsigned char attr);
	// use tile #0, palette #0

	local_start_x = (cur_block.x << 3) + BOARD_START_X_PX;
	local_start_y = (cur_block.y << 3) + BOARD_START_Y_PX;

	// 255 means hide.
	if (cur_block.y != 255)
	{
		for (i = 0; i < 4; ++i)
		{
			// store the index into the x,y offset for each solid piece in the first rotation.
			j = cur_cluster.layout[i];

			// conver that to x,y offsets.
			local_ix = index_to_x_lookup[j];
			local_iy = index_to_y_lookup[j];

			// Don't draw the current cluster if it is above the top of the board.
			// We want it to be able to function and move up there, but should not
			// be visible.
			if (local_start_y + (local_iy << 3) > OOB_TOP)
			{
				oam_spr(local_start_x + (local_ix << 3), local_start_y + (local_iy << 3), cur_cluster.sprite, 0);
			}
		}
	}

//PROFILE_POKE(0x1f); // white

	if (attack_style != ATTACK_NEVER)
	{
		shake_offset = 0;
		if (attack_style == ATTACK_ON_TIME)
		{
			if (attack_queue_ticks_remaining < 120)
			{
				speed = tick_count >> 2;
			}
			else if (attack_queue_ticks_remaining < 300)
			{
				speed = tick_count >> 3;
			}
			else
			{
				speed = tick_count >> 5;
			}
		}
		else
		{
			speed = tick_count >> 4;
		}

		// Loop through the attack columns and draw the off board portion as sprites.
		for (local_ix = 0; local_ix < BOARD_WIDTH; ++local_ix)
		{
			local_row_status = attack_row_status[local_ix];
			if (local_row_status > 0)
			{
				for (local_iy = 0; local_iy < local_row_status /*&& local_iy < ATTACK_QUEUE_SIZE*/; ++local_iy)
				{
					//if (attack_queue_ticks_remaining < 120)
					{
						//if (attack_queue_ticks_remaining % 8 == 0) // %8
						{
							//shake_offset = ((local_iy + (attack_queue_ticks_remaining << 4)) % 3) - 1;
						}
					}

					shake_offset = tenatcle_offsets[((local_iy + speed) & 3)]; // &3 = %4 = number of entries in array.

					// gross. Try to detect if this is the last piece, and also the end of the arm.
					if (local_iy == local_row_status - 1)
					{
					oam_spr(
						BOARD_START_X_PX + (local_ix << 3) + shake_offset,
						(BOARD_END_Y_PX) + (ATTACK_QUEUE_SIZE << 3) - (local_iy << 3),
						0xf9,
						1);
					}
					else
					{
					oam_spr(
						BOARD_START_X_PX + (local_ix << 3) + shake_offset,
						(BOARD_END_Y_PX) + (ATTACK_QUEUE_SIZE << 3) - (local_iy << 3),
						0xf8,
						1);
					}

				}
			}
		}
	}

	// oam_spr((22)<<3, 8<<3, 0x21, 3);
	// for (local_ix = 0; local_ix < 6; ++local_ix)
	// {
	// 	oam_spr((23+local_ix)<<3, 8<<3, '1' + local_ix, 3);
	// }

//PROFILE_POKE(0x3f); // red

	// HIT REACTION
	if (hit_reaction_remaining > 0)
	{
		// -1, 0, 1
		//r = (rand8() % 3) - 1;
		oam_spr((3 << 3) /*+ r*/, (24 << 3), 0x65, 1);
		oam_spr(3 << 3, 25 << 3, 0x64, 1);
		oam_spr(3 << 3, 26 << 3, 0x74, 1);

		// memcpy(temp_pal, palette_sp, sizeof(palette_sp));
		// // blocks
		// //temp_pal[4] = 0x15;
		// //temp_pal[5] = 0x15;
		// temp_pal[6] = 0x16;
		// //temp_pal[7] = 0x16;
		// pal_spr(temp_pal);

		// memcpy(temp_pal, palette_bg, sizeof(palette_bg));
		// // blocks
		// //temp_pal[12] = 0x15;
		// //temp_pal[13] = 0x15;
		// temp_pal[14] = 0x16;
		// //temp_pal[15] = 0x16;
		// pal_bg(temp_pal);
	}
	// BLINKING
	else
	{
		if (attack_style == ATTACK_NEVER)
		{
			// sleeping
			oam_spr(3 << 3, 25 << 3, 0x63, 1);
			oam_spr(3 << 3, 26 << 3, 0x73, 1);
		}
		else
		{
			//pal_spr(palette_sp);
			//pal_bg(palette_bg);
			local_t = tick_count_large % BLINK_LEN;

			if (local_t > BLINK_LEN - 5)
			{
				oam_spr(3 << 3, 25 << 3, 0x62, 1);
				oam_spr(3 << 3, 26 << 3, 0x72, 1);
			}
			else if (local_t > (BLINK_LEN - 10))
			{
				oam_spr(3 << 3, 25 << 3, 0x63, 1);
				oam_spr(3 << 3, 26 << 3, 0x73, 1);
			}
			else if (local_t > BLINK_LEN - 15)
			{
				oam_spr(3 << 3, 25 << 3, 0x62, 1);
				oam_spr(3 << 3, 26 << 3, 0x72, 1);
			}
		}
	}

	// FLAGS
	local_t = tick_count & 63;
	if (local_t > 48)
	{
		local_ix = 0x69;
	}
	else if (local_t > 32)
	{
		local_ix = 0x68;
	}
	else if (local_t > 16)
	{
		local_ix = 0x67;
	}
	else
	{
		local_ix = 0x66;
	}

	oam_spr(8 << 3, 1 << 3, local_ix, 2);
	oam_spr(24 << 3, 1 << 3, local_ix, 2);
	oam_spr(3 << 3, 10 << 3, local_ix, 0);
	oam_spr(27 << 3, 10 << 3, local_ix, 0);

	//debug_draw_board_area();
}

void movement(void)
{
	static unsigned char hard_drop_performed;

	hit = 0;
	temp_fall_frame_counter = 0;
	old_x = 0;
	delay_lock_skip = 0;

	if (start_delay_remaining == 0)
	{
		--fall_frame_counter;
	}
	else
	{
		--start_delay_remaining;
	}
	

	if (pad1_new & PAD_SELECT)
	{
		//hit_reaction_remaining = 60;
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//  inc_lines_cleared();
		//  delay(1);
		//lines_cleared_one = 9;
		//inc_lines_cleared();
		//add_block_at_bottom();
		//spawn_new_cluster();

		// Don't allow forcing the tentacle up while it is on the way down.
		// Not too serious, but looks weird when the height in increases 
		// while the sprites are not moving up.
		if (row_to_clear == -1)
		{
			attack_queued = 1;
		}
	}

	// INPUT

	if (pad1_new & PAD_A)
	{
		rotate_cur_cluster(1);
	}
	else if (pad1_new & PAD_B)
	{
		rotate_cur_cluster(-1);
	}

	if (horz_button_delay > 0)
	{
		--horz_button_delay;
	}

	old_x = cur_block.x;
	if (((pad1 & PAD_RIGHT) && horz_button_delay == 0) || (pad1_new & PAD_RIGHT))
	{
		horz_button_delay = button_delay;
		if ((pad1_new & PAD_RIGHT))
		{
			horz_button_delay <<= 1;
		}

		// if (cur_block.x < BOARD_END_X_PX_BOARD)
		// {
			old_x = cur_block.x;
			cur_block.x += 1;
		// }
		// else
		// {
		// 	cur_block.x = BOARD_END_X_PX_BOARD;
		// }

	}
	else if (((pad1 & PAD_LEFT) && horz_button_delay == 0) || pad1_new & PAD_LEFT)
	{
		horz_button_delay = button_delay;
		if ((pad1_new & PAD_LEFT))
		{
			// normal delay * 8
			horz_button_delay <<= 1;
		}
		// handle here since x is unsigned.
		// if (cur_block.x > 0)
		// {
			old_x = cur_block.x;
			cur_block.x -= 1; // note: wrap around
		// }
		// else
		// {
		// 	cur_block.x = 0;
		// }

	}

	// Only check for collision if we actually moved horz.
	// Otherwise spawning into another tile will cause horz
	// correction.
	if (cur_block.x != old_x && is_cluster_colliding())
	{
		cur_block.x = old_x;
	}

	// FALLING

	// TODO: There is some inconsistencies with this approach.
	//		 A frame after pressing Down might turn out to be
	//		 the normal fall rate frame, causing 2 frames in a row
	//		 to fall.
	//		 Similarly, shortly after releasing Down, we might hit
	//		 a natural fall frame, causing it to seem like down was
	//		 held a little longer.
	//		 To fix, I think tick_count should be tracked seperate for
	//		 this function so that it can be manipulated (eg. when release
	//	     reset the tick count).
	temp_fall_frame_counter = fall_frame_counter;

	hard_drop_performed = 0;
	if (hard_drops_on && pad1 & PAD_UP && (pad1 & (PAD_LEFT|PAD_RIGHT)) == 0)
	{
		if ((pad1 & PAD_UP && hard_drop_tap_required == 0) || pad1_new & PAD_UP)
		{
			--hard_drop_hold_remaining;	

			if (hard_drop_hold_remaining == 0)
			{
				hard_drop_performed = 1;
				hard_drop_tap_required = 1;
				
				// TODO: Causes hitch.
				while (!is_cluster_colliding())
				{
					++cur_block.y;
				}

				// No delay lock on hard drops.
				delay_lock_skip = 1;

				// UNCOMMENT FOR LAST CHANCE MOVE ON HARD DROP
				// cur_block.y -= 1;
				// fall_frame_counter = 1;
			}
		}
	}
	else
	{
		if ((pad1 & (PAD_LEFT|PAD_RIGHT)) == 0)
		{
			hard_drop_tap_required = 0;
		}
		if (hard_drops_on == 1) // tap
		{
			hard_drop_hold_remaining = 1;
		}
		else if (hard_drops_on == 2) // hold
		{
			hard_drop_hold_remaining = HARD_DROP_HOLD_TIME;
		}
	}
	
	
	if (hard_drop_performed == 0)
	{
		// Hard drop skips all this to avoid dropping to the bottom
		// and then dropping again because it happens to be
		// the natural fall frame.
		if (pad1_new & PAD_DOWN || delay_lock_remaining != -1)
		{
			if (pad1_new & PAD_DOWN)
			{
				// if a new press was made this frame, skip the delay lock.
				delay_lock_skip = 1;
			}
			require_new_down_button = 0;

			// fall this frame.
			fall_frame_counter = 0;
		}
		else if ((pad1 & PAD_DOWN) && require_new_down_button == 0)
		{
			// fall every other frame.
			fall_frame_counter = MIN(fall_frame_counter, 1);
		}

		if (fall_frame_counter == 0)
		{
			// If the player forces the opening move, skip any remaining start delay.
			// NOTE: We don't do this for Hard Drops, allowing a sort of "boosted start"
			//		 if the player wants to try a place a few pieces before they start falling.
			start_delay_remaining = 0;

			cur_block.y += 1;
			fall_frame_counter = fall_rate;
		}
	}

	// If the fall_rate is greater than the delay lock, the player has already waited
	// long enough and doesn't need a delay lock.
	if (fall_rate > DELAY_LOCK_LEN)
	{
		delay_lock_skip = 1;
	}

	//debug_display_number(delay_lock_remaining,0);

	hit = 0;

	// Offset from the bottom.
	if (is_cluster_colliding())
	{
		if (delay_lock_remaining == -1)
		{
			delay_lock_remaining = DELAY_LOCK_LEN - fall_rate;
		}
		// TODO: doesn't this mean that the delay lock is only decrementing every time that 
		//		 the block tries to move down, meaning lower g levels will have a longer
		//		 delay lock?
		// No, because when delay_lock_remaing is != -1, it triggers a "down" press (see above).
		--delay_lock_remaining;

		// Clamped to tile space, then multiplied back to pixel space
		//cur_block.y = (cur_block.y >> 3) << 3;

		// Move it above the collided tile.
		cur_block.y -= 1;
		if (delay_lock_remaining == 0 || delay_lock_skip)
		{
			hit = 1;
			delay_lock_remaining = -1;
		}
	}
	else
	{
		delay_lock_remaining = -1;
	}


	if (hit)
	{
		put_cur_cluster();
		// Spawn a new block.
		//spawn_new_cluster();
		delay_spawn_remaining = DELAY_SPAWN_LEN;
	}
//PROFILE_POKE(0x1e); //none
}

void set_block(/*unsigned char x, unsigned char y, unsigned char id*/)
{
	// w = 10 tiles,  80 px
	// h = 20 tiles, 160 px

	// Update the logic array as well as the nametable to reflect it.

	if (in_y <= BOARD_OOB_END)
	{
		// Don't place stuff out of bounds.
		return;
	}

	address = get_ppu_addr(cur_nt, (in_x << 3) + BOARD_START_X_PX, (in_y << 3) + BOARD_START_Y_PX);
	one_vram_buffer(in_id, address);

	// TODO: Is this too slow?
	game_board[TILE_TO_BOARD_INDEX(in_x, in_y)] = in_id;
}

void set_block_nt(unsigned char x, unsigned char y, unsigned char id, unsigned char nt)
{
	if (y <= BOARD_OOB_END)
	{
		// Don't place stuff out of bounds.
		return;
	}

	address = get_ppu_addr(nt, (x << 3) + BOARD_START_X_PX, (y << 3) + BOARD_START_Y_PX);
	one_vram_buffer(id, address);

	game_board[TILE_TO_BOARD_INDEX(x,y)] = id;
}

void clear_block(unsigned char x, unsigned char y)
{
	in_x = x;
	in_y = y;
	in_id = 0;
	set_block();
}

void put_cur_cluster()
{
	static unsigned char i;
	static unsigned char j;

//PROFILE_POKE(0x5f); //green

	max_y = 0;
	min_y = 0xff; // max

	for (i = 0; i < 4; ++i)
	{
		// store the index into the x,y offset for each solid piece in the first rotation.
		j = cur_cluster.layout[i];

		// convert that to x,y offsets.
		local_ix = index_to_x_lookup[j];
		local_iy = index_to_y_lookup[j];

		in_x = cur_block.x + local_ix;
		in_y = cur_block.y + local_iy;
		in_id = cur_cluster.sprite;

		// This is basically always going to be the first thing drawn,
		// but i couldn't think of a clever way to do this once.
		if (in_y < min_y)
		{
			min_y = in_y;
		}
		if (in_y > max_y)
		{
			max_y = in_y;
		}
//PROFILE_POKE(0x3f); //red
		set_block( );
//PROFILE_POKE(0x5f); //green

	}

//PROFILE_POKE(0x9f); //blue
	SFX_PLAY_WRAPPER(SOUND_LAND);

	// Don't end the game when something goes off screen (it should only end when a new piece can't be placed).
	//
	// if (min_y <= BOARD_OOB_END)
	// {
	// 	go_to_state(STATE_OVER);
	// 	return;
	// }
	// else
	{
//PROFILE_POKE(0x3f); //red
		// hide the sprite while we work.
		cur_block.y = 255;

		// We want to hid the sprite that just landed.
		// TODO: Shouldn't this only be if we clear a line?
		oam_set(0);
		//
		oam_spr(0, 0, 0, 0);
		oam_spr(0, 0, 0, 0);
		oam_spr(0, 0, 0, 0);
		oam_spr(0, 0, 0, 0);

//PROFILE_POKE(0x9f); //blue
		if (attack_style == ATTACK_ON_LAND)
		{
			attack_queued = 1;
		}

		// if (min_y <= (BOARD_OOB_END + STRESS_MUSIC_LEVEL) && cur_gameplay_music != MUSIC_STRESS)
		// {
		// 	cur_gameplay_music = MUSIC_STRESS;
		// 	music_play(MUSIC_STRESS);
		// }

		clear_rows_in_data(max_y);

	}
//PROFILE_POKE(0x3f); //green
}

unsigned char is_block_free(unsigned char x, unsigned char y)
{
	if (y > BOARD_END_Y_PX_BOARD || x > BOARD_END_X_PX_BOARD)
	{
		// consider this blocked.
		return 0;
	}

	//return get_block(x, y) == 0;
	return game_board[TILE_TO_BOARD_INDEX(x,y)] == 0;
}

unsigned char is_cluster_colliding()
{
	static unsigned char x;
	static unsigned char y;
	static unsigned char i;
	static unsigned char j;

	for (i = 0; i < 4; ++i)
	{
		// store the index into the x,y offset for each solid piece in the first rotation.
		j = cur_cluster.layout[i];

		// convert that to x,y offsets.
		local_ix = index_to_x_lookup[j];
		local_iy = index_to_y_lookup[j];

		x = cur_block.x + local_ix;
		y = cur_block.y + local_iy;

		if (y > BOARD_END_Y_PX_BOARD || x > BOARD_END_X_PX_BOARD)
		{
			// consider this blocked.
			return 1;
		}

		//return get_block(x, y) == 0;
		if(game_board[TILE_TO_BOARD_INDEX(x,y)]) // != 5 && game_board[TILE_TO_BOARD_INDEX(x,y)] != 0)
		{
			return 1;
		}
	}

	return 0;
}

void spawn_new_cluster()
{
	static unsigned char i;
	static unsigned char j;

	id = 0;

	delay_lock_remaining = -1;

	require_new_down_button = 1;
	fall_frame_counter = fall_rate;

	cur_rot = 0;

	// Copy the next cluster to the current one.
	memcpy(cur_cluster.def, next_cluster.def, 4 * 4);
	memcpy(cur_cluster.layout, cur_cluster.def[0], 4);
	cur_cluster.sprite = next_cluster.sprite;
	cur_cluster.id = next_cluster.id;

	// Reset the block.
	cur_block.x = 3; //(BOARD_END_Y_PX_BOARD >> 1);
	cur_block.y = cluster_offsets[cur_cluster.id];

	// By checking twice we go from 1 in 7 chance of a dupe to
	// 1 in 49 chance.
	id = rand() % NUM_CLUSTERS;
	if (id == cur_cluster.id)
	{
		id = rand() % NUM_CLUSTERS;
	}
	next_cluster.id = id;
	memcpy(next_cluster.def, cluster_defs_classic[id], (4 * 4));
	memcpy(next_cluster.layout, next_cluster.def[0], 4);
	next_cluster.sprite = cluster_sprites[id];

//PROFILE_POKE(0x9f); //blue
	// Put the next block into the nametable.
	local_iy = 0;
	local_ix = 0;
	local_t = next_cluster.sprite;
		
	// clear out the middle 2 rows of the "next piece" (all pieces spawn with only those 2 rows containing visuals).
	multi_vram_buffer_horz(empty_row, 4, get_ppu_addr(cur_nt, 120, 16));
	multi_vram_buffer_horz(empty_row, 4, get_ppu_addr(cur_nt, 120, 24));

	for (i = 0; i < 4; ++i)
	{
		// store the index into the x,y offset for each solid piece in the first rotation.
		j = next_cluster.layout[i];
		
		// convert that to x,y offsets.
		local_ix = index_to_x_lookup[j];
		local_iy = index_to_y_lookup[j];

		one_vram_buffer(local_t, get_ppu_addr(cur_nt, 120 + (local_ix << 3), 8 + (local_iy << 3)));
	}
//PROFILE_POKE(0x1e); //none

	// There is an edge case where a block moves down on the frame it is spawned, while
	// at the top of the board.
	// In such a case the block will be shifted back up to its starting point, which
	// is not out of bounds, and so the game will not trigger game over.
	if (state != STATE_OVER && is_cluster_colliding())
	{
		// trigger game over. First place the new block in nt, then
		// move the the game over state.
		put_cur_cluster();
		go_to_state(STATE_OVER);
	}
}

void rotate_cur_cluster(char dir)
{
	static unsigned char old_rot;

	old_rot = cur_rot;

	cur_rot = (cur_rot + dir) & 3; // % 4

	memcpy(cur_cluster.layout, cur_cluster.def[cur_rot], 4);

	// if after rotating, we are now colliding we something, revert the rotation.
	if (is_cluster_colliding())
	{
		// RIGHT 1
		++cur_block.x;
		if (is_cluster_colliding())
		{
			// LEFT 1
			cur_block.x -= 2;
			if (is_cluster_colliding())
			{
				// Special case for line piece :(
				if (cur_cluster.id == 2)
				{
					// RIGHT 2
					cur_block.x += 3;
					if (is_cluster_colliding())
					{
						// Officially no where to go. Revert back to original position
						// and rotation, and play a whaa-whaa sound.
						cur_block.x -= 2;
						cur_rot = old_rot;
						memcpy(cur_cluster.layout, cur_cluster.def[cur_rot], 4);
						SFX_PLAY_WRAPPER(SOUND_BLOCKED);
						return;
					}
				}
				else
				{
					// Officially no where to go. Revert back to original position
					// and rotation, and play a whaa-whaa sound.
					cur_block.x += 1;
					cur_rot = old_rot;
					memcpy(cur_cluster.layout, cur_cluster.def[cur_rot], 4);
					SFX_PLAY_WRAPPER(SOUND_BLOCKED);
					return;
				}
			}
		}
	}
	SFX_PLAY_WRAPPER(SOUND_ROTATE);
}

void go_to_state(unsigned char new_state)
{
	static unsigned char i;
	static unsigned char fade_delay;
	static unsigned char prev_state;

	fade_delay = 5;
	prev_state = state;

	switch (state)
	{
		case STATE_TY:
		case STATE_SOUND_TEST:
		{
			MUSIC_PLAY_WRAPPER(MUSIC_TITLE);
			break;
		}
		case STATE_OPTIONS:
		{
			pal_bg(palette_bg);
			saved_starting_level = cur_level;
			fall_rate = fall_rates_per_level[MIN(cur_level, sizeof(fall_rates_per_level))];
			row_to_clear = -1;
			start_delay_remaining = START_DELAY;
			display_level();
			display_score();
			break;
		}

		case STATE_PAUSE:
		{
			pal_bright(4);
			break;
		}
		
		case STATE_GAME:
		{
			// Little bit of future proofing in case we add other ways
			// to exit the game (eg. from pause).
			if (cur_score > high_scores[attack_style])
			{
				high_scores[attack_style] = cur_score;
			}
			break;
		}

	default:
		break;
	}

	state = new_state;

	switch (state)
	{
		case STATE_BOOT:
		{
			pal_bg(palette_bg_options);
			ppu_off();
			vram_adr(NTADR_A(0,0));
			vram_unrle(boot_screen);
			ppu_on_all();

			break;
		}
		case STATE_TY:
		{
			pal_bg(palette_bg_options);
			ppu_off();
			vram_adr(NTADR_A(0,0));
			vram_unrle(ty_screen);
			ppu_on_all();

			break;
		}
		case STATE_MENU:
		{
			pal_bg(palette_bg);
			pal_spr(palette_sp);
			scroll_y = 0;
			time_of_day = 0;
			cur_konami_index = 0;

			if (prev_state == STATE_OPTIONS || prev_state == STATE_BOOT || prev_state == STATE_TY|| prev_state == STATE_SOUND_TEST)
			{
				oam_clear();

				ppu_off();
				vram_adr(NTADR_A(0,0));
				vram_unrle(title_screen);
				ppu_on_all();
			}
			else
			{
				if (prev_state == STATE_OVER)
				{
					fade_to_black();
				}

				reset_gameplay_area();

				scroll(0, 0x1df); // shift the bg down 1 pixel
				MUSIC_PLAY_WRAPPER(MUSIC_TITLE);

				if (prev_state == STATE_OVER)
				{
					fade_from_black();
				}
			}

			break;
		}

		case STATE_OPTIONS:
		{
			oam_clear();

			ppu_off();

			pal_bg(palette_bg_options);

			//go_to_state(STATE_SOUND_TEST);
			vram_adr(NTADR_A(0,0));
			vram_unrle(options_screen);

			// vram_adr(NTADR_A(16,19));
			// vram_write(attack_style_strings[attack_style], ATTACK_STRING_LEN);

			// vram_adr(NTADR_A(16,21));
			// vram_write(off_on_string[music_on], OFF_ON_STRING_LEN);

			// handle case where player used cheat to jump 10 levels, and then quit back
			// to the main menu.
			cur_level %= 10;
			cur_option = 0;

			ppu_on_all();

			display_options();
			// too much for 1 frame.
			delay(1);
			clear_vram_buffer();
			display_highscore();

			break;
		}

		case STATE_SOUND_TEST:
		{
			oam_clear();
			ppu_off(); // screen off

			pal_bg(palette_bg_options);
			vram_adr(NTADR_A(0,0));
			vram_unrle(sound_screen);

			ppu_on_all(); // turn on screen

			test_song = test_sound = 0;
			test_song_active = 0xff;

			display_song();
			display_sound();

			break;
		}

		case STATE_GAME:
		{


			// This gets done in the main menu too.
			if (prev_state == STATE_OVER)
			{
				reset_gameplay_area();
			}

			if (prev_state != STATE_PAUSE)
			{
				oam_clear();

				while (scroll_y < 240)
				{
					scroll(0, scroll_y);
					delay(1);
					scroll_y += 4;
				}
				scroll(0, 239);

				// Spawn "next"
				spawn_new_cluster();
				// "Next" becomes current, and a new next is defined.
				spawn_new_cluster();

				memfill(attack_row_status, 0, BOARD_WIDTH);

				// Reseed rng at the start of each match to incrase randomness.
				srand(tick_count_large);

				// where to start the attack!
				i = rand() % BOARD_WIDTH;
				attack_row_status[i] = 1;

				require_new_down_button = 1;
				if (attack_style == ATTACK_ON_TIME)
				{
					attack_queue_ticks_remaining = attack_delay;
				}
			}

			// Do this at the end of the state change so that
			// the up beat music doesn't kick in until after
			// everything transitions in.
			cur_gameplay_music = MUSIC_GAMEPLAY;
			MUSIC_PLAY_WRAPPER(MUSIC_GAMEPLAY);

			break;
		}

		case STATE_PAUSE:
		{
			pal_bright(2);
			MUSIC_PLAY_WRAPPER(MUSIC_PAUSE);
			break;
		}
		case STATE_OVER:
		{
			// fix bug where mashing up/down to quickly hit gamover would case nametable coruption.
			delay(1);
			clear_vram_buffer();

			// Without this, the "next" block won't appear for the first half of the sequence.
			draw_gameplay_sprites();

			music_stop();
			SFX_MUSIC_PLAY_WRAPPER(SOUND_GAMEOVER);

			// Without music this delay feels really odd.
			if (music_on)
			{
				delay(120);
			}

			// treat this like music, since it is a jingle.
			SFX_MUSIC_PLAY_WRAPPER(SOUND_GAMEOVER_SONG);

			// Not sure why this was here. It causes the next block to
			// vanish.
			//oam_clear();

			pal_bright(5);
			delay(fade_delay);
			pal_bright(6);
			delay(fade_delay);
			pal_bright(7);
			delay(fade_delay);
			pal_bright(8);
			delay(fade_delay);

			address = get_ppu_addr(cur_nt, 96, 14<<3);
			multi_vram_buffer_horz( "GAME OVER!", 10, address);
			address = get_ppu_addr(cur_nt, 96, 15<<3);
			multi_vram_buffer_horz("A-RESTART ", 10, address);
			address = get_ppu_addr(cur_nt, 96, 16<<3);
			multi_vram_buffer_horz("B-QUIT    ", 10, address);
			pal_bright(7);
			delay(fade_delay);
			pal_bright(6);
			delay(fade_delay);
			pal_bright(5);
			delay(fade_delay);
			pal_bright(4);
			delay(fade_delay);
			break;
		}

		default:
		{
			break;
		}
	}
}

void inc_lines_cleared()
{
	static unsigned char lines_total;
	++lines_cleared_one;

	if (lines_cleared_one == 10)
	{
		// Basically the level we should be on, by truncating the ones.
		lines_total = (lines_cleared_hundred * 10) + lines_cleared_ten;

		if (cur_level <= lines_total)
		{
			++cur_level;

			// we only handle things up to level 29.
			if (cur_level <= 29 )
			{
				fall_rate = fall_rates_per_level[MIN(cur_level, sizeof(fall_rates_per_level))];
			}
			else if (cur_level < 40) // raise the floor 10 levels.
			{
				if (cur_level == 30)
				{
					one_vram_buffer(SKULL_SPRITE, get_ppu_addr(cur_nt, 4<<3, 9<<3)); // skull
				}
				kill_row_queued = 1;
			}
				
		}

		++time_of_day;
		if (time_of_day >= NUM_TIMES_OF_DAY)
		{
			time_of_day = 0;
		}

		pal_bg(palette_bg_list[time_of_day]);

		// TODO: Use pal_col()
		memcpy(temp_pal, palette_sp, sizeof(palette_sp));
		// blocks
		temp_pal[1] = palette_bg_list[time_of_day][1];
		temp_pal[2] = palette_bg_list[time_of_day][2];
		temp_pal[3] = palette_bg_list[time_of_day][3];
		// kraken
		temp_pal[6] = palette_bg_list[time_of_day][14];
		temp_pal[7] = palette_bg_list[time_of_day][15];
		// flag bg
		temp_pal[10] = palette_bg_list[time_of_day][2];
		//temp_pal[14] = pal_changes[pal_id + 1];
		pal_spr(temp_pal);

		display_level();

		lines_cleared_one = 0;
		++lines_cleared_ten;
		if (lines_cleared_ten == 10)
		{
			lines_cleared_ten = 0;
			++lines_cleared_hundred;
		}
	}
	display_lines_cleared();
}

void display_lines_cleared()
{
	one_vram_buffer('0' + lines_cleared_hundred, get_ppu_addr(cur_nt,4<<3,3<<3));
	one_vram_buffer('0' + lines_cleared_ten, get_ppu_addr(cur_nt,5<<3,3<<3));
	one_vram_buffer('0' + lines_cleared_one, get_ppu_addr(cur_nt,6<<3,3<<3));
}

void display_score()
{
	static unsigned long temp_score;
	static unsigned char i;

	temp_score = cur_score;

	// clear out any old score.
	multi_vram_buffer_horz("      ", 6, get_ppu_addr(cur_nt, 0, 6<<3));

	i = 0;
	while(temp_score != 0)
    {
        unsigned char digit = temp_score % 10;
        one_vram_buffer('0' + digit, get_ppu_addr(cur_nt, (6<<3) - (i << 3), 6<<3 ));

        temp_score = temp_score / 10;
		++i;
    }
}

void display_highscore()
{
	static unsigned long temp_score;
	static unsigned char i;

	temp_score = high_scores[attack_style];

	// clear out any old score.
	multi_vram_buffer_horz("0000000", 7, get_ppu_addr(0, 17<<3, 27<<3));

	i = 0;
	while(temp_score != 0)
    {
        unsigned char digit = temp_score % 10;
        one_vram_buffer('0' + digit, get_ppu_addr(0, (23<<3) - (i << 3), 27<<3 ));

        temp_score = temp_score / 10;
		++i;
    }
}

void display_level()
{
	// We let level be displayed as zero based because it makes more sense when
	// comparing it to lines (eg. lines is 80, level is 8).
	static unsigned char temp_level;
	static unsigned char i;

	temp_level = cur_level;
	i = 0;

	if (cur_level < 10)
	{
		multi_vram_buffer_horz("00", 2, get_ppu_addr(cur_nt,5<<3,9<<3));
	}

	while(temp_level != 0)
    {
        unsigned char digit = temp_level % 10;
        one_vram_buffer('0' + digit, get_ppu_addr(cur_nt, (6<<3) - (i << 3), 9<<3 ));

        temp_level = temp_level / 10;
		++i;
    }
}

// START OF ROW CLEAR SEQUENCE!

void clear_rows_in_data(unsigned char start_y)
{
	static unsigned char line_complete;
	static unsigned char i;
	static unsigned char prev_level;
//PROFILE_POKE(0x9f); //blue
	i = 0;
	prev_level = cur_level;

	// 0xff used to indicate unused.
	memfill(lines_cleared_y, 0xff, 4);
//PROFILE_POKE(0x3f); //red
	// Start at the bottom of the board, and work our way up.
	for (local_iy = start_y; local_iy > BOARD_OOB_END; --local_iy)
	{
		// Assume this row is complete unless we find an empty
		// block.
		line_complete = 1;
		for (local_ix = 0; local_ix <= BOARD_END_X_PX_BOARD; ++local_ix)
		{
//PROFILE_POKE(0x5f); //green
			if (game_board[TILE_TO_BOARD_INDEX(local_ix,local_iy)] == 0 || game_board[TILE_TO_BOARD_INDEX(local_ix,local_iy)] == 1)
			//if (is_block_free(ix, iy))
			{
				// This block is empty, so we can stop checking this row.
				line_complete = 0;
				break;
			}
//PROFILE_POKE(0x3f); //red
		}

		// If this row was filled, we need to remove it and crush
		// the rows above it into its place.
		if (line_complete)
		{
			// for (ix = 0; ix <= BOARD_END_X_PX_BOARD; ++ix)
			// {
			// 	// search for attacks to clear.
			// 	z = get_block(ix, iy);

			// 	if (z == 0xf9 || z == 0xf8 || z == 0xf7)
			// 	{
			// 		attack_row_status[ix] = 0;
			// 	}
			// }

			// early detection for hit, so that we can play hit reaction during clear animation.
			for (local_ix = 0; local_ix < BOARD_WIDTH; ++local_ix)
			{
				if (attack_row_status[local_ix] > ATTACK_QUEUE_SIZE && attack_row_status[local_ix] - (ATTACK_QUEUE_SIZE+1) >= (BOARD_END_Y_PX_BOARD - local_iy))
				{
					hit_reaction_remaining = 60;
					//debug_display_number(hit_reaction_remaining, 1);
				}
			}

			inc_lines_cleared();

			// Fill the row will empty data.
			memcpy(&game_board[TILE_TO_BOARD_INDEX(0, local_iy)], empty_row, 10);

			// Keep track of rows that we cleared so that they can be quickly
			// collapsed later.
			lines_cleared_y[i] = local_iy;

			// Remember that we cleared some lines.
			++i;
		}
	}

	// If any lines we cleared, time to move to the next phase...
	if (i > 0)
	{
		if (prev_level != cur_level)
		{
			SFX_PLAY_WRAPPER(SOUND_LEVELUP);
		}
		else if (i == 4)
		{
			SFX_PLAY_WRAPPER(SOUND_MULTIROW);
		}
		else
		{
			SFX_PLAY_WRAPPER(SOUND_ROW);
		}

		// 40 * (n + 1)	100 * (n + 1) 	300 * (n + 1) 	1200 * (n + 1)
		switch (i)
		{
			case 1:
			{
				line_score_mod = 40;
				break;
			}

			case 2:
			{
				line_score_mod = 100;
				break;
			}

			case 3:
			{
				line_score_mod = 300;
				break;
			}
			
			case 4:
			default:
			{
				line_score_mod = 1200;
				break;
			}
		}
		cur_score += (line_score_mod * (cur_level + 1));
		display_score();

		// potential hit reaction.
		if (hit_reaction_remaining > 0)
		{
			draw_gameplay_sprites();
		}
		reveal_empty_rows_to_nt();
	}
//PROFILE_POKE(0x1e); //none
}

void reveal_empty_rows_to_nt()
{
	//multi_vram_buffer_vert(const char * data, unsigned char len, int ppu_address);

	// Start in the middle of th board, and reveal outwards:
	// 4,5 -> 3,6 -> 2,7 -> 1,8 -> 0,9
	static signed char ix;
	static unsigned char iy;

	// Clear out any existing vram commands to ensure we can safely do a bunch
	// of work in this function.
	delay(1);
	clear_vram_buffer();

	// Reveal from the center out.
	for (ix = 4; ix >= 0; --ix)
	{
		// LEFT SIDE

		// copy a column into an array.
		for (iy = 0; iy < BOARD_HEIGHT; ++iy)
		{
			copy_board_data[iy] = game_board[TILE_TO_BOARD_INDEX(ix, iy + BOARD_OOB_END + 1)];
		}

		multi_vram_buffer_vert(
			copy_board_data,
			BOARD_HEIGHT,
			get_ppu_addr(
				cur_nt,
				BOARD_START_X_PX + (ix << 3),
				BOARD_START_Y_PX + ((BOARD_OOB_END + 1) << 3)));


		// RIGHT SIDE


		for (iy = 0; iy < BOARD_HEIGHT; ++iy)
		{
			copy_board_data[iy] = game_board[TILE_TO_BOARD_INDEX(BOARD_END_X_PX_BOARD - ix, iy + BOARD_OOB_END + 1)];
		}

		multi_vram_buffer_vert(
			copy_board_data,
			BOARD_HEIGHT,
			get_ppu_addr(
				cur_nt,
				BOARD_START_X_PX + ((BOARD_END_X_PX_BOARD - ix) << 3),
				BOARD_START_Y_PX + ((BOARD_OOB_END + 1) << 3)));

		// Reveal these 2 new columns, and then move to the next one.
		delay(5);
		clear_vram_buffer();
	}

	// Move on to the next phase...
	try_collapse_empty_row_data();
}

void try_collapse_empty_row_data(void)
{	
	// cannot use global ix,ix for some reason. Causes Kraken to not
	// retreat when hit.
	static unsigned char ix;
	static unsigned char iy;
	static signed char i;

	// first one is the bottom.
	// TODO: Off by one?
	iy = BOARD_END_Y_PX_BOARD - lines_cleared_y[0];

	//debug_display_number(iy, 0);

	for (ix = 0; ix < BOARD_WIDTH; ++ix)
	{
		if (attack_row_status[ix] > ATTACK_QUEUE_SIZE && attack_row_status[ix] - (ATTACK_QUEUE_SIZE+1) >= (iy))
		{
			while (attack_row_status[ix] > 0)
			{
				//hit_reaction_remaining = 60;
				--attack_row_status[ix];
				delay(1);
				draw_gameplay_sprites();
				clear_vram_buffer();
			}

		}
	}

	// Start at the top of the board, and work our way down.
	for (i = 3; i >= 0; --i)
	{
		// Collapse the game board by copying the top of the board down to above
		// where the line was cleared, to 1 line below the top of the board.

		iy = lines_cleared_y[i];

		if (iy != 0xff)
		{
			// We need to make a copy of game_board, because memcpy can not copy over itself.
			// memmove would be function to use, but it does not exist in this library.
			memcpy(game_board_temp, game_board, sizeof(game_board));
			// index 10 is the start of the 2nd row.
			memcpy(&game_board[10], game_board_temp, iy * 10);
		}
	}


	// TODO NEXT: Chunky update nt.
	copy_board_to_nt();


}

void copy_board_to_nt()
{
	// Clear out any existing vram commands to ensure we can safely do a bunch
	// of work in this function.

	// This also gets called when going back to the main menu.
	if (state == STATE_GAME)
	{
		draw_gameplay_sprites();
	}
	//delay(1);
	//clear_vram_buffer();
	//return;

	for (local_ix = 0; local_ix <= BOARD_END_X_PX_BOARD; ++local_ix)
	{
		// copy a column into an array.
		for (local_iy = 0; local_iy < BOARD_HEIGHT; ++local_iy)
		{
			copy_board_data[local_iy] = game_board[TILE_TO_BOARD_INDEX(local_ix, local_iy + BOARD_OOB_END + 1)];

			// if (iy <= STRESS_MUSIC_LEVEL && copy_board_data[iy] != 0)
			// {
			// 	fast_music = 1;
			// }
		}

		multi_vram_buffer_vert(
			copy_board_data,
			BOARD_HEIGHT,
			get_ppu_addr(
				cur_nt,
				BOARD_START_X_PX + (local_ix << 3),
				BOARD_START_Y_PX + ((BOARD_OOB_END + 1) << 3)));

		// delay often enough to avoid buffer overrun.
		if (local_ix % 3 == 0)
		{
			// calling this again here isn't needed, as time will not have advanced, so
			// drawing the sprites again will do nothing.
			//draw_gameplay_sprites();
//PROFILE_POKE(PROF_CLEAR);
			delay(1);
			clear_vram_buffer();
		}
//PROFILE_POKE(PROF_R);
	}

	// if (fast_music && cur_gameplay_music != MUSIC_STRESS)
	// {
	// 	cur_gameplay_music = MUSIC_STRESS;
	// 	music_play(MUSIC_STRESS);
	// }
	// else if (!fast_music && cur_gameplay_music != MUSIC_GAMEPLAY)
	// {
	// 	cur_gameplay_music = MUSIC_GAMEPLAY;
	// 	music_play(MUSIC_GAMEPLAY);
	// }
}

void add_block_at_bottom()
{
	static signed char ix;
	static unsigned char iy;
	static unsigned char attacks;
	//static unsigned char tentacle_fill[7];

	attacks = 0;

	// Clear out any existing vram commands to ensure we can safely do a bunch
	// of work in this function.
	//delay(1);
	//clear_vram_buffer();

	for (ix = 0; ix < BOARD_WIDTH; ++ix)
	{
		if (attack_row_status[ix] > 0)
		{
			if (attack_row_status[ix] >= ATTACK_MAX)
			{
				// // This attack has maxed out, so remove it from the board (animated).
				// while (attack_row_status[ix] > 0)
				// {
				// 	//hit_reaction_remaining = 60;
				// 	--attack_row_status[ix];
				// 	delay(2);
				// 	draw_gameplay_sprites();
				// 	clear_vram_buffer();
				// }

				row_to_clear = ix;

				// Assuming there is only one attack at a time, we can
				// now exit this loop, and go to the part where it starts
				// the next attack.
				// Note: This assumes that the nametable does not need to
				//		 be updated, since it gets updated as it goes.
				break;
			}
			++attacks;
			++attack_row_status[ix];

			if (attack_row_status[ix] > ATTACK_QUEUE_SIZE)
			{
				for (iy = BOARD_END_Y_PX_BOARD; iy > BOARD_OOB_END; --iy)
				{
					// travel till we hit the first empty spot, which is where we will copy up to.
					if (game_board[TILE_TO_BOARD_INDEX(ix, iy)] == 0)
					{
						// Now work our way back down, copying upwards as we go.
						for (; iy <= BOARD_END_Y_PX_BOARD; ++iy)
						{
							game_board[TILE_TO_BOARD_INDEX(ix, iy)] = game_board[TILE_TO_BOARD_INDEX(ix, iy + 1)];
						}

						break;
					}
				}

				game_board[TILE_TO_BOARD_INDEX(ix, BOARD_END_Y_PX_BOARD)] = garbage_types[cur_garbage_type]; //     0x60; //0xf7; //(attack_row_status[ix] == (ATTACK_QUEUE_SIZE + 1)) ? 0xf9 : 0xf8;
				++cur_garbage_type;
				if (cur_garbage_type >= NUM_GARBAGE_TYPES)
				{
					cur_garbage_type = 0;
				}
				// stay at 1 larger than the queue size to avoid overrun.
				//attack_row_status[ix] = ATTACK_QUEUE_SIZE + 1;
			}
		}
	}

	// TODO: Compare to level expectations.
	if (attacks == 0)
	{
		// where to start the attack!
		attack_row_status[rand() % BOARD_WIDTH] = 1;
	}

	// TODO: Only if changed above.
	copy_board_to_nt();
}



void add_row_at_bottom()
{
	memfill(&game_board[TILE_TO_BOARD_INDEX(0, BOARD_END_Y_PX_BOARD - kill_row_cur)], 1, BOARD_WIDTH);
	++kill_row_cur;
	copy_board_to_nt();
}

void reset_gameplay_area()
{
	memfill(game_board, 0, BOARD_SIZE);

	// Reset stats.
	lines_cleared_one = lines_cleared_ten = lines_cleared_hundred = cur_score = 0;
	cur_level = saved_starting_level;
	fall_rate = fall_rates_per_level[MIN(cur_level, sizeof(fall_rates_per_level))];
	row_to_clear = -1;
	delay_lock_remaining = -1;
	kill_row_cur = 0;
	start_delay_remaining = START_DELAY;

	// load the palettes
	time_of_day = 0;
	pal_bg(palette_bg_list[time_of_day]);
	pal_spr(palette_sp);

	// Clear the skull if needed.
	one_vram_buffer(0x8, get_ppu_addr(2, 4<<3, 9<<3));

	display_lines_cleared();
	display_score();
	display_level();

	oam_clear();

	// clear the "next" block for cases of restarting.
	multi_vram_buffer_horz(empty_row, 4, get_ppu_addr(cur_nt, 120, 16));
	multi_vram_buffer_horz(empty_row, 4, get_ppu_addr(cur_nt, 120, 24));

	// Reset the ppu for gameover case.
	copy_board_to_nt();
}

void display_song()
{
	static unsigned char temp;
	static unsigned char i;

	temp = test_song;
	i = 0;

	if (test_song < 100)
	{
		multi_vram_buffer_horz("000", 3, get_ppu_addr(0,(4<<3),(14<<3)));
	}

	while(temp != 0)
    {
        unsigned char digit = temp % 10;
        one_vram_buffer('0' + digit, get_ppu_addr(0, (6<<3) - (i << 3), (14<<3) ));

        temp = temp / 10;
		++i;
    }
}

void display_sound()
{

	static unsigned char temp;
	static unsigned char i;

	temp = test_sound;
	i = 0;

	if (test_song < 100)
	{
		multi_vram_buffer_horz("000", 3, get_ppu_addr(0,(25<<3),(14<<3)));
	}

	while(temp != 0)
    {
        unsigned char digit = temp % 10;
        one_vram_buffer('0' + digit, get_ppu_addr(0, (27<<3) - (i << 3), (14<<3) ));

        temp = temp / 10;
		++i;
	}
}

void display_options()
{
 	static unsigned char start_y = 16;

	// TODO: Could be smarter and only update the line that changed, and delay
	// 		 could probably be removed.
	// Avoid overrun when mashing mode change.
	delay(1);
	clear_vram_buffer();

	multi_vram_buffer_horz(&starting_levels[cur_level], 1, get_ppu_addr(0,17<<3,start_y<<3));
	multi_vram_buffer_horz(attack_style_strings[attack_style], ATTACK_STRING_LEN, get_ppu_addr(0,17<<3,(start_y+2)<<3));
	multi_vram_buffer_horz(off_on_string[music_on], OFF_ON_STRING_LEN, get_ppu_addr(0,17<<3,(start_y+4)<<3));
	multi_vram_buffer_horz(off_on_string[sfx_on], OFF_ON_STRING_LEN, get_ppu_addr(0,17<<3,(start_y+6)<<3));
	multi_vram_buffer_horz(hard_drop_types[hard_drops_on], HARD_DROP_STRING_LEN, get_ppu_addr(0,17<<3,(start_y+8)<<3));

	// NOTE: One redundant call.
	multi_vram_buffer_horz(option_empty, 2, get_ppu_addr(0, 7<<3, (start_y)<<3));
	multi_vram_buffer_horz(option_empty, 2, get_ppu_addr(0, 7<<3, (start_y+2)<<3));
	multi_vram_buffer_horz(option_empty, 2, get_ppu_addr(0, 7<<3, (start_y+4)<<3));
	multi_vram_buffer_horz(option_empty, 2, get_ppu_addr(0, 7<<3, (start_y+6)<<3));
	multi_vram_buffer_horz(option_empty, 2, get_ppu_addr(0, 7<<3, (start_y+8)<<3));

	multi_vram_buffer_horz(option_icon, 2, get_ppu_addr(0, 7<<3, (start_y + (cur_option<<1)<<3)));
	
	// Avoid overrun when mashing mode change.
	delay(1);
	clear_vram_buffer();
}


void fade_to_black()
{
	pal_bright(3);
	delay(2);
	pal_bright(2);
	delay(2);
	pal_bright(1);
	delay(2);
	pal_bright(0);
	delay(2);
}

void fade_from_black()
{
	pal_bright(1);
	delay(2);
	pal_bright(2);
	delay(2);
	pal_bright(3);
	delay(2);
	pal_bright(4);
	delay(2);
}

// DEBUG
#if DEBUG_ENABLED
void debug_fill_nametables(void)
{
	vram_adr(NTADR_A(0,0));
	vram_fill('a', NAMETABLE_PATTERN_SIZE);
	vram_adr(NTADR_B(0,0));
	vram_fill('b', NAMETABLE_PATTERN_SIZE);
	vram_adr(NTADR_B(0,0));
	vram_fill('c', NAMETABLE_PATTERN_SIZE);
	vram_adr(NTADR_D(0,0));
	vram_fill('d', NAMETABLE_PATTERN_SIZE);
}

void debug_draw_board_area(void)
{
	oam_spr(BOARD_START_X_PX, BOARD_START_Y_PX, 0x01, 0);
	oam_spr(BOARD_END_X_PX, BOARD_START_Y_PX, 0x01, 0);
	oam_spr(BOARD_START_X_PX, BOARD_END_Y_PX, 0x01, 0);
	oam_spr(BOARD_END_X_PX, BOARD_END_Y_PX, 0x01, 0);
}

void debug_copy_board_data_to_nt(void)
{
	//multi_vram_buffer_vert(const char * data, unsigned char len, int ppu_address);

	// Clear out any existing vram commands to ensure we can safely do a bunch
	// of work in this function.

	delay(1);
	clear_vram_buffer();

	for (local_ix = 0; local_ix <= BOARD_END_X_PX_BOARD; ++local_ix)
	{
		// copy a column into an array.
		for (local_iy = 0; local_iy < BOARD_HEIGHT; ++local_iy)
		{
			copy_board_data[local_iy] = '0' + game_board[TILE_TO_BOARD_INDEX(local_ix, local_iy + BOARD_OOB_END + 1)];
		}

		multi_vram_buffer_vert(
			copy_board_data,
			BOARD_HEIGHT,
			get_ppu_addr(
				cur_nt,
				BOARD_START_X_PX + (local_ix << 3),
				BOARD_START_Y_PX + ((BOARD_OOB_END + 1) << 3)));

		// delay often enough to avoid buffer overrun.
		if (local_ix % 4 == 0)
		{
			delay(1);
			clear_vram_buffer();
		}
	}
}

void debug_display_number(unsigned char num, unsigned char index)
{
	// We let level be displayed as zero based because it makes more sense when
	// comparing it to lines (eg. lines is 80, level is 8).
	static unsigned char temp;
	static unsigned char i;

	temp = num;
	i = 0;

	if (temp < 100)
	{
		multi_vram_buffer_horz("000", 3, get_ppu_addr(cur_nt,28<<3,232 - (index << 3)));
	}

	while(temp != 0)
    {
        unsigned char digit = temp % 10;
        one_vram_buffer('0' + digit, get_ppu_addr(cur_nt, (30<<3) - (i << 3), 232 - (index << 3) ));

        temp = temp / 10;
		++i;
    }

	//multi_vram_buffer_horz(arr, 3, get_ppu_addr(cur_nt, 0, 232 - (index << 3)));
	delay(1);
	clear_vram_buffer();
}
#endif //DEBUG_ENABLED