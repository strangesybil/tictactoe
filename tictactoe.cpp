
#include <iostream>
#include <limits> // flush the input buffer
using namespace std;

char board[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Checks game status
int checkwin() {
    // horizontal wins
    if (board[1] == board[2] && board[2] == board[3]) return 1;
    else if (board[4] == board[5] && board[5] == board[6]) return 1;
    else if (board[7] == board[8] && board[8] == board[9]) return 1;

    // vertical wins
    else if (board[1] == board[4] && board[4] == board[7]) return 1;
    else if (board[2] == board[5] && board[5] == board[8]) return 1;
    else if (board[3] == board[6] && board[6] == board[9]) return 1;

    // diagonal wins
    else if (board[1] == board[5] && board[5] == board[9]) return 1;
    else if (board[3] == board[5] && board[5] == board[7]) return 1;

    // are all the cells filled?
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' &&
             board[4] != '4' && board[5] != '5' && board[6] != '6' &&
             board[7] != '7' && board[8] != '8' && board[9] != '9') {
        return 0; // Draw
    }

    return -1; // Game still in progress
}

// Function to display the game board
void squares() {
    cout << "Tic Tac Toe";
    cout << "Player 1 (X)  -  Player 2 (O)";

    cout << "     |     |     \n";
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "\n";
    cout << "     |     |     \n\n";
}

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        squares();
        player = (player % 2) ? 1 : 2; // conditional operator 
        // if player is odd, player becomes one 
        // if player is 0, player is 2

        cout << "Player " << player << ", enter a number (1-9): ";
        cin >> choice; // which square does the player choose this turn

        // Validate input: check if input failed (non-number)
        if(cin.fail()) {
            cin.clear(); // clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "INVALID INPUT! Please enter a number between 1 and 9.\n";
            cin.get(); // wait for user to press enter
            player--; // repeat the same player's turn
            continue;
        }

        mark = (player == 1) ? 'X' : 'O';
        // if player is 1, mark is 'X', if 2, mark is 'O'

        // Check if the chosen cell is available
        if (choice >= 1 && choice <= 9 && board[choice] == ('0' + choice)) {
            board[choice] = mark;
        } else {
            cout << "INVALID MOVE! Cell already taken or invalid number.";
            cin.get(); // wait for user to read message
            player--; // repeat turn for same player 
        }

        i = checkwin();
        player++; // move to next player
    } while (i == -1);

    squares();
    if (i == 1) { // the game is over 
        cout << "CONGRATULATIONS! PLAYER " << --player << " WINS!\n"; // display no. of user who won
    } else {
        cout << "GAME DRAW!\n";
    }

    cin.ignore();
    cin.get();
    return 0;
}
