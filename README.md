# 🐍 Classic Snake Game in C

A fully functional console-based Snake game implemented in pure C programming language. This project demonstrates real-time game development fundamentals without external graphics libraries.

## 🎮 Gameplay



Control a snake that grows longer each time it eats food. The game ends if the snake hits the wall or collides with its own body.

## ✨ Features

- ✅ Real-time non-blocking keyboard input using `_kbhit()` / `_getch()`
- ✅ Array-based tail management system
- ✅ Boundary and self-collision detection
- ✅ Dynamic food generation at random positions
- ✅ Score tracking (10 points per food)
- ✅ Smooth gameplay with 120ms frame delay
- ✅ Console-based ASCII graphics

## 🎯 Controls

| Key | Action |
|-----|--------|
| `W` | Move Up |
| `A` | Move Left |
| `S` | Move Down |
| `D` | Move Right |
| `X` | Exit Game |

## 🖥️ System Requirements

- Windows Operating System (uses windows.h and conio.h)
- GCC or any C compiler (Turbo C, Dev-C++, Code::Blocks)
- Terminal/Command Prompt with console support

## 🔧 Compilation & Execution

### Using GCC (MinGW)
```bash
gcc snake.c -o snake.exe
./snake.exe
