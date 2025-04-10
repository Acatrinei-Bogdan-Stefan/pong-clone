#include <raylib.h>
#include <iostream>

using namespace std;

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int player_score = 0;
int cpu_score = 0;

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
    DrawCircle(x, y, radius, Yellow);
}

void Update()
{
    x += speed_x;
    y += speed_y;

    if(y + radius >= GetScreenHeight() || y - radius <= 0) 
    {
        speed_y *= -1;
    }
    if(x + radius >= GetScreenWidth()) // CPU wins
    {
        cpu_score++;
        ResetBall();
    }

    if(x - radius <= 0) 
    {
        player_score++;
        ResetBall();
    } 
    
}

void ResetBall()
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int speed_choices[2] = {-1,1};
    speed_x *= speed_choices[GetRandomValue(0,1)];
    speed_y *= speed_choices[GetRandomValue(0,1)];
}

};

//Paddle class
class Paddle 
{
protected:

void LimitMovement()
{
    if(y <= 0)
    {
        y = 0;
    }
    if(y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}

public:
float x, y;
float width, height;
int speed;

void Draw()
{
    // DrawRectangle(x, y, width, height, WHITE);
    // DrawRectangleRounded(Rec, roundness, segment, color);
    DrawRectangleRounded( Rectangle{x, y, width, height}, 0.8, 0, WHITE);

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

    LimitMovement();
}

};

// Chiled of the Paddle Class (Inheritance)
class CpuPaddle: public Paddle
{
    public:

    void Update(int ball_y)
    {
        if(y + height / 2 > ball_y)
        {
            y = y - speed; 
        }
        if(y + height / 2 <= ball_y)
        {
            y = y + speed;
        }
        LimitMovement();
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
            
            // Update
            ball.Update();
            player.Update();
            cpu.Update(ball.y);

            //Checking for collisions
            if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
            {
                ball.speed_x *= -1;
            }

            if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
            {
                ball.speed_x *= -1;
            }

            // Draw
            ClearBackground(Dark_Green);
            DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
            DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
            ball.Draw();
            player.Draw();
            cpu.Draw();
            // DrawText(text, xpos, ypos, fontsize, color)
            DrawText(TextFormat("%i",cpu_score), screenWidth / 4 - 20, 20, 80, WHITE);
            DrawText(TextFormat("%i",player_score), 3 * screenWidth / 4 - 20, 20, 80, WHITE);

            DrawLine(screenWidth/2 ,0 ,screenWidth/2, screenHeight, WHITE);
            

        EndDrawing();

        
    }
    CloseWindow();
    return 0;
}