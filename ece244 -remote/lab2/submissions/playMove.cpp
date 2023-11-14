//
//  playMove.cpp
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
//  ECE244 Student: write your code for playMove in this file

#include "GameState.h"
#include "globals.h"

// Function prototypes (if you need)

void playMove(GameState& game_state) {
  // Change turn if move is valid,
  // also updating the board
  if(!game_state.get_gameOver()){
    if(game_state.get_turn() == true){
      game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), 1);
    }else if(game_state.get_turn() == false){
      game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), -1);
    }
    if(game_state.get_moveValid()){
      game_state.set_turn(!game_state.get_turn());
    }
  }

  int turnNum;
    if(game_state.get_turn() == true){
      turnNum = -1;
    }else{
      turnNum = 1;
    }
    // first check vertical
    int count = 0;

    // checking upwards
    int tempRow = game_state.get_selectedRow();
    while(game_state.get_gameBoard(tempRow, game_state.get_selectedColumn()) == turnNum && tempRow < boardSize && tempRow >= 0){
      count++;
      tempRow++;
      if(count == 4){
        game_state.set_gameOver(true);
      }if(game_state.get_turn() == false){
        game_state.set_winner(1);
      }else{
        game_state.set_winner(-1);
      }
    }

    // checking downwards
    tempRow = game_state.get_selectedRow() - 1;
    while(game_state.get_gameBoard(tempRow, game_state.get_selectedColumn()) == turnNum && tempRow < boardSize && tempRow >= 0){
      count++;
      tempRow--;
      if(count == 4){
        game_state.set_gameOver(true);
        if(game_state.get_turn() == false){
          game_state.set_winner(1);
          }else{
          game_state.set_winner(-1);
          }
      }
    }

    count = 0;
    // checking left
    tempRow = game_state.get_selectedRow();
    int tempCol = game_state.get_selectedColumn();
    while(game_state.get_gameBoard(tempRow, tempCol) == turnNum && tempCol < boardSize && tempCol >= 0){
      count++;
      tempCol--;
      if(count == 4){
        game_state.set_gameOver(true);
        if(game_state.get_turn() == false){
          game_state.set_winner(1);
        }else{
          game_state.set_winner(-1);
        }
      }
    }

    // checking right
    tempCol = game_state.get_selectedColumn() + 1;
    while(game_state.get_gameBoard(tempRow, tempCol) == turnNum && tempCol < boardSize && tempCol >= 0){
      count++;
      tempCol++;
      if(count == 4){
        game_state.set_gameOver(true);
        if(game_state.get_turn() == false){
          game_state.set_winner(1);
        }else{
          game_state.set_winner(-1);
        }
      }
    }
    
    count = 0;
    // checking NE
    tempRow = game_state.get_selectedRow();
    tempCol = game_state.get_selectedColumn();
    while(game_state.get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol++;
      tempRow++;
      if(count == 4){
        game_state.set_gameOver(true);
        if(game_state.get_turn() == false){
          game_state.set_winner(1);
        }else{
          game_state.set_winner(-1);
        }
      }
    }
    
    // checking SW
    tempRow = game_state.get_selectedRow() - 1;
    tempCol = game_state.get_selectedColumn() - 1;
    while(game_state.get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol--;
      tempRow--;
      if(count == 4){
        game_state.set_gameOver(true);
        if(game_state.get_turn() == false){
          game_state.set_winner(1);
        }else{
          game_state.set_winner(-1);
        }
      }
    }
    
    count = 0;
    // checking NW
    tempRow = game_state.get_selectedRow();
    tempCol = game_state.get_selectedColumn();
    while(game_state.get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol--;
      tempRow++;
      if(count == 4){
        game_state.set_gameOver(true);
        if(game_state.get_turn() == false){
          game_state.set_winner(1);
        }else{
          game_state.set_winner(-1);
        }
      }
    }

    // checking SE
    tempRow = game_state.get_selectedRow() - 1;
    tempCol = game_state.get_selectedColumn() + 1;
    while(game_state.get_gameBoard(tempRow, tempCol) == turnNum && (tempCol < boardSize && tempCol >= 0) && (tempRow < boardSize && tempRow >= 0)){
      count++;
      tempCol++;
      tempRow--;
      if(count == 4){
        game_state.set_gameOver(true);
        if(game_state.get_turn() == false){
          game_state.set_winner(1);
        }else{
          game_state.set_winner(-1);
        }
      }
    }
}
