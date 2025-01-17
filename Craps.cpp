#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

const int MIN_BET = 10;
const int MAX_BET = 200;

void PassMenu(int balance) {
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
    cout << "\nYour Choice? ";
}

void ComeMenu(int balance) {
    cout << "------------------------------ " << endl;
    cout << "|    Additional Bet Menu     | " << endl;
    cout << "|----------------------------| " << endl;
    cout << "| Chips Balance: $" << balance << "        | "<< endl;
    cout << "|----------------------------| " << endl;
    cout << "| 1.) Bet Come Line          |\n";
    cout << "| 2.) Bet Dont Come Line     |\n";
    cout << "| 3.) Roll the Dice          |\n";
    cout << "| 4.) Quit                   |\n";
    cout << "------------------------------";
    cout << "\nYour Choice? ";
}

void gameBoard (string puckStatus, string BetDontCome, string BetCome, string BetDontPass, string BetPass, 
                string dice4, string dice5, string dice6, string dice8, string dice9, string dice10,
                string Come4, string Come5, string Come6, string Come8, string Come9, string Come10,
                string DCome4, string DCome5, string DCome6, string DCome8, string DCome9, string DCome10){
    cout << "------------------------------ "<<endl;
    cout << "Puck Status: " << puckStatus << endl;
    cout << "                            \n";
    cout << "                    Don't \n";
    cout << "      Point   Come   Come  \n";
    cout << "------------------------------ \n";
    cout << dice4  << "       4     "<<Come4<<"     "<<DCome4<<"  \n";
    cout << dice5  << "       5     "<<Come5<<"     "<<DCome5<<"  \n";
    cout << dice6  << "     Six     "<<Come6<<"     "<<DCome6<<"  \n";
    cout << dice8  << "       8     "<<Come8<<"     "<<DCome8<<"  \n";
    cout << dice9  << "    Nine     "<<Come9<<"     "<<DCome9<<"  \n";
    cout << dice10 << "      10     "<<Come10<<"     "<<DCome10<<"   \n";
    cout << "                        \n";
    cout << "Don't Come: " << BetDontCome << endl;
    cout << "      Come: " << BetCome     << endl;
    cout << "Don't Pass: " << BetDontPass << endl;
    cout << "      Pass: " << BetPass     << endl;
    cout << "------------------------------ \n";
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

void updateComeBetVariables(string BetCome, int dice, string &Come4, string &Come5, string &Come6, string &Come8, string &Come9, string &Come10) {

    Come4 = Come5 = Come6 = Come8 = Come9 = Come10 = "   ";  // Reset all
    if (dice == 4) Come4 = BetCome;
    else if (dice == 5) Come5 = BetCome;
    else if (dice == 6) Come6 = BetCome;
    else if (dice == 8) Come8 = BetCome;
    else if (dice == 9) Come9 = BetCome;
    else if (dice == 10) Come10 = BetCome;
}

void updateDontComeBetVariables(string BetDontCome, int dice, string &DCome4, string &DCome5, string &DCome6, string &DCome8, string &DCome9, string &DCome10) {

    DCome4 = DCome5 = DCome6 = DCome8 = DCome9 = DCome10 = "   "; // Reset all
    if (dice == 4) DCome4 = BetDontCome;
    else if (dice == 5) DCome5 = BetDontCome;
    else if (dice == 6) DCome6 = BetDontCome;
    else if (dice == 8) DCome8 = BetDontCome;
    else if (dice == 9) DCome9 = BetDontCome;
    else if (dice == 10) DCome10 = BetDontCome;
}

int rollDice() {
    int die = rand() % 6 + 1;
    return die;
}

void displayDice(int dice) {
    
    if(dice == 2){
        cout << "+-------+ +-------+\n";
        cout << "|       | |       |\n";
        cout << "|   o   | |   o   |\n";
        cout << "|       | |       |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 3){
        cout << "+-------+ +-------+\n";
        cout << "| o     | |       |\n";
        cout << "|       | |   o   |\n";
        cout << "|     o | |       |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 4){
        cout << "+-------+ +-------+\n";
        cout << "| o     | | o     |\n";
        cout << "|       | |       |\n";
        cout << "|     o | |     o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 5){
        cout << "+-------+ +-------+\n";
        cout << "| o     | | o     |\n";
        cout << "|   o   | |       |\n";
        cout << "|     o | |     o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 6){
        cout << "+-------+ +-------+\n";
        cout << "| o     | | o     |\n";
        cout << "|   o   | |   o   |\n";
        cout << "|     o | |     o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 7){
        cout << "+-------+ +-------+\n";
        cout << "| o   o | | o     |\n";
        cout << "|       | |   o   |\n";
        cout << "| o   o | |     o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 8){
        cout << "+-------+ +-------+\n";
        cout << "| o   o | | o   o |\n";
        cout << "|       | |       |\n";
        cout << "| o   o | | o   o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 9){
        cout << "+-------+ +-------+\n";
        cout << "| o   o | | o   o |\n";
        cout << "|   o   | |       |\n";
        cout << "| o   o | | o   o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 10){
        cout << "+-------+ +-------+\n";
        cout << "| o   o | | o   o |\n";
        cout << "|   o   | |   o   |\n";
        cout << "| o   o | | o   o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 11){
        cout << "+-------+ +-------+\n";
        cout << "| o   o | | o   o |\n";
        cout << "| o   o | |   o   |\n";
        cout << "| o   o | | o   o |\n";
        cout << "+-------+ +-------+\n";
    }
    if(dice == 12){
        cout << "+-------+ +-------+\n";
        cout << "| o   o | | o   o |\n";
        cout << "| o   o | | o   o |\n";
        cout << "| o   o | | o   o |\n";
        cout << "+-------+ +-------+\n";
    }
}

void checkBalance(int balance, int CurrentBetPass, int CurrentBetDontPass, int CurrentBetCome, int CurrentBetDontCome) {
    if (balance <= 0 && (CurrentBetCome == 0 && CurrentBetDontCome == 0 && CurrentBetPass == 0 && CurrentBetDontPass == 0)) {
        cout << "You're out of chips! Looks like the house always wins. Better luck next time!\n"<<endl;
        exit(0);
    }
}

int main(){
    int balance = 500;
    int puck = 0;
    int point = 0;

    int PassMenuChoice = 0;
    int ComeMenuChoice = 0;

    int CurrentBetPass = 0;
    int CurrentBetDontPass = 0;
    int CurrentBetCome = 0;
    int CurrentBetDontCome = 0;

    bool BetDontComeBool = false;
    bool BetComeBool = false;
    bool BetDontPassBool = false;
    bool BetPassBool = false;

    string BetDontCome = " ";
    string BetCome = " ";
    string BetDontPass = " ";
    string BetPass = " ";

    int die1;
    int die2;

    string dice4  = "  "; 
    string dice5  = "  "; 
    string dice6  = "  "; 
    string dice8  = "  "; 
    string dice9  = "  "; 
    string dice10 = "  ";

    string Come4  = "  "; 
    string Come5  = "  "; 
    string Come6  = "  "; 
    string Come8  = "  "; 
    string Come9  = "  "; 
    string Come10 = "  ";

    string DCome4  = "  "; 
    string DCome5  = "  "; 
    string DCome6  = "  "; 
    string DCome8  = "  "; 
    string DCome9  = "  "; 
    string DCome10 = "  ";

    bool PlayingGame = true;
    bool PassGame = true;
    bool ComeGame = false;

    bool PuckStatus = false;
    bool PointStatus = 0;
    string PuckStatusString = "Off";

    
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


    //Controlls the Game
    while(PlayingGame){
        checkBalance(balance, CurrentBetPass, CurrentBetDontPass, CurrentBetCome, CurrentBetDontCome);

        //Starting of Pass Betting
        if(PuckStatus == false || PassGame){
            PassMenu(balance);
            cin >> PassMenuChoice;
            cout<< " \n";
             // Check balance after menu choice
            if (PassMenuChoice == 1) { // Bet Pass Line
                cout << "You have "<< balance <<". How much do you wish to bet? ";
                cin >> CurrentBetPass;

                while (CurrentBetPass < MIN_BET || CurrentBetPass > MAX_BET || CurrentBetPass > balance) {
                    cout << "Invalid bet amount. Min bet is 10 and Max bet is 200. Please try again.\n";
                    cout << "You have "<< balance <<". How much do you wish to bet? ";
                    cin >> CurrentBetPass;
                }

                balance = balance - CurrentBetPass;
                BetPass = to_string(CurrentBetPass);
                BetPassBool = true;
                gameBoard(PuckStatusString, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10, Come4, Come5, Come6, Come8, Come9, Come10, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
            }
            if (PassMenuChoice == 2) { // Bet Dont Pass
                cout << "You have "<< balance <<". How much do you wish to bet? ";
                cin >> CurrentBetDontPass;

                while (CurrentBetDontPass < MIN_BET || CurrentBetDontPass > MAX_BET || CurrentBetDontPass > balance) {
                    cout << "Invalid bet amount. Please try again.\n";
                    cout << "You have "<< balance <<". How much do you wish to bet? ";
                    cin >>CurrentBetDontPass;
                }

                balance = balance - CurrentBetDontPass;
                BetDontPass = to_string(CurrentBetDontPass);
                BetDontPassBool = true;
                gameBoard(PuckStatusString, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10, Come4, Come5, Come6, Come8, Come9, Come10, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
            }
            if (PassMenuChoice == 3 ) {
                if(CurrentBetPass > 0 || CurrentBetDontPass > 0){ 
                    die1 = rollDice();
                    die2 = rollDice();
                    int dice = die1 + die2;
                    displayDice(dice);
                    cout << "You rolled a " << dice << endl;
                    if (dice == 7 || dice == 11) {
                        if (BetPassBool) {
                            balance += CurrentBetPass * 2;
                            cout << "You win! Pass Line pays out." << endl;
                        }
                        else if (BetDontPassBool) {
                            cout << "You Lose! Sorry Pal, Better Luck Next Time!" << endl;
                        }
                        BetPassBool = false;
                        CurrentBetPass = 0;
                        BetPass = " ";

                        BetDontPassBool = false;
                        CurrentBetDontPass = 0;
                        BetDontPass = " ";

                    }
                    else if (dice == 2 || dice == 3 || dice == 12) {
                        if (BetDontPassBool) {
                            balance += CurrentBetDontPass * 2;
                            cout << "You win! Don't Pass Line pays out." << endl;
                        }
                        else if (BetPassBool) {
                            cout << "You Lose! Sorry Pal, Better Luck Next Time!" << endl;
                        }
                        BetDontPassBool = false;
                        CurrentBetDontPass = 0;
                        BetDontPass = " ";

                        BetPassBool = false;
                        CurrentBetPass = 0;
                        BetPass = " ";
                    }
                    else{
                        puck = dice;
                        PuckStatusString = "On";
                        PuckStatus = true;
                        PassGame = false;
                        cout << "Puck is set to " << puck << ". Puck is now On." << endl;
                        updateDiceVariables(puck, dice4, dice5, dice6, dice8, dice9, dice10);
                    }
                }

                else if (CurrentBetCome > 0 || CurrentBetDontCome > 0) {
                    // Handle the Come Bets if active
                    cout << "Pass Bet resolved. Moving to Come bets.\n" << endl;
                    ComeGame = true;
                }

                else{
                    cout<< "You have not placed a bet yet! \n"<<endl;
                }
            }
            if (PassMenuChoice == 4) {
                cout << "Thanks for playing!\n"<<endl;
                PlayingGame = false;
            }
        }

        //Starting Of Additional Betting
        if(PuckStatus || ComeGame){
            ComeMenu(balance);
            cin >> ComeMenuChoice;
            cout<< " \n";

            if (ComeMenuChoice == 1) {
                cout << "You have "<< balance <<". How much do you wish to bet? ";
                cin >> CurrentBetCome;

                while (CurrentBetCome < MIN_BET || CurrentBetCome > MAX_BET || CurrentBetCome > balance) {
                    cout << "Invalid bet amount. Min bet is 10 and Max bet is 200. Please try again.\n";
                    cout << "You have "<< balance <<". How much do you wish to bet? ";
                    cin >> CurrentBetCome;
                }

                balance = balance - CurrentBetCome;
                BetCome = to_string(CurrentBetCome);
                BetComeBool = true;
                gameBoard(PuckStatusString, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10, Come4, Come5, Come6, Come8, Come9, Come10, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
            }
            if (ComeMenuChoice == 2) {
                cout << "You have "<< balance <<". How much do you wish to bet? ";
                cin >> CurrentBetDontCome;

                while (CurrentBetDontCome < MIN_BET || CurrentBetDontCome > MAX_BET || CurrentBetDontCome > balance) {
                    cout << "Invalid bet amount. Please try again.\n";
                    cout << "You have "<< balance <<". How much do you wish to bet? ";
                    cin >>CurrentBetDontCome;
                }

                balance = balance - CurrentBetDontCome;
                BetDontCome = to_string(CurrentBetDontCome);
                BetDontComeBool = true;
                gameBoard(PuckStatusString, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10, Come4, Come5, Come6, Come8, Come9, Come10, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
            }
            if (ComeMenuChoice == 3) {
                if (CurrentBetCome > 0 || CurrentBetDontCome > 0 || CurrentBetPass > 0 || CurrentBetDontPass > 0) {
                    die1 = rollDice();
                    die2 = rollDice();
                    int dice = die1 + die2;
                    displayDice(dice);

                    cout << "You rolled a " << dice << endl;

                    if (BetPassBool || BetDontPassBool) {
                        if (dice == 7 || dice == puck) {
                            if (dice == 7) {
                                // Seven out, pass line loses
                                if (BetDontPassBool) {
                                    balance += CurrentBetDontPass * 2;
                                    cout << "You win! Don't Pass Line pays out." << endl;
                                }
                                else if (BetPassBool) {
                                    cout << "You Lose Pass Bet! Sorry Pal, Better Luck Next Time!" << endl;
                                }
                            }
                            else if (dice == puck) {
                                // Player hits the point
                                if (BetPassBool) {
                                    balance += CurrentBetPass * 2;
                                    cout << "You win! Pass Line pays out." << endl;
                                }
                                else if (BetDontPassBool) {
                                    cout << "You Lose Dont Pass Bet! Sorry Pal, Better Luck Next Time!" << endl;
                                }
                            }
                            // Reset Pass bets and puck
                            BetPassBool = BetDontPassBool = false;
                            CurrentBetPass = CurrentBetDontPass = 0;
                            BetPass = BetDontPass = " ";
                            PuckStatus = false;
                            PuckStatusString = "Off";
                            updateDiceVariables(0, dice4, dice5, dice6, dice8, dice9, dice10);
                        }
                    }
                    if (BetComeBool || BetDontComeBool) {
                        if (PointStatus == 0) {
                            // Establish a point for Come/Don't Come
                            if (dice == 7 || dice == 11) {
                                if (BetComeBool) {
                                    balance += CurrentBetCome * 2;
                                    cout << "You win! Come Line pays out." << endl;
                                } else if (BetDontComeBool) {
                                    cout << "You lose! Sorry, better luck next time!" << endl;
                                }
                                BetComeBool = BetDontComeBool = false;
                                CurrentBetCome = CurrentBetDontCome = 0;
                                BetCome = BetDontCome = " ";
                            } else if (dice == 2 || dice == 3 || dice == 12) {
                                if (BetDontComeBool) {
                                    balance += CurrentBetDontCome * 2;
                                    cout << "You win! Don't Come Line pays out." << endl;
                                } else if (BetComeBool) {
                                    cout << "You lose! Sorry, better luck next time!" << endl;
                                }
                                BetComeBool = BetDontComeBool = false;
                                CurrentBetCome = CurrentBetDontCome = 0;
                                BetCome = BetDontCome = " ";
                            } else {
                                // Set point for Come/Don't Come
                                PointStatus = 1;
                                cout << "Point established for Come: " << dice << endl;
                                if (BetComeBool) {
                                    updateComeBetVariables(BetCome, dice, Come4, Come5, Come6, Come8, Come9, Come10);
                                    BetCome = " ";
                                }
                                if (BetDontComeBool) {
                                    updateDontComeBetVariables(BetDontCome, dice, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
                                    BetDontCome = " ";
                                }
                            }
                        } 
                        if (PointStatus == 1) {
                            // Resolve established point for Come/Don't Come
                            if (dice == 7) {
                                if (BetDontComeBool) {
                                    balance += CurrentBetDontCome * 2;
                                    cout << "You win! Don't Come Line pays out." << endl;
                                } else if (BetComeBool) {
                                    cout << "You lose! Come Line loses." << endl;
                                }
                                PointStatus = 0;
                                BetComeBool = BetDontComeBool = false;
                                CurrentBetCome = CurrentBetDontCome = 0;
                                BetCome = BetDontCome = " ";
                                updateComeBetVariables(" ", 0, Come4, Come5, Come6, Come8, Come9, Come10);
                                updateDontComeBetVariables(" ", 0, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
                            } else if (dice == point) {
                                if (BetComeBool) {
                                    balance += CurrentBetCome * 2;
                                    cout << "You win! Come Line pays out." << endl;
                                } else if (BetDontComeBool) {
                                    cout << "You lose! Don't Come Line loses." << endl;
                                }
                                PointStatus = 0;
                                BetComeBool = BetDontComeBool = false;
                                CurrentBetCome = CurrentBetDontCome = 0;
                                BetCome = BetDontCome = " ";
                                updateComeBetVariables(" ", 0, Come4, Come5, Come6, Come8, Come9, Come10);
                                updateDontComeBetVariables(" ", 0, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
                            }
                            else {
                                // Roll doesn't resolve, point stays on
                                cout << "Roll doesn't resolve. Point remains On." << endl;
                            }
                        }
                    }
                    gameBoard(PuckStatusString, BetDontCome, BetCome, BetDontPass, BetPass, dice4, dice5, dice6, dice8, dice9, dice10, Come4, Come5, Come6, Come8, Come9, Come10, DCome4, DCome5, DCome6, DCome8, DCome9, DCome10);
                }
            }
            if (ComeMenuChoice == 4) {
                cout << "Thanks for playing!\n"<<endl;
                PlayingGame = false;
            }
        }
    }
}
