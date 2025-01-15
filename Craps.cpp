#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int MIN_BET = 10;
const int MAX_BET = 200;

void gameBoard (string puckStatus, string BetDontCome, string BetCome, string BetDontPass, string BetPass, string dice4, string dice5, string dice6, string dice8, string dice9, string dice10){
    cout << "------------------------------ "<<endl;
    cout << "Puck Status: " << puckStatus <<endl;
    cout << "                    Don't \n";
    cout << "      Point   Come   Come  \n";
    cout << "------------------------------ \n";
    cout << dice4  << "       4                \n";
    cout << dice5  << "       5                \n";
    cout << dice6  << "     Six                \n";
    cout << dice8  << "       8                \n";
    cout << dice9  << "    Nine                \n";
    cout << dice10 << "      10                \n";
    cout << "                        \n";
    cout << "Don't Come: " << BetDontCome << endl;
    cout << "      Come: " << BetCome     << endl;
    cout << "Don't Pass: " << BetDontPass << endl;
    cout << "      Pass: " << BetPass     << endl;
    cout << "------------------------------ \n";
}

void displayMenu(int balance) {
    cout << "------------------------------ " << endl;
    cout << "|          Bet Menu          | " << endl;
    cout << "|----------------------------| " << endl;
    cout << "| Chips Balance: $" << balance << "        | "<< endl;
    cout << "|----------------------------| " << endl;
    cout << "| 1.) Bet Pass Line          |\n";
    cout << "| 2.) Bet Don't Pass Line    |\n";
    cout << "| 3.) Roll the Dice          |\n";
    cout << "| 4.) Quit                   |\n";
    cout << "------------------------------";
    cout << "\n Your Choice? ";
}

void displayAddBetMenu(int balance) {
    cout << "------------------------------ " << endl;
    cout << "|    Additional Bet Menu     | " << endl;
    cout << "|----------------------------| " << endl;
    cout << "| Chips Balance: $" << balance << "        | "<< endl;
    cout << "|----------------------------| " << endl;
    cout << "| 1.) Bet Pass Line          |\n";
    cout << "| 2.) Bet Don't Pass Line    |\n";
    cout << "| 3.) Roll the Dice          |\n";
    cout << "| 4.) Quit                   |\n";
    cout << "------------------------------";
    cout << "\n Your Choice? ";
}

void updateDiceVariables(int dice, string &dice4, string &dice5, string &dice6, string &dice8, string &dice9, string &dice10) {
    dice4 = dice5 = dice6 = dice8 = dice9 = dice10 = "  ";  // Reset all
    if (dice == 4) dice4 = "On";
    else if (dice == 5) dice5 = "On";
    else if (dice == 6) dice6 = "On";
    else if (dice == 8) dice8 = "On";
    else if (dice == 9) dice9 = "On";
    else if (dice == 10) dice10 = "On";
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
    int balance = 500;
    int currentBetPass = 0;
    int currentBetCome = 0;

    string BetDontCome = " ";
    string BetCome = " ";
    string BetDontPass = " ";
    string BetPass = " ";

    bool BetDontComeBool = false;
    bool BetComeBool = false;
    bool BetDontPassBool = false;
    bool BetPassBool = false;

    string dice4  = "  "; 
    string dice5  = "  "; 
    string dice6  = "  "; 
    string dice8  = "  "; 
    string dice9  = "  "; 
    string dice10 = "  ";

    bool PlayingMain = true;
    bool PointBetting = true;
    int point = 0;
    int die1;
    int die2;
    string puckStatus = "Off";

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


    while (PlayingMain) {
        displayMenu(balance);
        int choice;
        cin >> choice;
        cout<< " \n";
        if (choice == 1) { // Bet Pass Line
            cout << " You have "<< balance <<". How much do you wish to bet? ";
            cin >> currentBetPass;

            while (currentBetPass < MIN_BET || currentBetPass > MAX_BET || currentBetPass > balance) {
                cout << "Invalid bet amount. Min bet is 10 and Max bet is 200. Please try again.\n";
                cout << "You have "<< balance <<". How much do you wish to bet? ";
                cin >> currentBetPass;
            }

            balance = balance - currentBetPass;
            BetPass = to_string(currentBetPass);
            BetPassBool = true;
            gameBoard(puckStatus, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10);
        }

        if (choice == 2) { // Bet Dont Pass
            cout << " You have "<< balance <<". How much do you wish to bet? ";
            cin >> currentBetPass;

            while (currentBetPass < MIN_BET || currentBetPass > MAX_BET || currentBetPass > balance) {
                cout << "Invalid bet amount. Please try again.\n";
                cout << " You have "<< balance <<". How much do you wish to bet? ";
                cin >> currentBetPass;
            }

            balance = balance - currentBetPass;
            BetDontPass = to_string(currentBetPass);
            BetDontPassBool = true;
            gameBoard(puckStatus, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10);
        }

        if (choice == 3) { // Roll the dice
            die1 = rollDice();
            die2 = rollDice();
            displayDice(die1, die2);
            int dice = die1 + die2;

            cout << "You rolled a " << dice << endl;

            if (puckStatus == "Off") {
                // Initial roll when the puck is off
                if (dice == 7 || dice == 11) {
                    // Pass Line wins
                    if (BetPassBool) {
                        balance += currentBetPass * 2;
                    }
                    currentBetPass = 0;
                    BetPass = " ";
                    cout << "You win! Pass Line pays out." << endl;
                } else if (dice == 2 || dice == 3 || dice == 12) {
                    // Don't Pass Line wins
                    if (BetDontPassBool) {
                        balance += currentBetPass * 2;
                    }
                    currentBetPass = 0;
                    BetDontPass = " ";
                    cout << "You win! Don't Pass Line pays out." << endl;
                } else if (dice == 4 || dice == 5 || dice == 6 || dice == 8 || dice == 9 || dice == 10) {
                    // Point is set; puck turns on
                    puckStatus = "On";
                    point = dice;
                    cout << "Point is set to " << point << ". Puck is now ON." << endl;

                    // Update dice variables to display the point
                    updateDiceVariables(point, dice4, dice5, dice6, dice8, dice9, dice10);
                }
            } else if (puckStatus == "On") {
                // Subsequent rolls when the puck is on
                if (dice == 7) {
                    // Seven out, pass line loses
                    cout << "Seven out! Pass Line loses." << endl;
                    puckStatus = "Off";
                    point = 0;
                    BetPass = " ";
                    BetDontPass = " ";
                    

                    // Reset dice variables
                    updateDiceVariables(point, dice4, dice5, dice6, dice8, dice9, dice10);
                } else if (dice == point) {
                    // Player hits the point
                    cout << "You hit the point! Pass Line wins." << endl;
                    if (BetPassBool) {
                        balance += currentBetPass * 2;
                    }
                    currentBetPass = 0;
                    BetPass = " ";
                    BetDontPass = " ";
                    puckStatus = "Off";
                    point = 0;

                    // Reset dice variables
                    updateDiceVariables(point, dice4, dice5, dice6, dice8, dice9, dice10);
                } else {
                    // Roll doesn't resolve, puck stays on
                    cout << "Roll doesn't resolve. Puck remains ON." << endl;
                }
            }
            // Update the game board after every roll
            gameBoard(puckStatus, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10);
        }

        if (choice == 4) { // Quit the game
            cout << "Thanks for playing!\n";
            PlayingMain = false;
        }
        updateDiceVariables(point, dice4, dice5, dice6, dice8, dice9, dice10);
    }
    return 0;
}


