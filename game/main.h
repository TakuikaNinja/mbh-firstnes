/** (C) Matt Hughson 2020 */

#define DEBUG_ENABLED 0
#define HOLD_PIECE_ENABLED 1

#if DEBUG_ENABLED
#define PROFILE_POKE(val) POKE((0x2001), (val));
#else
#define PROFILE_POKE(val)
#endif

#define PROF_CLEAR 0x1e // none
#define PROF_R 0x3f     // red
#define PROF_G 0x5f     // green
#define PROF_B 0x9f     // blue
#define PROF_W 0x1f     // white

// Nametable A: 	2400-2000 = 400
// Attributes: 		2400-23c0 = 0x40
// Patterns: 		0x400-0x40 = 0x3c0
#define NAMETABLE_SIZE 0x400
#define NAMETABLE_PATTERN_SIZE 0x3c0

#define BOARD_START_X_PX 96
#define BOARD_START_Y_PX 16
#define BOARD_END_X_PX 168
#define BOARD_END_Y_PX (184 + 16)

#define BOARD_OOB_END 3
#define BOARD_END_X_PX_BOARD 9  // left edge of last block (width = 10)
#define BOARD_END_Y_PX_BOARD 23 // top edge of last block (height = 24)

#define BOARD_SIZE 240 //
#define BOARD_HEIGHT (BOARD_END_Y_PX_BOARD - BOARD_OOB_END)
#define BOARD_WIDTH (BOARD_END_X_PX_BOARD + 1)

#define TILE_TO_BOARD_INDEX(x, y) ((board_lookup_y[(y)]) + (x))

#define BLINK_LEN (60 * 5)

#define SFX_PLAY_WRAPPER(id) \
    if (sfx_on)              \
    {                        \
        sfx_play((id), 0);   \
    }
// play a sound effect that is treated like music to the user (jingles, etc).
#define SFX_MUSIC_PLAY_WRAPPER(id) \
    if (music_on)                  \
    {                              \
        sfx_play((id), 0);         \
    }
#define MUSIC_PLAY_WRAPPER(id) \
    if (music_on)              \
    {                          \
        music_play((id));      \
    }
#if VS_SYS_ENABLED
#define MUSIC_PLAY_ATTRACT_WRAPPER(id)                             \
    if (music_on && (DIP8 == 0 || credits_remaining >= game_cost)) \
    {                                                              \
        music_play((id));                                          \
    }
#else
// No attract mode.
#define MUSIC_PLAY_ATTRACT_WRAPPER(id) MUSIC_PLAY_WRAPPER(id)
#endif // VS_SYS_ENABLED
#define SKULL_SPRITE 0x3b

// The time before another code will be accepted.
#define CREDIT_DELAY 70

#if VS_SYS_ENABLED
// Note: 1 based to match documentation and user face numbering.
#define DIP1 (PEEK(0x4016) & 1 << 3) // FREE PLAY
#define DIP2 (PEEK(0x4016) & 1 << 4) // EXTRA COIN COST

#define DIP3 (PEEK(0x4017) & 1 << 2) // PPU.0
#define DIP4 (PEEK(0x4017) & 1 << 3) // PPU.1
#define DIP5 (PEEK(0x4017) & 1 << 4) // PPU.2

#define DIP6 (PEEK(0x4017) & 1 << 5) // MUSIC OFF
#define DIP7 (PEEK(0x4017) & 1 << 6) // SFX OFF
#define DIP8 (PEEK(0x4017) & 1 << 7) // MUTE MAIN MENU
#endif                               // VS_SYS_ENABLED

// Delay in the settings screens before the player options are auto-chosen for them.
#define AUTO_FORWARD_DELAY (60 * 30)
#define HIGH_SCORE_ENTRY 4
#define NO_SCORE (0xffffffff)

#if VS_SRAM_ENABLED
#define IS_PRIMARY_CPU ((PEEK(0x4016) & (1 << 7)) == 0)
#else
#define IS_PRIMARY_CPU (1)
#endif // #if VS_SRAM_ENABLED

enum
{
    ATTACK_ON_LAND,
    ATTACK_ON_TIME,
    ATTACK_NEVER,
    ATTACK_NUM
};

