#include <raylib.h>
#include <iostream>

// Class
class Ball
{
// Variables
public:
float x,y;
int speed_x,speed_y;
int radius;

//Functii
void Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

void Update()
{
    x += speed_x;
    y += speed_y;

    if( y + radius >= GetScreenHeight() || y - radius <= 0) 
    {
        speed_y *= -1;
    }
    if(x + radius >= GetScreenWidth() || x - radius <= 0)
    {
        speed_x *= -1;
    }
}

};


class Paddle 
{
public:
float x, y;
float width, height;
int speed;

void Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}
};

// Object Copy
Ball ball;

int main() 
{

    // const Color darkGreen = {20, 160, 133, 255};
    
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 800;

    ball.radius = 20;
    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    InitWindow(screenWidth, screenHeight, "My Pong Game");
    SetTargetFPS(60);

    
    while (!WindowShouldClose())
    {


        BeginDrawing();
            ClearBackground(BLACK);
            // Update
            ball.Update();

            // Draw
            ball.Draw();
            DrawRectangle(10, screenHeight/2-60, 25, 120, WHITE);
            DrawLine(screenWidth/2 ,0 ,screenWidth/2, screenHeight, WHITE);

        EndDrawing();

        
    }
    CloseWindow();
    return 0;
}