/*













    while (PointBetting){

        displayAddBetMenu(balance);
        int choice;
        cin >> choice;
        cout<< " \n";
        if (choice == 1) { // Bet Come
            cout << " You have "<< balance <<". How much do you wish to bet? ";
            cin >> currentBetCome;

            while (currentBetCome < MIN_BET || currentBetCome > MAX_BET || currentBetCome > balance) {
                cout << "Invalid bet amount. Min bet is 10 and Max bet is 200. Please try again.\n";
                cout << "You have "<< balance <<". How much do you wish to bet? ";
                cin >> currentBetCome;
            }

            balance = balance - currentBetCome;
            BetCome = to_string(currentBetCome);
            BetComeBool = true;
        }


        if (choice == 2) { // Bet Dont Come
            cout << " You have "<< balance <<". How much do you wish to bet? ";
            cin >> currentBetCome;

            while (currentBetCome < MIN_BET || currentBetCome > MAX_BET || currentBetCome > balance) {
                cout << "Invalid bet amount. Please try again.\n";
                cout << " You have "<< balance <<". How much do you wish to bet? ";
                cin >> currentBetCome;
            }

            balance = balance - currentBetCome;
            BetDontCome = to_string(currentBetCome);
            BetDontComeBool = true;
        }

        if (choice == 3) { // Rolls Dice
            die1 = rollDice();
            die2 = rollDice();
            displayDice(die1, die2);
            int dice = die1 + die2;
            cout << "You Rolled a " << dice <<endl;
            
            if(dice == 7 || 11){
                if (BetComeBool == true){
                    balance = (currentBetCome * 2) + balance;
                    currentBetCome = 0;
                    BetCome = " ";
                }
                else if (BetDontComeBool == true){
                    currentBetCome = 0;
                    BetDontCome = " ";
                }
            }

            if(dice == 2 || 3 || 12){
                if (BetDontComeBool == true){
                    balance = (currentBetCome * 2) + balance;
                    currentBetCome = 0;
                    BetDontCome = " ";
                }
                else if (BetComeBool == true){
                    currentBetCome = 0;
                    BetCome = " ";
                }
            }
            
            if (dice == 4 || 5 || 6 || 8 || 9 || 10){
                
                puckStatus = "On";
                point = dice;
                PointOFMenu(dice, dice4, dice5, dice6, dice8, dice9, dice10);
            }
        }

        if (choice == 4) { // Quit the game
            PlayingMain = false;
            PointBetting = false;
            cout << "Thanks for playing!\n";
        }

        gameBoard(puckStatus, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10);
    }
    

    return 0;
}  



*/