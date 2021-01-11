# FROM BELOW

A brand new game for the Nintendo Entertainment System!

Details on the game, along with downloads (for the original game) of compiled ROM can be found here: https://mhughson.itch.io/from-below

For the NES version containing the changes below, see [main.nes](game/main.nes)

Differences from the original:
1. The use of SRS rotation system (https://tetris.fandom.com/wiki/SRS) instead of Nintendo Rotation System - Right Handed version (https://harddrop.com/wiki/Nintendo_Rotation_System) used in Tetris (NES) with the added Wall Kick. So you are now able to do T-Spins with Twists.
2. T-Spin score is calculated
- No line: 40 points (same as 1 line)
- 1, 2, and 3 Lines: 5x score
3. T-Spin triple plays Tetris sound with the shake 
4. Soft Drop adds 1 per line to score, and Hard Drop add 2 points per line to score.
5. Combo score is calculated, 20 x combo count * level
6. Back to Back Tetris is calculated - Tetris Score x 1.5
7. Perfect score is calculated
8. Can hold a piece using SELECT button (you lose the ability to taunt the Kraken though 😢)
9. A secret song can be played

# COMPILING

Everything you need to build the ROM from scratch can be found in the repro.

With Visual Studio Code (https://code.visualstudio.com/):
1. On the Visual Studio menu bar, choose File > Open > Folder, and then browse to the code location.
2. Use Ctrl+Shift+B (Build Menu)
3. Then click on "Build All & Run"

# SOURCE

All of the source for the game is found in [here](game/). The 2 files you will be most interested in are [main.h](game/main.h) and [main.c](game/main.c) which contain all the logic for the game.

# NOTES
Due to changes of the code from the original source, the VS version *cannot* be compiled due to memory limitations as adding SRS and T-Spin scoring has exceeded the memory. For the time being, only the NES version can be compiled.