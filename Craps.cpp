#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void displayMenu() {
    cout << "    Bet Menu\n";
    cout << "1.) Bet Pass Line\n";
    cout << "2.) Bet Don't Pass Line\n";
    cout << "3.) Roll the Dice\n";
    cout << "4.) Quit\n";
    cout << "Your Choice? ";
}

int rollDice() {
    int die = rand() % 6 + 1;
    return die;
}

void displayDice(int die1, int die2) {
    cout << "+-------+ +-------+\n";
    cout << "|       | |       |\n";
    cout << "|   " << die1 << "   | |   " << die2 << "   |\n";
    cout << "|       | |       |\n";
    cout << "+-------+ +-------+\n";
}

int main() { 
    const double MIN_BET = 10.0;
    const double MAX_BET = 200.0;
    double balance = 500.0;
    double currentBet = 0.0;
    bool playing = true;
    int point = 0;
    int die1;
    int die2;

    srand(time(0));

    cout << " ________  ________  ________  ___  ________   ________                          "<< endl;
    cout << "|\\   ____\\|\\   __  \\|\\   ____\\|\\  \\|\\   ___  \\|\\   __  \\             "<< endl;
    cout << "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\  "<< endl;
    cout << " \\ \\  \\    \\ \\   __  \\ \\_____  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\   "<< endl;
    cout << "  \\ \\  \\____\\ \\  \\ \\  \\|____|\\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\"<< endl;
    cout << "   \\ \\_______\\ \\__\\ \\__\\____\\_\\  \\ \\__\\ \\__\\\\ \\__\\ \\_______\\  "<< endl;
    cout << "    \\|_______|\\|__|\\|__|\\_________\\|__|\\|__| \\|__|\\|_______|             "<< endl;
    cout << "                                                                                 "<< endl;
    cout << " ________  ________  ________  ________  ________                                "<< endl;
    cout << "|\\   ____\\|\\   __  \\|\\   __  \\|\\   __  \\|\\   ____\\                     "<< endl;
    cout << "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\___|_            "<< endl;
    cout << " \\ \\  \\    \\ \\   _  _\\ \\   __  \\ \\   ____\\ \\_____  \\                 "<< endl;
    cout << "  \\ \\  \\____\\ \\  \\\\  \\\\ \\  \\ \\  \\ \\  \\___|\\|____|\\  \\          "<< endl;
    cout << "   \\ \\_______\\ \\__\\\\ _\\\\ \\__\\ \\__\\ \\__\\     ____\\_\\  \\          "<< endl;
    cout << "    \\|_______|\\|__|\\|__|\\|__|\\|__|\\|__|    |\\_________\\                  "<< endl;
    cout << "                                           \\|_________|                         "<< endl;

    while (playing) {
        cout << "\nChips Balance: $" << balance << endl;
        displayMenu();

        int choice;
        cin >> choice;

        if (choice == 3) { // Rolls Dice
            die1 = rollDice();
            die2 = rollDice();
            displayDice(die1, die2);
            int dice = die1 + die2;
            cout << "You Rolled a " << dice <<endl;
        }

        if (choice == 4) { // Quit the game
            playing = false;
            cout << "Thanks for playing!\n";
        }
    }

    return 0;
}  