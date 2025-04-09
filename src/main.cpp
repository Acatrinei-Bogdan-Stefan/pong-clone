#include <raylib.h>
#include <iostream>

// Ball Class
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

//Paddle class
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

void Update()
{
    if(IsKeyDown(KEY_UP))
    {
        y = y - speed;
    }
    if(IsKeyDown(KEY_DOWN))
    {
        y = y + speed;
    }

    if(y <= 0)
    {
        y = 0;
    }
    if(y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}

};

// Chiled of the Paddle Class (Inheritance)
class CpuPaddle: public Paddle
{
    public:

    void Update(int ball_y)
    {
        if(y = height / 2 > ball_y)
        {
            y = y - speed; 
        }
    }
};

// Object Copy
Ball ball;
Paddle player;
CpuPaddle cpu;

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

    player.width = 25;
    player.height = 120;
    player.x = screenWidth - player.width - 10;
    player.y = screenHeight/2 - player.height/2;
    player.speed = 6;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screenHeight/2 - cpu.height / 2;
    cpu.speed = 6;

    InitWindow(screenWidth, screenHeight, "My Pong Game");
    SetTargetFPS(60);

    
    while (!WindowShouldClose())
    {


        BeginDrawing();
            ClearBackground(BLACK);
            // Update
            ball.Update();
            player.Update();

            // Draw
            ball.Draw();
            player.Draw();
            cpu.Draw();

            DrawLine(screenWidth/2 ,0 ,screenWidth/2, screenHeight, WHITE);
            

        EndDrawing();

        
    }
    CloseWindow();
    return 0;
}