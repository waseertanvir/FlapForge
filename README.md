# FlapForge

A Flappy Bird–style game written in C++17 with [raylib](https://www.raylib.com/).

> **Status:** early work in progress. See [TODO.md](TODO.md) for what's left.

## Inspiration

FlapForge is inspired by the original **Flappy Bird** game by Dong Nguyen. It is a fan-made project for learning and fun, and is not affiliated with or endorsed by the original creator.

## Art

The sprites are modern, updated vector-style redraws rather than the original pixel art. They were created in a separate repo:
**[waseertanvir/modern-flappy-bird-assets](https://github.com/waseertanvir/modern-flappy-bird-assets)** (MIT License).

They live in `assets/textures/modern/`.

## Building

Requires CMake 3.16+ and a C++17 compiler. raylib 5.5 is downloaded automatically by CMake.

```bash
cmake -B cmake-build-debug
cmake --build cmake-build-debug
./cmake-build-debug/flappy-clone   # run from the project root so assets load
```

## Controls

| Key   | Action  |
|-------|---------|
| Space | Flap    |
| R     | Reset   |
| Esc   | Quit    |
