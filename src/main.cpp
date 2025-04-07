#include <raylib.h>
#include <iostream>

int main() 
{

    const Color darkGreen = {20, 160, 133, 255};
    
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    
    InitWindow(screenWidth, screenHeight, "Pong Clone");
    SetTargetFPS(60);

    using namespace std;
    
    while (!WindowShouldClose())
    {
       
        cout << "Starting the game" << endl;

        // BeginDrawing();
        //     ClearBackground(darkGreen);
        // EndDrawing();

        return 0;
    }
    
    // CloseWindow();
}