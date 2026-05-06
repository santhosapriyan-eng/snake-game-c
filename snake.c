### 📄 snake.c (Complete Code)
```c
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// Game dimensions
int width = 20;
int height = 15;

// Game variables
int x, y;               // Snake head position
int foodX, foodY;       // Food position
int score;              // Player score
int tailX[100];         // Tail X positions
int tailY[100];         // Tail Y positions
int tailLength = 0;     // Current tail length
int gameOver = 0;       // Game state flag
char dir = 'R';         // Current direction (R, L, U, D)

// Function to initialize game state
void setup() {
    gameOver = 0;
    x = width / 2;
    y = height / 2;
    score = 0;
    tailLength = 0;
    dir = 'R';
    
    // Seed random number generator
    srand(time(NULL));
    
    // Generate first food position
    foodX = rand() % width;
    foodY = rand() % height;
}

// Function to draw the game board
void draw() {
    system("cls");  // Clear console
    
    // Draw top border
    for (int i = 0; i < width + 2; i++) {
        printf("#");
    }
    printf("\n");
    
    // Draw game area
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) printf("#");  // Left border
            
            if (i == y && j == x) {
                printf("O");  // Snake head
            }
            else if (i == foodY && j == foodX) {
                printf("*");  // Food
            }
            else {
                int print = 0;
                // Draw tail segments
                for (int k = 0; k < tailLength; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print) printf(" ");
            }
            
            if (j == width - 1) printf("#");  // Right border
        }
        printf("\n");
    }
    
    // Draw bottom border
    for (int i = 0; i < width + 2; i++) {
        printf("#");
    }
    printf("\n");
    
    // Display score and controls
    printf("Score: %d\n", score);
    printf("Controls: W A S D | X to Exit\n");
}

// Function to handle keyboard input
void input() {
    if (_kbhit()) {
        char ch = _getch();
        switch (ch) {
            case 'a':
            case 'A':
                if (dir != 'R') dir = 'L';
                break;
            case 'd':
            case 'D':
                if (dir != 'L') dir = 'R';
                break;
            case 'w':
            case 'W':
                if (dir != 'D') dir = 'U';
                break;
            case 's':
            case 'S':
                if (dir != 'U') dir = 'D';
                break;
            case 'x':
            case 'X':
                gameOver = 1;
                break;
        }
    }
}

// Function to update game logic
void logic() {
    // Move tail: shift all segments
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    
    for (int i = 1; i < tailLength; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
    // Move snake head based on direction
    switch (dir) {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y--;
            break;
        case 'D':
            y++;
            break;
    }
    
    // Wall collision detection
    if (x < 0 || x >= width || y < 0 || y >= height) {
        gameOver = 1;
    }
    
    // Self collision detection
    for (int i = 0; i < tailLength; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = 1;
        }
    }
    
    // Food collision detection
    if (x == foodX && y == foodY) {
        score += 10;
        tailLength++;
        // Generate new food at random position
        foodX = rand() % width;
        foodY = rand() % height;
        
        // Ensure food doesn't spawn on snake
        int onSnake = 1;
        while (onSnake) {
            onSnake = 0;
            for (int i = 0; i < tailLength; i++) {
                if (tailX[i] == foodX && tailY[i] == foodY) {
                    onSnake = 1;
                    foodX = rand() % width;
                    foodY = rand() % height;
                    break;
                }
            }
        }
    }
}

// Main function
int main() {
    printf("=== SNAKE GAME ===\n");
    printf("Press any key to start...\n");
    getch();
    
    setup();
    
    // Game loop
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100);  // 100ms delay for smooth gameplay
    }
    
    // Game over screen
    system("cls");
    printf("\n");
    printf("╔══════════════════════════════╗\n");
    printf("║         GAME OVER!           ║\n");
    printf("╠══════════════════════════════╣\n");
    printf("║    Final Score: %-5d         ║\n", score);
    printf("║    Tail Length: %-5d         ║\n", tailLength);
    printf("╚══════════════════════════════╝\n");
    printf("\nPress any key to exit...\n");
    getch();
    
    return 0;
}
