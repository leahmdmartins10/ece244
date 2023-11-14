//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;
bool firstCall = true;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

int main() {
    string line;
    string command;

    string name; string type;
    int xloc; int yloc; int xsize; int ysize; int angle;
    
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input
    int numShapes = 0;
    int indexOfArray = 0;

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;
        

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        for(int i = 0; i < NUM_KEYWORDS; i++){
            if(command == keyWordsList[i]){
                if(keyWordsList[i] == "all"){
                    cout << "Error: invalid command" << endl;
                    break;
                }else if(keyWordsList[i] == "maxShapes"){
                    if(firstCall){
                        if(lineStream.eof()){
                            cout << "Error: too few arguments" << endl;
                            break;
                        }

                        lineStream >> numShapes;
                        lineStream.ignore(10000000, ' ');
                        if(lineStream.fail()){
                            cout << "Error: invalid argument" << endl;
                            lineStream.clear();
                            break;
                        }
                        if(lineStream.eof() != true){
                            if(lineStream.peek() == '.'){
                                cout << "Error: invalid argument" << endl;
                                break;
                            }

                            cout << "Error: too many arguments" << endl;
                            break;
                        }

                        if(numShapes <= 0){
                            cout << "Error: invalid value" << endl;
                            break;
                        }
                        firstCall = false;
                        cout << "New database: max shapes is " << numShapes << endl;
                        shapesArray = new Shape*[numShapes];
                        break;
                    }else if(firstCall == false){
                        for(int j = 0; j < indexOfArray; j++){
                            delete shapesArray[j];
                            shapesArray[j] = NULL;
                        }
                        delete[] shapesArray;
                        shapesArray = NULL;

                        numShapes = 0;
                        if(lineStream.eof()){
                            cout << "Error: too few arguments" << endl;
                            break;
                        }
                        lineStream >> numShapes;
                        if(lineStream.fail()){
                            cout << "Error: invalid argument" << endl;
                            lineStream.clear();
                            break;
                        }
                        if(lineStream.eof() != true){
                            if(lineStream.peek() == '.'){
                                cout << "Error: invalid argument" << endl;
                                break;
                            }

                            cout << "Error: too many arguments" << endl;
                            break;
                        }

                        if(numShapes <= 0){
                            cout << "Error: invalid value" << endl;
                            break;
                        }
                        firstCall = false;
                        cout << "New database: " << command << " is " << numShapes << endl;
                        shapesArray = new Shape*[numShapes];
                        break;
                    }

                }else if(keyWordsList[i] == "create"){
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    // checking for valid inputs
                    lineStream >> name;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }

                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    bool invalid = false;
                    for(int k = 0; k < NUM_KEYWORDS; k++){
                        if(name == keyWordsList[k]){
                            cout << "Error: invalid shape name" << endl;
                            invalid = true;
                            break;
                        }
                    }
                    if(invalid){
                        break;
                    }

                    // checking if shape is already created
                    if(indexOfArray != 0){
                        for(int k = 0; k < indexOfArray; k++){
                            if(shapesArray[k] != NULL){
                                if(shapesArray[k]->getName() == name){
                                    cout << "Error: shape " << name << " already exists" << endl;
                                    break;
                                }
                            }
                        }
                    }
                    
                    lineStream >> type;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }                    
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    lineStream >> xloc;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    lineStream >> yloc;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    lineStream >> xsize;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        lineStream.clear();
                        break;
                    }
                    lineStream >> ysize;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }
                    
                    // checking if shapeArray is full
                    if(indexOfArray >= numShapes){
                        cout << "Error: shape array is full" << endl;
                        break;
                    }
                    // checking for too many arguments
                    if(lineStream.eof() != true){
                        cout << "Error: too many arguments" << endl;
                        break;
                    }
                    // case if the locations or sizes are negative
                    if(xloc < 0 || yloc < 0 || xsize < 0 || ysize < 0){
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    // case if circle is not symmetrical
                    if(type == "circle" && (xsize != ysize)){
                        cout << "Error: invalid value" << endl;
                        break;
                    }

                    for(int j = 0; j < NUM_TYPES; j++){
                        if(type == shapeTypesList[j]){
                            shapesArray[indexOfArray] = new Shape(name, type, xloc, xsize, yloc, ysize);

                            cout << "Created " << name << ": " << type << " " << xloc << " " << yloc << " " << xsize << " " << ysize << endl;
                            indexOfArray++;
                            break;
                        }else if((j+1) == NUM_TYPES && type != shapeTypesList[j]){
                            cout << "Error: invalid shape type" << endl;
                            break;
                        }
                    }
                    break;
                
                }else if(keyWordsList[i] == "move"){
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    lineStream >> name;
                    bool found = false;
                    for(int j = 0; j < numShapes; j++){
                        if(shapesArray[j] != NULL && shapesArray[j]->getName() != name){
                            found = false;
                            continue;
                        }else if(shapesArray[j] != NULL && shapesArray[j]->getName() == name){
                            found = true;
                            break;
                        }
                    }
                    if(found == false){
                        cout << "Error: shape " << name << " not found" << endl;
                        break;
                    }
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }

                    int newXloc; int newYloc;
                    lineStream >> newXloc;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }

                    lineStream >> newYloc;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }

                    // checking for too many arguments
                    if(lineStream.eof() != true){
                        cout << "Error: too many arguments" << endl;
                        break;
                    }
                    // checking locations
                    if(newXloc < 0 || newYloc < 0){
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    // checking for name                 
                    for(int j = 0; j < indexOfArray; j++){
                        if(shapesArray[j] != NULL){
                            if(shapesArray[j]->getName() == name){
                                shapesArray[j]->setXlocation(newXloc);
                                shapesArray[j]->setYlocation(newYloc);
                                cout << "Moved " << name << " to " << newXloc << " " << newYloc << endl;
                                break;
                            }
                            if(shapesArray[j]->getName() != name && (j+1) == indexOfArray){
                                cout << "Error: shape "<< name <<" not found" << endl;
                                break;
                            }
                        }
                    }

                    break;
                }else if(keyWordsList[i] == "rotate"){
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;

                    }
                    lineStream >> name;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }

                    bool found = false;
                    for(int j = 0; j < numShapes; j++){
                        if(shapesArray[j] != NULL && shapesArray[j]->getName() != name){
                            found = false;
                            continue;
                        }else if(shapesArray[j] != NULL && shapesArray[j]->getName() == name){
                            found = true;
                            break;
                        }
                    }
                    if(found == false){
                        cout << "Error: shape " << name << " not found" << endl;
                        break;
                    }
                    if(lineStream.eof()){
                        cout << "Error: too few arguments " << endl;
                        break;
                    }

                    lineStream >> angle;
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.peek() == '.'){
                        cout << "Error: invalid argument" << endl;
                        break;
                    }

                    // checking for too many arguments
                    if(lineStream.eof() != true){
                        cout << "Error: too many arguments" << endl;
                        break;
                    }
                    // checking to see if angle is between 0 and 360
                    if(angle < 0 || angle > 360){
                        cout << "Error: invalid value" << endl;
                        break;
                    }
                    for(int j = 0; j < indexOfArray; j++){
                        if(shapesArray[j] != NULL){
                            if(shapesArray[j]->getName() == name){
                                shapesArray[j]->setRotate(angle);
                                cout << "Rotated " << name << " by " << angle << " degrees" << endl;
                                break;
                            }
                            if(shapesArray[j]->getName() != name && (j+1) == indexOfArray){
                                cout << "Error: shape "<< name << " not found" << endl;
                                break;
                            }
                        }
                    }
                    break;
                }else if(keyWordsList[i] == "draw"){
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    lineStream >> name;
                    bool found = false;
                    for(int j = 0; j < numShapes; j++){
                        if(shapesArray[j] != NULL && shapesArray[j]->getName() != name && name != "all"){
                            found = false;
                            continue;
                        }else if((shapesArray[j] != NULL) && (shapesArray[j]->getName() == name) || (name == "all")){
                            found = true;
                            break;
                        }
                    }
                    if(found == false){
                        cout << "Error: shape " << name << " not found" << endl;
                        break;
                    }  
                    if(lineStream.eof() != true){
                        cout << "Error: too many arguments" << endl;
                        break;
                    }
                 
                    if(name == "all"){
                        cout << "Drew all shapes " << endl;
                        for(int j = 0; j < indexOfArray; j++){
                            if(shapesArray[j] != NULL){
                                cout << shapesArray[j]->getName() << ": " << shapesArray[j]->getType() << " " << shapesArray[j]->getXlocation() << " " << shapesArray[j]->getYlocation() << " " << shapesArray[j]->getXsize() << " " << shapesArray[j]->getYsize() << " ";
                            }
                        }
                        cout << endl;
                    }else{
                        for(int j = 0; j < indexOfArray; j++){
                            if(shapesArray[j] != NULL){
                                if(shapesArray[j]->getName() == name){
                                    cout << "Drew " << name << ": " << shapesArray[j]->getType() << " " << shapesArray[j]->getXlocation() << " " << shapesArray[j]->getYlocation() << " " << shapesArray[j]->getXsize() << " " << shapesArray[j]->getYsize() << endl;
                                }else if(shapesArray[j]->getName() != name && (j+1) == indexOfArray){
                                    cout << "Error: shape " << name << " not found " << endl;
                                    break;
                                }                                
                            }
                        }
                    }
                    break;

                }else if(keyWordsList[i] == "delete"){
                    if(lineStream.eof()){
                        cout << "Error: too few arguments" << endl;
                        break;
                    }
                    lineStream >> name;
                    bool found = false;
                    for(int j = 0; j < numShapes; j++){
                        if(shapesArray[j] != NULL && shapesArray[j]->getName() != name && name != "all"){
                            found = false;
                            continue;
                        }else if((shapesArray[j] != NULL) && (shapesArray[j]->getName() == name) || (name == "all")){
                            found = true;
                            break;
                        }
                    }
                    if(found == false){
                        cout << "Error: shape " << name << " not found" << endl;
                        break;
                    }   
                    if(lineStream.fail()){
                        cout << "Error: invalid argument" << endl;
                        lineStream.clear();
                        break;
                    }
                    if(lineStream.eof() != true){
                        cout << "Error: too many arguments" << endl;
                        break;
                    }                
                    if(name == "all"){
                        if(shapesArray != NULL){
                            cout << "Deleted: all shapes " << endl;
                            for(int j = 0; j < numShapes; j++){
                                delete shapesArray[j];
                                shapesArray[j] = NULL;
                            }
                            
                            delete[] shapesArray;
                            shapesArray = NULL;

                            indexOfArray = 0;
                            break;
                        }else{
                            cout << "Deleted: all shapes " << endl;
                        }
                    }else{
                        for(int j = 0; j < indexOfArray; j++){
                            if(shapesArray[j]->getName() == name){
                                cout << "Deleted shape " << shapesArray[j]->getName() << endl;
                                delete shapesArray[j];
                                shapesArray[j] = NULL;
                                break;
                            }else if(shapesArray[j]->getName() != name && (j+1) == indexOfArray){
                                cout << "Error: shape " << name << " not found " << endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            
            }else if((i+1) == NUM_KEYWORDS && command != keyWordsList[i]){
                cout << "Error: invalid command" << endl;
            }
        }

        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

