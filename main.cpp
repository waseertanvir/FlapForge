#include "cmake-build-debug/_deps/raylib-src/src/raylib.h"

constexpr int GAME_WIDTH = 288;
constexpr int GAME_HEIGHT = 512;
constexpr float WINDOW_SCALE = 2.0f;
constexpr int BIRD_SIZE = 34;
constexpr int GROUND_HEIGHT = 64;
constexpr float GRAVITY = 1200.0f;
constexpr float FLAP_STRENGTH = 380.0f;
constexpr float GROUND_SPEED = 50.0f;

int main() {
    SetConfigFlags(FLAG_VSYNC_HINT);
    Camera2D camera = {0};
    camera.zoom = WINDOW_SCALE;

    constexpr float WINDOW_WIDTH = static_cast<int>(GAME_WIDTH * WINDOW_SCALE);
    constexpr float WINDOW_HEIGHT = static_cast<int>(GAME_HEIGHT * WINDOW_SCALE);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Flappy Clone");

    float positionY = GAME_HEIGHT / 2.0f;
    float birdVelocity = 0.0f;

    const Texture2D birdTexture = LoadTexture("assets/textures/modern/bird_flap_1.png");
    const Texture2D backgroundTexture = LoadTexture("assets/textures/modern/background_sky.png");
    const Texture2D groundTexture = LoadTexture("assets/textures/modern/ground_tile.png");

    SetTextureFilter(birdTexture, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(backgroundTexture, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(groundTexture, TEXTURE_FILTER_BILINEAR);

    const float groundScale = (GAME_WIDTH / static_cast<float>(groundTexture.width));
    const float groundHeight = static_cast<float>(groundTexture.height) * groundScale;

    float groundShift = 0.0f;
    const float GROUND_Y = GAME_HEIGHT - groundHeight;

    bool isGameOver = false;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            birdVelocity = -FLAP_STRENGTH;
        }

        if (IsKeyPressed(KEY_R)) {
            birdVelocity = 0;
            positionY = GAME_HEIGHT / 2.0f;
        }

        if (GAME_WIDTH + static_cast<int>(groundShift) <= 0) {
            groundShift = 0.0f;
        }

        float dt = GetFrameTime();

        if (isGameOver) {
            dt = 0.0f;
        }

        if (positionY >= GROUND_Y) {
            isGameOver = true;
        }

        birdVelocity += GRAVITY * dt;
        positionY += birdVelocity * dt;
        groundShift -= dt * GROUND_SPEED;

        constexpr int positionX = (GAME_WIDTH / 2) - (BIRD_SIZE / 2);

        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode2D(camera);

        DrawTextureEx(
            birdTexture,
            Vector2{positionX, positionY},
            0.0f,
            BIRD_SIZE / (float) birdTexture.width,
            WHITE
        );

        DrawTextureEx(
            groundTexture,
            Vector2{groundShift, GROUND_Y},
            0.0f,
            groundScale,
            WHITE
        );

        DrawTextureEx(
            groundTexture,
            Vector2{GAME_WIDTH + groundShift, GROUND_Y},
            0.0f,
            groundScale,
            WHITE
        );

        EndMode2D();
        EndDrawing();
    }

    UnloadTexture(birdTexture);
    UnloadTexture(groundTexture);
    UnloadTexture(backgroundTexture);
    CloseWindow();
}