#if VS_SRAM_ENABLED
#pragma bss-name(push, "XRAM")
unsigned char xram_test[8];
#if VS_SYS_ENABLED
unsigned char high_scores_vs_initials[ATTACK_NUM][4][3][3];
unsigned long high_scores_vs_value[ATTACK_NUM][4][3];
#endif //#if VS_SYS_ENABLED
#pragma bss-name(pop)
#endif // #if VS_SRAM_ENABLED

#pragma bss-name(push, "ZEROPAGE")

// GLOBAL VARIABLES

struct block
{
    unsigned char x;
    unsigned char y;
};

struct cluster
{

    // The current layout. 1 entry from "def".
    unsigned char layout[4];
    // The 4 rotations defining this block.
    // Each entry in the array is an index into index_to_x/y_lookup.
    // That look up contains x/y offsets from the position of this block.
    const unsigned char def[4][4];
    unsigned char sprite;
    unsigned char id;
};

unsigned char tick_count;
unsigned int tick_count_large;
unsigned int ticks_in_state_large;
unsigned char hit_reaction_remaining;
unsigned int attack_queue_ticks_remaining;
const unsigned int attack_delay = 600;
unsigned char pad_all;
unsigned char pad_all_new;
unsigned char pad1;
unsigned char pad1_new;
unsigned char pad2;
unsigned char pad2_new;
unsigned int scroll_y;

#define NUM_OPTIONS 5
unsigned char cur_option;

//const unsigned char text[] = "- PRESS START -";
unsigned char attack_style;
#define ATTACK_STRING_LEN 7

#if VS_SYS_ENABLED
// unsigned char high_scores_vs_initials[ATTACK_NUM][4][3][3] =
// {
//     // ATTACK_ON_LAND/FIXED
//     {
//         { "1FE", "2FE", "3FE" }, // EASY
//         { "1FM", "2FM", "3FM" }, // MED
//         { "1FI", "2FI", "3FI" }, // INSANE
//         { "1FD", "2FD", "3FD" }, // DEATH
//     },
//     // ATTACK_ON_TIME/TIMED
//     {
//         { "1TE", "2TE", "3TE" }, // EASY
//         { "1TM", "2TM", "3TM" }, // MED
//         { "1TI", "2TI", "3TI" }, // INSANE
//         { "1TD", "2TD", "3TD" }, // DEATH
//     },
//     // ATTACK_NEVER/CLASSIC
//     {
//         { "1CE", "2CE", "3CE" }, // EASY
//         { "1CM", "2CM", "3CM" }, // MED
//         { "1CI", "2CI", "3CI" }, // INSANE
//         { "1CD", "2CD", "3CD" }, // DEATH
//     },
// };

// Temporary table used for manipulating high score table.
unsigned char *temp_table;
unsigned char last_initials[3] = "AAA";

#if !VS_SRAM_ENABLED
unsigned char high_scores_vs_initials[ATTACK_NUM][4][3][3] =
    {
        // ATTACK_ON_LAND/FIXED
        {
            {"---", "---", "---"}, // EASY
            {"---", "---", "---"}, // MED
            {"---", "---", "---"}, // INSANE
            {"---", "---", "---"}, // DEATH
        },
        // ATTACK_ON_TIME/TIMED
        {
            {"---", "---", "---"}, // EASY
            {"---", "---", "---"}, // MED
            {"---", "---", "---"}, // INSANE
            {"---", "---", "---"}, // DEATH
        },
        // ATTACK_NEVER/CLASSIC
        {
            {"---", "---", "---"}, // EASY
            {"---", "---", "---"}, // MED
            {"---", "---", "---"}, // INSANE
            {"---", "---", "---"}, // DEATH
        },
};

