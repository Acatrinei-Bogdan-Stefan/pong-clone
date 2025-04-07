#include <raylib.h>
#include <iostream>

int main() 
{

    const Color darkGreen = {20, 160, 133, 255};
    
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 800;

    
    InitWindow(screenWidth, screenHeight, "My Pong Game");
    SetTargetFPS(60);

    // using namespace std;
    
    while (!WindowShouldClose())
    {
       
        // cout << "Starting the game" << endl;

        BeginDrawing();
            ClearBackground(darkGreen);

            DrawCircle(screenWidth/2,screenHeight/2, 20, WHITE);
            DrawRectangle(0, 0, 25, 120, WHITE);
            DrawRectangle(200, 200, 25, 120, BLACK);
        EndDrawing();

        
    }
    CloseWindow();
    return 0;
}