#include <iostream>
#include <Windows.h>
#include <filesystem>
#include <ctime>


int main()
{
    std::cout << "ALLC by Rismose\n";
    std::cout << "\n";
    std::cout << "Press Y to auto clear the League of Legends log files\n";

    // Wait for the user to press Y
    bool keyY_pressed = false;
    while (!keyY_pressed)
    {
        if (GetAsyncKeyState(0x59) & 0x8000)
        {
            keyY_pressed = true;
            // Print message to console
            std::cout << "[i] Logs will clear every 30 seconds\n";
        }
    }

    


    while (keyY_pressed)
    {
        // Make a function that gets the current time and stores it in a string, use the ctime library and ctime_s
        time_t current_time = time(0);
        char current_time_str[100];
        ctime_s(current_time_str, sizeof(current_time_str), &current_time);

        // Delete the "Log" folder in "C:\Riot Games\League of Legends"
        std::filesystem::remove_all("C:\\Riot Games\\League of Legends\\Logs");
        // Print a message to the console with a timestamp
        std::cout << "[+] Logs cleared at " << current_time_str;
        
        // Recreate the "Log" folder
        std::filesystem::create_directory("C:\\Riot Games\\League of Legends\\Logs");

        // Wait 30 seconds before clearing the logs again
        Sleep(30000);
    }

    return 0;
}