// unsigned long high_scores_vs_value[ATTACK_NUM][4][3] =
// {
//     // ATTACK_ON_LAND/FIXED
//     {
//         { 1234567, 12345, 12 }, // Easy
//         { 1234567, 12345, 12 }, // Med
//         { 1234567, 12345, 12 }, // Insane
//         { 1234567, 12345, 12 }, // Death
//     },
//     {
//         { 1234567, 12345, 12 }, // Easy
//         { 1234567, 12345, 12 }, // Med
//         { 1234567, 12345, 12 }, // Insane
//         { 1234567, 12345, 12 }, // Death
//     },
//     {
//         { 1234567, 12345, 12 }, // Easy
//         { 1234567, 12345, 12 }, // Med
//         { 1234567, 12345, 12 }, // Insane
//         { 1234567, 12345, 12 }, // Death
//     },
// };

unsigned long high_scores_vs_value[ATTACK_NUM][4][3] =
    {
        // ATTACK_ON_LAND/FIXED
        {
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Easy
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Med
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Insane
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Death
        },
        // ATTACK_ON_TIME/TIMED
        {
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Easy
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Med
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Insane
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Death
        },
        // ATTACK_NEVER/CLASSIC
        {
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Easy
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Med
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Insane
            {NO_SCORE, NO_SCORE, NO_SCORE}, // Death
        },
};
#endif // #if !VS_SRAM_ENABLED
unsigned char cur_initial_index;
#endif

unsigned long high_scores[ATTACK_NUM] = {0, 0, 0}; // NOTE: long!

unsigned char music_on;
unsigned char sfx_on;
#define OFF_ON_STRING_LEN 4

enum
{
    BLOCK_STYLE_MODERN,
    BLOCK_STYLE_CLASSIC
};
unsigned char block_style;
#define BLOCK_STYLE_STRING_LEN 7

