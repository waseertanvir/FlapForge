# TODO

## Rename
- [ ] Rename CMake project/target and window title from `flappy-clone` / "Flappy Clone" to FlapForge

## Build
- [ ] Change `#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"` to `#include "raylib.h"` so builds don't depend on the build folder name
- [ ] Copy `assets/` next to the executable (or set the working directory) so the game runs from anywhere

## Gameplay
- [ ] Pipes: spawn, scroll, and recycle (`pipe_body`, `pipe_cap_top`, `pipe_cap_bottom`)
- [ ] Collision with pipes and the top of the screen
- [ ] Scoring when passing pipes, plus a high score
- [ ] Start screen ("press Space to start") and game-over screen
- [ ] Reset on R should also clear `isGameOver` and the ground scroll
- [ ] Coins (`coin.png`)

## Visuals
- [ ] Draw the sky background (`background_sky.png`) — it is loaded but never drawn
- [ ] Animate the bird using `bird_flap_0/1/2`
- [ ] Tilt the bird based on its velocity
- [ ] Score display with `score_badge.png`
- [ ] Replay button (`button_replay.png`)

## Polish
- [ ] Sound effects (flap, score, hit)
- [ ] Mouse click / touch to flap
- [ ] Clean up old `main.cpp.bak*` files
