//
//  connectfour.cpp
//  Connect Four Game
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Modified by Salma Emara and Ethan Hugh on 2023-09-06
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <iostream>
#include <string>
using namespace std;

#include "GameState.h"
#include "globals.h"

// Function prototypes

// The main function
int main() {
  /**********************************************************************************/
  /* Create three initialized game state objects in an array */
  /**********************************************************************************/
  const int numOfRounds = 3;
  GameState game_state[numOfRounds];

  // Read one integer from the user that represents the column
  // the player would like to place their piece (R or Y) in
  // You can assume there will be no formatting errors in the input

  int col;
  int round = 0;
  int redPoints = 0;
  int yellowPoints = 0;
  bool newRound = true;
  while (!game_state[round].get_gameOver() && round < 3) {
    if(newRound){
      cout << "Game " << round + 1 << endl;
      newRound = false;
    }
    cout << endl << "Enter column to place piece: ";
    cin >> col;
    if(col >= 0 && col < boardSize && game_state[round].get_gameBoard(boardSize - 1, col) == Empty){
      cout << "column chosen: " << col << endl;
    }
 
    if( cin.eof() ) {
      cerr << endl << "Game ended by user." << endl ;
      exit( 0 ) ;
    }
    if( cin.fail() ) {
      cin.clear() ;
      cin.ignore( 1000, '\n' ) ;
      col = -1 ; // giving col invalid value so it will be handled as invalid input below
    }
  
    // Check validity of input and if not valid, handle accordingly
    while(col < 0 || col > boardSize || game_state[round].get_gameBoard(boardSize - 1, col) != Empty){
      game_state[round].set_moveValid(false);
      cin.clear();
      cout << "Invalid column!" << endl;
      cout << "Enter column to place piece: ";
      cin >> col;
      if(col >= 0 && col < boardSize){
        game_state[round].set_moveValid(true);
      }
      cout << "column chosen: " << col << endl;
    }
    // The coordinates are valid; set the selectedRow and selectedColumn
    // members of the game state to the read values
    // Note that the corresponding mutators of GameState must be first
    // implemented before this works
    game_state[round].set_selectedColumn(col);
    if(game_state[round].get_gameBoard(boardSize, col) == Empty){
      int cRow = 5;
      while((game_state[round].get_gameBoard(cRow, col) == Empty) && cRow > 0){
        cRow--;
      }
      if(cRow == 0 && game_state[round].get_gameBoard(0, col) == Empty){
        game_state[round].set_selectedRow(0);
      }else{
        game_state[round].set_selectedRow(cRow + 1);
      }
    }
    
    // Call playMove
    playMove(game_state[round]);

    // Print the GameState object, as prescribed in the handout
    for(int rowP = 6; rowP >= 0; rowP--){
      for(int colP = 0; colP < boardSize; colP++){
        if(game_state[round].get_gameBoard(rowP, colP) == Empty){
          cout << "_";
        }else if(game_state[round].get_gameBoard(rowP, colP) == R){
          cout << "R";
        }else if(game_state[round].get_gameBoard(rowP, colP) == Y){
          cout << "Y";
        }
      }
      cout << endl;
    }

    // Check if a player won this round and if so handle accordingly
    int turnNum;
    if(game_state[round].get_turn() == true){
      turnNum = -1;
    }else{
      turnNum = 1;
    }
    // first check vertical
    int count = 0;

    // checking upwards
    int tempRow = game_state[round].get_selectedRow();
    while(game_state[round].get_gameBoard(tempRow, col) == turnNum && tempRow < boardSize && tempRow >= 0){
      count++;
      tempRow++;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }
        
        break;
      }
    }

    // checking downwards
    tempRow = game_state[round].get_selectedRow() - 1;
    while(game_state[round].get_gameBoard(tempRow, col) == turnNum && tempRow < boardSize && tempRow >= 0){
      count++;
      tempRow--;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }
      }
    }

    count = 0;
    // checking left
    tempRow = game_state[round].get_selectedRow();
    int tempCol = game_state[round].get_selectedColumn();
    while(game_state[round].get_gameBoard(tempRow, tempCol) == turnNum && tempCol < boardSize && tempCol >= 0){
      count++;
      tempCol--;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }
      }
    }

    // checking right
    tempCol = game_state[round].get_selectedColumn() + 1;
    while(game_state[round].get_gameBoard(tempRow, tempCol) == turnNum && tempCol < boardSize && tempCol >= 0){
      count++;
      tempCol++;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }
      }
    }
    
    count = 0;
    // checking NE
    tempRow = game_state[round].get_selectedRow();
    tempCol = game_state[round].get_selectedColumn();
    while(game_state[round].get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol++;
      tempRow++;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }
      }
    }
    
    // checking SW
    tempRow = game_state[round].get_selectedRow() - 1;
    tempCol = game_state[round].get_selectedColumn() - 1;
    while(game_state[round].get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol--;
      tempRow--;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }

      }
    }
    
    count = 0;
    // checking NW
    tempRow = game_state[round].get_selectedRow();
    tempCol = game_state[round].get_selectedColumn();
    while(game_state[round].get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol--;
      tempRow++;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }

      }
    }

    // checking SE
    tempRow = game_state[round].get_selectedRow() - 1;
    tempCol = game_state[round].get_selectedColumn() + 1;
    while(game_state[round].get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol++;
      tempRow--;
      if(count == 4){
        game_state[round].set_gameOver(true);
        if(game_state[round].get_turn() == false){
          cout << endl << "R won this round!" << endl;
          newRound = true;
          redPoints++;
          round++;
        }else{
          cout << endl << "Y won this round!" << endl;
          newRound = true;
          yellowPoints++;
          round++;
        }

      }
    }



    // Check if a player won this match and if so handle accordingly
    if(round == 2){
      if(redPoints > yellowPoints){
        cout << "R won the match!";
        return 0;
      }else if(yellowPoints > redPoints){
        cout << "Y won the match";
        return 0;
      }
    }
    if(round == 3){
      if(redPoints > yellowPoints){
        cout << "R won the match!";
        return 0;
      }else if(yellowPoints > redPoints){
        cout << "Y won the match";
        return 0;
      }else{
        cout << "Tie!";
        return 0;
      }
    }
  }
}
  