const unsigned char starting_levels[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
unsigned char saved_starting_level;

unsigned char hard_drops_on;
unsigned char hard_drop_hold_remaining;
unsigned char hard_drop_tap_required;

enum
{
    STATE_BOOT,
    STATE_TY,
    STATE_MENU,
    STATE_OPTIONS,
    STATE_GAME,
    STATE_PAUSE,
    STATE_OVER,
    STATE_SOUND_TEST,
    STATE_HIGH_SCORE_TABLE
};
unsigned char state = STATE_BOOT;

#define KONAMI_CODE_LEN 11
const unsigned char konami_code[KONAMI_CODE_LEN] = {PAD_UP, PAD_UP, PAD_DOWN, PAD_DOWN, PAD_LEFT, PAD_RIGHT, PAD_LEFT, PAD_RIGHT, PAD_B, PAD_A, PAD_START};
unsigned char cur_konami_index;

// The block operates in "logical space" from 0 -> w/h. The logical
// space is converted to screen space at time of render (or ppu get).
struct block cur_block = {0, 0};

// How many frames need to pass before it falls 8 pixels.
unsigned char fall_rate = 48;
unsigned char cur_level = 0;
// When changing starting level, we actually change this linear number which then
// gets mapped to starting numbers.
#if VS_SYS_ENABLED
unsigned char cur_level_vs_setting = 0;
unsigned char high_score_entry_placement;
#define VS_CODE_LEN 7
const unsigned char vs_code[VS_CODE_LEN] = {PAD_RIGHT, PAD_RIGHT, PAD_RIGHT, PAD_DOWN, PAD_DOWN, PAD_DOWN, PAD_RIGHT};
unsigned char vs_code_index;
#endif // #if VS_SYS_ENABLED
// Each entry in the array is a rotation.
// Stored as 4x4 16 bit matrix to support line (otherwise 3x3 would do it).
// TODO: Perhaps a special character could be user to terminate the array
//       prior to the end.
/*
    1 1 0 0
    0 1 1 0
    0 0 0 0
    0 0 0 0

    0 0 1 0
    0 1 1 0
    0 1 0 0
    0 0 0 0
*/

// SRS ROTATION

// TODO: offset in pixels as well?

//const unsigned char index_to_x_lookup[16] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
//const unsigned char index_to_y_lookup[16] = {0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3};

const unsigned char def_line[4][4] =
    {
        {2, 3, 6, 7},
        {4, 6, 12, 14},
        {8, 9, 12, 13},
        {1, 3, 9, 11},

};

const unsigned char def_square[4][4] =
    {
        {3, 6, 9, 12},
        {3, 6, 9, 12},
        {3, 6, 9, 12},
        {3, 6, 9, 12},
};

const unsigned char def_L_rev[4][4] =
    {
        {0, 2, 3, 6},
        {1, 4, 3, 9},
        {2, 3, 6, 12},
        {1, 3, 8, 9},

};

const unsigned char def_L[4][4] =
    {
        {4, 2, 3, 6},
        {1, 3, 9, 12},
        {2, 3, 6, 8},
        {0, 1, 3, 9},

};

const unsigned char def_S[4][4] =
    {
        {1, 4, 2, 3},
        {1, 3, 6, 12},
        {3, 6, 8, 9},
        {0, 2, 3, 9},

};

const unsigned char def_Z[4][4] =
    {
        {0, 1, 3, 6},
        {4, 3, 6, 9},
        {2, 3, 9, 12},
        {1, 2, 3, 8},

};

const unsigned char def_T[4][4] =
    {
        {1, 2, 3, 6},
        {6, 1, 3, 9},
        {9, 6, 3, 2},
        {2, 9, 3, 1},

};

#define NUM_CLUSTERS 7

const unsigned char **cluster_defs_classic[NUM_CLUSTERS] =
    {
        def_Z,
        def_S,
        def_line, // if move update places that check for line via id.
        def_square,
        def_T,
        def_L,
        def_L_rev,
};

#if !VS_SYS_ENABLED

unsigned char bag[NUM_CLUSTERS] = {0,1,2,3,4,5,6};
unsigned char bag_index = 0;
void randomize_bag ( unsigned char arr[], unsigned char n ); 
void swap (unsigned char *a, unsigned char *b);

#endif

unsigned char cur_rot;

//SRS offset +3 and is morton encoded. As SRS Offset rotations are -3 minimum, and encoding is unsigned
//8 cases with 5 tests (1st test is not included since it accounts for no offset [No wall kick required], last test is to revert change)
//So for each case iterate over 5
#define SRS_TESTS 5
const unsigned char srs_rotate_lookup[8][SRS_TESTS] =
    {
        {14, 13, 56, 14, 18}, //0 Non Line
        {26, 37, 4, 26, 38},  //1 Non Line
        {26, 13, 44, 26, 6},  //2 Non Line
        {14, 37, 16, 14, 50}, //3 Non Line
        {11, 30, 32, 20, 38}, //4 Line
        {27, 10, 28, 40, 18}, //5 Line
        {14, 30, 2, 60, 9},   //6 Line
        {26, 10, 54, 0, 49}   //7 Line
};

struct cluster cur_cluster; // = { def_z_clust }; // 165 1010 0101
struct cluster next_cluster;

#if HOLD_PIECE_ENABLED

unsigned char held_cluster_id; 
unsigned char held_cluster_def[4][4];
unsigned char staging_cluster_id; //Need staging cluster to temp store held cluster when swapping with current cluster
unsigned char can_hold_cluster; //Cannot hold repeatly - only until next cluster is loaded
void hold_cluster();

#endif

#define ATTACK_QUEUE_SIZE 3
#define ATTACK_MAX 10

unsigned char attack_row_status[BOARD_WIDTH];

const unsigned char cluster_sprites[NUM_CLUSTERS] =
    {
        0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6};

const unsigned char cluster_offsets[NUM_CLUSTERS] =
    {
        4, 4, 3, 3, 4, 4, 4,
        //3, 3, 2, 3, 3, 3, 3,
        //10,10,10,10,10,10,10
};

unsigned char horz_button_delay;
const unsigned char button_delay = 5;
unsigned char require_new_down_button;
unsigned char fall_frame_counter;
unsigned char lines_cleared_one;
unsigned char lines_cleared_ten;
unsigned char lines_cleared_hundred;
unsigned long cur_score; // NOTE: long!
unsigned char cur_nt;
unsigned char off_nt;

// movement()
char hit;
unsigned char temp_fall_frame_counter;
unsigned char old_x;
// spawn_new_cluster()
unsigned char id;
// put_cur_cluster()
unsigned char min_y;
unsigned char max_y;
// set_block()
unsigned char in_x;
unsigned char in_y;
unsigned char in_id;
// draw_gameplay_sprites()
unsigned char local_start_x;
unsigned char local_start_y;
unsigned char local_ix;
unsigned char local_iy;
unsigned int local_t;
unsigned char local_bit;
unsigned char local_row_status;
const unsigned char OOB_TOP = (BOARD_START_Y_PX + (BOARD_OOB_END << 3));

unsigned char test_song;
unsigned char test_song_active;
unsigned char test_sound;

enum
{
    MUSIC_TITLE,
    MUSIC_GAMEPLAY,
    MUSIC_STRESS,
    MUSIC_PAUSE
};
enum
{
    SOUND_ROTATE,
    SOUND_LAND,
    SOUND_ROW,
    SOUND_MULTIROW,
    SOUND_GAMEOVER,
    SOUND_START,
    SOUND_BLOCKED,
    SOUND_LEVELUP,
    SOUND_LEVELUP_MULTI,
    SOUND_PAUSE,
    SOUND_MENU_HIGH,
    SOUND_MENU_LOW,
    SOUND_GAMEOVER_SONG
};

unsigned char cur_gameplay_music;
#define STRESS_MUSIC_LEVEL 7 // 5 blocks down from the out of bounds area
unsigned char attack_queued;

const char tentacle_offsets[4] = {-1, 0, 1, 0};

#define NUM_GARBAGE_TYPES 3
const unsigned char garbage_types[NUM_GARBAGE_TYPES] = {0x60, 0x70, 0x2f};
unsigned char cur_garbage_type;

#define DELAY_LOCK_LEN 15
signed char delay_lock_remaining;
unsigned char delay_lock_skip;

// The amount of time before another block is spawned after the previous one lands.
#define DELAY_SPAWN_LEN 5
signed char delay_spawn_remaining;
unsigned char spawn_queued;

#define HARD_DROP_HOLD_TIME 2

signed char row_to_clear;

unsigned char kill_row_cur;
unsigned char kill_row_queued;

#define START_DELAY 120
unsigned char start_delay_remaining;

const unsigned char board_lookup_y[24] =
    {
        0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230};

unsigned int mask;
int address;
unsigned char time_of_day;
unsigned char temp_pal[16];
char lines_cleared_y[4];
unsigned int line_score_mod;

#pragma bss-name(push, "BSS")

// Defined in crt0.s
extern unsigned char CREDITS_QUEUED;
extern unsigned char PPU_VERSION;

unsigned char game_board[BOARD_SIZE];
unsigned char game_board_temp[BOARD_SIZE];
const char empty_row[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const char full_row[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const unsigned char full_col[20] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
const unsigned char option_empty[] = {0x0, 0x0};
const unsigned char option_icon[] = {0x25, 0x26};

// copy_board_to_nt()
char copy_board_data[BOARD_HEIGHT];

// 2C03
// 333,014,006,326,403,    503,510,420,320,120,    031,040,022,000,000,    000
// 555,036,027,407,507,    704,700,630,430,140,    040,053,044,000,000,    000
// 777,357,447,637,707,    737,740,750,660,360,    070,276,077,000,000,    000
// 777,567,657,757,747,    755,764,772,773,572,    473,276,467,000,000,    000

// 755,637,700,447,044,    120,222,704,777,333,    750,503,403,660,320,     777
// 357,653,310,360,467,    657,764,027,760,276,    000,200,666,444,707,     014
// 003,567,757,070,077,    022,053,507,000,420,    747,510,407,006,740,     000
// 000,140,555,031,572,    326,770,630,020,036,    040,111,773,737,430,     473

// first "16" entry is remapping of 772 to 764.
// unsigned char ppu_RP2C04_0001_mapping[] =
// {
// $09,$1f,$2d,$35,$0c, $0b,$2b,$29,$0e,$05, $33,$3a,$25,$30,$30, $30,
// $32,$39,$17,$2c,$27, $07,$02,$37,$3e,$31, $3a,$26,$04,$30,$30, $30,
// $0f,$10,$03,$01,$0e, $3d,$2e,$0a,$0d,$13, $23,$19,$24,$30,$30, $30,
// $0f,$21,$15,$22,$2a, $00,$36,$16,$3c,$34, $3f,$19,$14,$30,$30, $30
// };

// // 0001
// unsigned char ppu_RP2C04_0001[] =
// {
// 0x35,0x23,0x16,0x22,0x1c,0x09,0x2d,0x15,0x30,0x00,0x27,0x05,0x04,0x28,0x08,0x30,
// 0x21,0x18,0x06,0x29,0x3c,0x32,0x36,0x12,0x18,0x3b,0x0d,0x06,0x10,0x00,0x24,0x01,
// 0x01,0x31,0x33,0x2a,0x2c,0x0c,0x1b,0x14,0x0d,0x07,0x34,0x06,0x13,0x02,0x26,0x0d,
// 0x0d,0x19,0x10,0x0a,0x39,0x03,0x28,0x17,0x09,0x11,0x0b,0x10,0x38,0x25,0x18,0x3a,
// };

// const unsigned char palette_bg_[16] =
// {
//     0x30,   //     0x0f,
//     0x03,   //     0x22,
//     0x21,   //     0x31,
//     0x08,   //     0x30,

//     0x30,   //     0x0f,
//     0x09,   //     0x00,
//     0x37,   //     0x17,
//     0x0d,   //     0x28,

//     0x30,   //     0x0f,
//     0x23,   //     0x2a,
//     0x02,   //     0x16,
//     0x3c,   //     0x37,

//     0x30,   //     0x0f,
//     0x03,   //     0x22,
//     0x2e,   //     0x26, // 0x00 - Should be 2e, but appears to be blue, so picked something close.
//     0x3c    //     0x37
// };

const unsigned char palette_bg[16] = {0x0f, 0x22, 0x31, 0x30, 0x0f, 0x00, 0x17, 0x28, 0x0f, 0x2a, 0x16, 0x36, 0x0f, 0x22, 0x26, 0x36};
const unsigned char palette_sp[16] = {0x0f, 0x22, 0x31, 0x30, 0x0f, 0x0f, 0x26, 0x36, 0x0f, 0x16, 0x31, 0x36, 0x0f, 0x0f, 0x26, 0x36};
const unsigned char palette_bg_options[16] = {0x0f, 0x22, 0x31, 0x30, 0x0f, 0x30, 0x0f, 0x26, 0x0f, 0x22, 0x0f, 0x26, 0x0f, 0x22, 0x26, 0x36};

#if VS_SYS_ENABLED
//const unsigned char palette_vs_options[16]={ 0x0f,0x00,0x10,0x30,0x0f,0x00,0x10,0x30,0x0f,0x00,0x10,0x20,0x0f,0x22,0x32,0x30 };
const unsigned char palette_vs_options[16] = {0x0f, 0x00, 0x10, 0x30, 0x0f, 0x00, 0x10, 0x30, 0x0f, 0x00, 0x10, 0x20, 0x0f, 0x22, 0x31, 0x30};
const unsigned char palette_vs_highscore_table[16] = {0x0f, 0x22, 0x31, 0x30, 0x0f, 0x30, 0x0f, 0x26, 0x0f, 0x22, 0x0f, 0x26, 0x0f, 0x06, 0x0f, 0x30};

const unsigned char palette_vs_options_inactive[] = {0x0f, 0x00, 0x10, 0x30};
const unsigned char palette_vs_options_active[] = {0x0f, 0x22, 0x26, 0x36};
const unsigned char palette_vs_options_skulls[16] = {
    0x0f,
    0x06,
    0x16,
    0x36,
    0x0f,
    0x06,
    0x16,
    0x36,
    0x0f,
    0x06,
    0x16,
    0x36,
    0x0f,
    0x06,
    0x16,
    0x36,
};
#endif

// const unsigned char pal_changes[20] =
// {
//     0x01, 0x21, // blues
//     0x13, 0x23, // purples
//     0x1c, 0x26, // dark blue + oj
//     0x0b, 0x1b, // dark green, soft green
//     0x06, 0x15, // reds
//     0x2c, 0x39, // limey blue
//     0x03, 0x35, // purples
//     0x16, 0x26, // oranges
//     0x11, 0x2b, // light green, blue
//     0x0f, 0x15, // bright reds
// };

#define NUM_TIMES_OF_DAY 8
const unsigned char palette_bg_list[NUM_TIMES_OF_DAY][16] =
    {
        {0x0f, 0x22, 0x31, 0x30, 0x0f, 0x00, 0x17, 0x28, 0x0f, 0x2a, 0x16, 0x36, 0x0f, 0x22, 0x26, 0x36},
        {0x0f, 0x22, 0x36, 0x30, 0x0f, 0x00, 0x17, 0x27, 0x0f, 0x2a, 0x16, 0x38, 0x0f, 0x22, 0x26, 0x36},
        {0x0f, 0x1c, 0x36, 0x30, 0x0f, 0x00, 0x17, 0x27, 0x0f, 0x1a, 0x16, 0x38, 0x0f, 0x1c, 0x26, 0x36},
        {0x0f, 0x0c, 0x23, 0x34, 0x0f, 0x00, 0x07, 0x10, 0x0f, 0x1a, 0x17, 0x27, 0x0f, 0x0c, 0x16, 0x27},
        {0x0f, 0x0c, 0x1c, 0x10, 0x0f, 0x00, 0x07, 0x22, 0x0f, 0x1b, 0x07, 0x17, 0x0f, 0x0c, 0x11, 0x22},
        {0x0f, 0x0c, 0x22, 0x27, 0x0f, 0x00, 0x18, 0x27, 0x0f, 0x1a, 0x17, 0x27, 0x0f, 0x0c, 0x22, 0x36},
        {0x0f, 0x1c, 0x36, 0x30, 0x0f, 0x00, 0x18, 0x26, 0x0f, 0x2a, 0x16, 0x38, 0x0f, 0x1c, 0x26, 0x36},
        {0x0f, 0x23, 0x32, 0x30, 0x0f, 0x00, 0x17, 0x28, 0x0f, 0x2a, 0x16, 0x36, 0x0f, 0x23, 0x26, 0x36},
};

/*
Level	Frames per Gridcell
00	        48
01	        43
02	        38
03	        33
04	        28
05	        23
06	        18
07	        13
08	        8
09	        6
10–12	    5
13–15	    4
16–18	    3
19–28	    2
29+	        1
*/

// https://tetris.fandom.com/wiki/Tetris_(NES,_Nintendo)
const unsigned char fall_rates_per_level[] =
    {
        48,
        43,
        38,
        33,
        28,
        23,
        18,
        13,
        8,
        6,
        5, // 10-12
        5, // 10-12
        5, // 10-12
        4, // 13-15
        4, // 13-15
        4, // 13-15
        3, // 16–18
        3, // 16–18
        3, // 16–18
        2, // 19–28
        2, // 19–28
        2, // 19–28
        2, // 19–28
        2, // 19–28
        2, // 19–28
        2, // 19–28
        2, // 19–28
        2, // 19–28
        2, // 19–28
        1, // 29+
};

const unsigned char attack_style_strings[3][ATTACK_STRING_LEN] =
    {
        "FIXED",
        "TIMED",
        "CLASSIC"};
const unsigned char off_on_string[2][OFF_ON_STRING_LEN] =
    {
        "OFF",
        "ON"};
const unsigned char block_style_strings[2][BLOCK_STYLE_STRING_LEN] =
    {
        "MODERN",
        "CLASSIC"};

#define NUM_HARD_DROP_SETTINGS 3
#define HARD_DROP_STRING_LEN 4
const unsigned char hard_drop_types[NUM_HARD_DROP_SETTINGS][HARD_DROP_STRING_LEN] = {"OFF", "TAP", "HOLD"};

#if VS_SYS_ENABLED
unsigned char auto_forward_leaderboards;
unsigned char free_play_enabled;
unsigned char game_cost;
unsigned char option_state;
// Store the value at $4016 from previous frame, so that
// it can be compared for release events.
unsigned char prev_4016;
// Counter used to turn on the hardware coin counter for 3 frames
// then off for at least 3 frames.
unsigned char maintenance_counter;
#endif //VS_SYS_ENABLED

// Screen shake is now supported across the game.
unsigned char screen_shake_remaining;

#if VS_SYS_ENABLED
const unsigned char text_insert_1_coin[] = {"\xDB  INSERT COIN  \xDC"}; // { "PUSH START" };
const unsigned char text_insert_2_coin[] = {"\xDB INSERT  COINS \xDC"}; // { "PUSH START" };
const unsigned char text_free_play[] = {"\xdb  FREE   PLAY  \xDC"};     // { "PUSH START" };
const unsigned char text_push_start[] = {"\xDBPUSH ANY BUTTON\xDC"};    // { "PUSH START" };
const unsigned char clear_push_start[] = {"\xDB               \xDC"};   //{ "          " };
#else
const unsigned char text_push_start[] = {"PUSH START"};
const unsigned char clear_push_start[] = {"          "};
#endif //VS_SYS_ENABLED

#if VS_SYS_ENABLED
unsigned char credits_remaining;

const unsigned char metasprite_vs_logo[] = {
    0, 0, 0x0a, 3,
    8, 0, 0x0b, 3,
    16, 0, 0x0c, 3,
    24, 0, 0x0d, 3,
    0, 8, 0x1a, 3,
    8, 8, 0x1b, 3,
    16, 8, 0x1c, 3,
    24, 8, 0x1d, 3,
    128};

// const unsigned char metasprite_button2[]={
// 	  0,  0,0xab,3,
// 	  8,  0,0xac,3,
// 	  0,  8,0xbb,3,
// 	  8,  8,0xbc,3,
// 	128
// };

unsigned char attract_gameplay_enabled = 0;

#endif // VS_SYS_ENABLED

const unsigned char metasprite_tentacle_title[]={
	  0,  0,0x60,1,
	  8,  0,0x61,1,
	  0,  8,0x70,1,
	  8,  8,0x71,1,
	  0, 16,0x80,1,
	  8, 16,0x81,1,
	  0, 24,0x90,1,
	  8, 24,0x91,1,
	128
};

// PROTOTYPES
void draw_menu_sprites(void);
void draw_gameplay_sprites(void);
void movement(void);

// Set a block in x, y (board space)
void set_block(/*unsigned char x, unsigned char y, unsigned char id*/);
void set_block_nt(unsigned char x, unsigned char y, unsigned char id, unsigned char nt);
// x, y in board space.
//void clear_block(unsigned char x, unsigned char y);

// Drops the current cluster at its current location.
void put_cur_cluster();

// x, y in map space.
unsigned char get_block(unsigned char x, unsigned char y);

// x, y in map space.
unsigned char is_block_occupied(unsigned char x, unsigned char y);

// Checks if the entire cluster is currently hitting any other blocks.
unsigned char is_cluster_colliding();

// Morton grab parameter
unsigned char morton_compact_one_by_one(unsigned char x);

// Creates a new cluster at the top of the play area.
void spawn_new_cluster();

// Hold a cluster
//void hold_cluster()

// Rotate the current cluster by 90degs.
void rotate_cur_cluster(char dir);

// Do the rotate
unsigned char rotate_srs(unsigned char case_id);

//Check if position counts as tspin
unsigned char check_tspin();
unsigned char is_tspin;
unsigned char is_last_rotate;

// Transition to a new state.
void go_to_state(unsigned char new_state);

void inc_lines_cleared();
void display_lines_cleared();
void display_score();
void display_highscore();
void display_level();

// CLEAR PHASES

// First clear all the rows in CPU memory.
void clear_rows_in_data(unsigned char start_y);

// Then show the empty rows, 2 columns at a time...
void reveal_empty_rows_to_nt();

// Then collapse the empty rows in CPU memory...
void try_collapse_empty_row_data(void);

// Finally reveal to resolved board with all blocks in final position.
void copy_board_to_nt();

void add_block_at_bottom();
void add_row_at_bottom();

void reset_gameplay_area();

void display_song();
void display_sound();
void display_options();

void fade_to_black();
void fade_from_black();

void difficulty_to_leaderboard_pos(unsigned char dif);

// DEBUG
#if DEBUG_ENABLED
void debug_fill_nametables(void);
void debug_draw_board_area(void);
void debug_copy_board_data_to_nt(void);
void debug_display_number(unsigned char num, unsigned char index);
#endif