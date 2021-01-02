# FROM BELOW

A brand new game for the Nintendo Entertainment System!

Details on the game, along with downloads (for the original game) of compiled ROM can be found here: https://mhughson.itch.io/from-below

Differences from original:
1. The use of SRS rotation system (https://tetris.fandom.com/wiki/SRS) instead of Nintendo Rotation System - Right Handed version (https://harddrop.com/wiki/Nintendo_Rotation_System) used in Tetris (NES) with the added Wall Kick. So you are now able to do T-Spins with Twists.
2. T-Spin score is calculated
- No line: 40 points (same as 1 line)
- 1, 2, and 3 Lines: 5x score
3. T-Spin triple plays Tetris sound with the shake 

# COMPILING

Everything you need to build the ROM from scratch can be found in the repro.

With Visual Studio Code (https://code.visualstudio.com/):
1. On the Visual Studio menu bar, choose File > Open > Folder, and then browse to the code location.
2. Use Ctrl+Shift+B (Build Menu), Click on "Build All & Run"

# SOURCE

All of the source for the game is found in [here](game/). The 2 files you will be most interested in are [main.h](game/main.h) and [main.c](game/main.c) which contain all the logic for the game.

# NOTES
Due to changes of code from original, the VS version cannot be compiled, due to memory limitations. Only NES version can be compiled.