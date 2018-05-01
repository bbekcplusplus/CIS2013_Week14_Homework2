#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
// Studies Problem Solving with C++ (Course Book)
// Some online C++ books for example: Chegg (computer science learning materials)

class game {
private:
   string name;
   int score;

public:
   void set_name(){
       cout << "What is your name please? ";
       cin >> name;
   }
   void set_score() {
       score++;
   }
   void get_name() {
       cout << name;
   }
   void get_score() {
       cout << score;
   }
   int getRandom(int i)
   {
       return rand() % i;
   }

};

class mine_sweeper : public game {
private:
   int board_size;
   int board_rows;
   int board_columns;
   int numb_bombs;
   char *selected_squares;
   char *bomb_squares;
   int xGuess = 0;
   int yGuess = 0;
   int test_for_bomb;


public:
   bool keep_alive = true;

   //get name, board size, number of mines;
   void get_board() {
       cin >> board_rows;
       cin >> board_columns;
       cin >> numb_bombs;
       board_size = board_columns * board_rows;
   }

   //randomly set the selected number of bombs in the board
   void set_bombs() {
       selected_squares = new char[board_size];
       bomb_squares = new char[board_size];

       for (int i = 0; i < numb_bombs; i++) {
           bomb_squares[getRandom(board_size)] = 'X';
       }

       //for (int i = 0; i < board_size; i++) { //print test for random bombs // will comment out later
       //   if (bomb_squares[i] == 'X') {
       //       cout << 'X';
       //   }
       //   else {
       //       cout << '0';
       //   }
       //}
   }

   //Print an empty board
   void print_board() {

       for (int x = 0; x < board_rows; x++) {
           cout << x;
           if (x < 10) {
               cout << " ";
           };
       }
       cout << endl << "       ";
       for (int x = 0; x < board_rows; x++) {
           cout << "__";
       }
       cout << endl;
       for (int y = 0; y<board_columns; y++) {
           cout << "    " << y;
           if (y < 10) {
               cout << " ";
           }
           cout << "| ";
           for (int x = 0; x < board_rows; x++) {
               if (keep_alive == false) {
                   if (selected_squares[x + (board_rows * y)] == 'b') {
                       cout << "@ ";
                   }
                   else if (bomb_squares[x + (board_rows * y)] == 'X') {
                       cout << "X ";
                   }
                   else if (selected_squares[x + (board_rows * y)] == 'y') {
                       cout << "O ";
                   }
                   else {
                       cout << ". ";
                   }
               }
               else {
                   if (selected_squares[x + (board_rows * y)] == 'y') {
                       cout << "O ";
                   }
                   else {
                       cout << ". ";
                   }
               }
           }
           cout << endl;
       }

       if (keep_alive == false) {
           delete[] selected_squares;
           delete[] bomb_squares;
       }
   }

   //ask the user for input
   void get_square() {
       cin >> xGuess;
       cin >> yGuess;
       test_for_bomb = xGuess + (board_rows * yGuess); //interpret user x and y guesses as a spot in our dynamic array of random bombs
       if (bomb_squares[test_for_bomb] == 'X') {
           selected_squares[test_for_bomb] = 'b';
           keep_alive = false;
       }
       else {
           selected_squares[test_for_bomb] = 'y';
       }
   }
};

int main() {
   mine_sweeper m;
   srand(time(NULL));

   m.set_name();
   cout << endl << "HI! Let's set up your board, ";
   m.get_name();
   cout << endl << "Please type the width, then legnth, then number of bombs: " << endl;
   m.get_board();
   m.set_bombs();
   cout << endl << " Welcome to minesweeper! Yaay!" << endl;
   while (m.keep_alive == true) {
       cout << "please type your X and then Y coordinate of attack:" << endl;
       cout << endl << "        ";
       m.print_board();
       m.get_square();
       m.set_score();
   }
   m.print_board();
   cout << "        GAME OVER" << endl << "@ = bomb you picked. X = other bombs. O = your safe guesses." << endl;
   cout << "Final score for ";
   m.get_name();
   cout << ": ";
   m.get_score();
   cout << " points (total guesses).";
   int i;
   cin >> i;
   return 0;
}