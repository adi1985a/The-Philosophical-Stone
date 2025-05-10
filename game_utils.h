#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <windows.h>

// Move PlayerState before GameUtils
struct PlayerState {
    int health = 100;
    bool hasKey = false;
    bool hasPhilosophersStone = false;
    int sanity = 100;

    void damage(int amount) {
        health = std::max(0, health - amount);
    }

    void heal(int amount) {
        health = std::min(100, health + amount);
    }

    void changeSanity(int amount) {
        sanity = std::max(0, std::min(100, sanity + amount));
    }
};

class GameUtils {
public:
    static void clearScreen() {
        system("cls");
    }
    
    static void setColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    static void displayStats(const PlayerState& player) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << "\nHealth: ";
        for(int i = 0; i < 20; i++) {
            std::cout << (i < player.health/5 ? "|" : "-");
        }
        std::cout << " " << player.health << "%\n";

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "Sanity: ";
        for(int i = 0; i < 20; i++) {
            std::cout << (i < player.sanity/5 ? "|" : "-");
        }
        std::cout << " " << player.sanity << "%\n\n";
        
        // Reset color
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    static void printSlowly(const std::string& text, int delay = 30) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        for (char c : text) {
            std::cout << c << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
        }
        std::cout << std::endl;
        // Reset color
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    static bool processChoice(const std::string& choice, PlayerState& player) {
        if (choice.length() != 1) return false;
        char c = choice[0];
        return (c >= 'a' && c <= 'f');
    }

    static void wait() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    static void delay(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
};
