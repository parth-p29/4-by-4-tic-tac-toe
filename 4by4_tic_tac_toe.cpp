
//Project: 4 by 4 Tic Tac Toe

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool play_again() {

    string user_choice = " ";
    while (user_choice != "Y" && user_choice != "N") {     //Continues asking user for input until a valid one is chosen

        cout << "Do you want to play again (Y or N)? \n";   
        cin >> user_choice;

    }

    if (user_choice == "Y") {
        return true;                      //returns boolean based on player choice
    }

    else {
        return false;
    }
}

bool is_tie(string game_board[][4]) {     
    int tie = false;

    for (int row = 0; row < 4; row++) {    

        for (int col = 0; col < 4; col++) {

            if (game_board[row][col] == "X" || game_board[row][col] == "O") {               //goes through all the rows and columns of the game board and checks if it is all covered with X's and O's. IF so it is a tie
                tie = true; 
            }

            else {
                return false;    //returns false if there is still one spot which doesnt have an X or an O
            }
        }
    }

    return tie;   //it will return the tie boolean variable which represents true - tie or false - not a tie
}

void reset_game(string game_board[][4]) {    

    cout << "\n";
    for (int row = 0; row < 4; row++) {      //goes through the game board changing each element back to the original

        for (int col = 0; col < 4; col++) {

            game_board[row][col] = to_string((col + 1) + 4 * row); //We developed this formula to return the board to the original, without any X's or O's
            cout << game_board[row][col] << setw(10);  
        } 

        cout << "\n \n"; 
    }
}

string check_rows(string board[][4]) {    //checks the horizontal win condiition to see if a player has won

    for (int row = 0; row < 4; row++) {

        for (int col = 0; col < 4; col++) {

            if (board[row][0] == "X" && board[row][1] == "X" && board[row][2] == "X" && board[row][3] == "X") {     //checks if an entire row is "X." If so, it will return X to indicate X has won

                return "X";
            }

            if (board[row][0] == "O" && board[row][1] == "O" && board[row][2] == "O" && board[row][3] == "O") {   //Checks if an entire row is "O." If so, it will return O to indicate O has won

                return "O";
            }

        }

    }

    return "no win";  //default return if no one has won yet
}

string check_columns(string board[][4]) {

    for (int col = 0; col < 4; col++) {

        for (int row = 0; row < 4; row++) {

            if (board[0][col] == "X" && board[1][col] == "X" && board[2][col] == "X" && board[3][col] == "X") {   //Checks if an entire column is "X." If so, it will return X to indicate X has won

                return "X";
            }

            if (board[0][col] == "O" && board[1][col] == "O" && board[2][col] == "O" && board[3][col] == "O") { //Checks if an entire column is "O." If so, it will return O to indicate O has won

                return "O";
            }

        }

    }

    return "no win";
}

string check_diagonals(string board[][4]) {

    if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X" && board[3][3] == "X") {    
        return "X";
    }

    else if (board[0][3] == "X" && board[1][2] == "X" && board[2][1] == "X" && board[3][0] == "X") {
        return "X";
    }
                                                                                                         //Checks both diagonals to see if there is a winner for X or O. If there is, it will return the winner
    else if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O" && board[3][3] == "O") {
        return "O";
    }

    else if (board[0][3] == "O" && board[1][2] == "O" && board[2][1] == "O" && board[3][0] == "O") {
        return "O";
    }

    else {

        return "no win";

    }
}

void output_board(string board[][4]) {

    cout << "\n";

    for (int row = 0; row < 4; row++) {

        for (int col = 0; col < 4; col++) {

            cout << board[row][col] << setw(10);     //goes through the entire board - all the rows and columns to output the board to the user. Uses setw to format the board nicely.

        }

        cout << "\n \n";

    }

}

void update_board(string board[][4], string player_placement, string& player_type) {   //inputs 2 additional variables: Player placement is the string which represents where the player wants their spot.
                                                                                        //Player type is whether the player is "X" or "O" - passed by reference to change whose turn it is
    for (int row = 0; row < 4; row++) {

        for (int col = 0; col < 4; col++) {

            if (player_placement == board[row][col]) {    //goes through each element in the board to see if the player's placement matches the element on the board.

                board[row][col] = player_type;  //If it does, it will replace that element with the players type(X or O)

            }

        }
    }

    if (player_type == "X") {
        player_type = "O";            //if the current turn is X, it will switch to O. Vice versa. This is so that the turns always change after each move
    }

    else {

        player_type = "X";    
    }

}

void run_tic_tac_toe() {

    //variable declarations
    string game_board[4][4] = { {"1", "2", "3" , "4"},
                              {"5", "6", "7", "8"},
                              {"9", "10", "11", "12"},           //The game board is a string array which will contain all the places the player can place their X or O
                              {"13", "14", "15", "16"} };

    string current_turn = "X";   //represents whose turn it is to play. Starts with X
    int player_x_wins = 0;                    
    int player_o_wins = 0;   //variables hold the score of each player
    int ties = 0; 
    bool run_game = true;

    cout << "\nWelcome to 4 by 4 Tic Tac Toe! \n ";

    while (run_game) {   //main game loop 

        output_board(game_board);   //outputs the game board to the players

        if (is_tie(game_board)) {
               
            ties++;
            cout << "Game is a tie! \n";    //checks if the game was a tie. 
            if (play_again()) {

                reset_game(game_board);   //if the game was a tie it will ask the user if they want to play again. If they do, it will reset game
            }

            else {
                break; //breaks out of loop if user does not want to play again
            }

        }

        if (check_rows(game_board) == "X" || check_columns(game_board) == "X" || check_diagonals(game_board) == "X") {   //checks if the X player has won - checks all the rows, columns and diagonals

            cout << "X wins \n";  //outputs that X has won
            player_x_wins++;

            if (play_again()) {  //asks if they want to play again

                reset_game(game_board);  //resets game if they say Yes
            }

            else {
                break; //breaks out of loop otherwise
            }

        }

        if (check_rows(game_board) == "O" || check_columns(game_board) == "O" || check_diagonals(game_board) == "O") {   //checks if O has won

            cout << "O wins \n";  //output for O winning
            player_o_wins++;

            if (play_again()) {  //asks user if they wanna play again

                reset_game(game_board); //resets the game board
            }

            else {

                break;
            }

        }

        int player_choice = 0;
        while (player_choice <= 0 || player_choice >= 17) {    //keeps asking user unil a valid choice between 1 and 16 is inputted

            cout << "Pick a number: ";
            cin >> player_choice;   

        }

        update_board(game_board, to_string(player_choice), current_turn);   //updates the board based on the player's input

    }

    cout << "player X Wins: " << player_x_wins << "\n";
    cout << "Player O Wins: " << player_o_wins << "\n";   //outputs the score of each player
    cout << "Number of Ties: " << ties << "\n"; //outputs the number of ties

}

int main() {

    run_tic_tac_toe();  //runs the tic tac toe game
}