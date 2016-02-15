//
//  main.cpp
//  StudentGradingSystem
//
//  Created by Alex Dickinson on 15.02.16.
//  Copyright © 2016 Alex Dickinson. All rights reserved.
//  This program takes points scored for CS11, CS12, and CS21. Out of a total of 300 points, it displays the
//  points accrued by the student and their letter grade along with basic information about the student.

#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::string;

//This function takes a string and makes sure it only desired characters.
string stringValidator(string desiredChars, string inputMsg);
//This takes a string and makes sure it contains digits and lies between 0 and 300.
double pointValidator();

int main(int argc, const char * argv[]) {
    string id;
    string lastName;
    string firstName;
    double points;//used for calculating percentage.
    double percentage;//used for calculating letter grade.
    char grade;
    string gradeCommentary;//gives student advice or encouragement based on their letter grade.
    
    cout << "==============================================================\n";
    cout << "Student Grading System (SGS)\n";
    cout << "Long Beach City College\n";
    cout << "Author: Alex Dickinson\n";
    cout << "Feb. 15, 2016\n";
    cout << "==============================================================\n";
    cout << "Welcome to the Student Grading System.\n";
    
    id = stringValidator("1234567890", "ID");
    lastName = stringValidator("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", "last name");
    for(int i = 0; i < lastName.length(); i++){//capitalizes last name.
        lastName[i] = tolower(lastName[i]);
    }
    lastName[0] = toupper(lastName[0]);
    
    firstName = stringValidator("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", "first name");
    for(int i = 0; i < firstName.length(); i++){//capitalizes first name.
        firstName[i] = tolower(firstName[i]);
    }
    firstName[0] = toupper(firstName[0]);
    
    points = pointValidator();
    percentage = (points / 300) * 100;
    
    cout << "ID: " << id << std::endl;
    cout << "Last Name: " << lastName << std::endl;
    cout << "First Name " << firstName << std::endl;
    cout << "Points out of 300: " << points << std::endl;
    cout << "Percentage: " << percentage << std::endl;
    
    if (percentage >= 90) {
        grade = 'A';
        gradeCommentary = "You have a bright future!";
    }
    else if (percentage >= 80) {
        grade = 'B';
        gradeCommentary = "You have great potential. Keep trying!";
    }
    else if (percentage >= 70) {
        grade = 'C';
        gradeCommentary = "Your lack of effort shows. You can do better than this.";
    }
    else if (percentage >= 60) {
        grade = 'D';
        gradeCommentary = "You are on the edge. Apply yourself.";
    }
    else{
        grade = 'F';
        gradeCommentary = "You have failed. You should go into the liberal arts.";
    }
    
    cout << "Your Letter Grade: " << grade << std::endl;
    cout << gradeCommentary << std::endl;
    
    return 0;
}

/*
 This function takes a string and makes sure it only contains characters in desiredChars. InputMsg is what
 the user is being asked to input (ex. user ID).
 Postcondition: Input is returned if all characters are digits. The user is repeatedly asked for input if any
 non-digit characters are found.
 */
string stringValidator(string desiredChars, string inputMsg){
    string input;
    
    while (true) { //input validation loop
        //Tells the user that they need to input a certain value.
        cout << "Please enter your " << inputMsg << ":\n";
        getline(cin >> std::ws, input);
        if (input.find_first_not_of(desiredChars) != string::npos) {
            //Tells the user that input has failed and that they must try again.
            cout << "The entered " << inputMsg << " is invalid\n";
            continue;
        }
        else{
            return input;
        }
    }
}

/*
 This takes a string and makes sure it is a numerical value.
 It also checks whether it lies between 0 and 300.
*/
double pointValidator(){
    string input;
    double inputMath;
    
    while (true) { //input validation loop
        //Tells the user that they need to input a certain value.
        cout << "Please enter total points accrued in CS11, 12, and 21:\n";
        getline(cin >> std::ws, input);
        if (input.find_first_not_of("1234567890") == string::npos) {
            inputMath = stod(input);
            if (inputMath > 300) {//automatically assigns points to 300 if they exceed 300.
                inputMath = 300;
            }
            else if(inputMath < 0) {//automatically assigns points to 0 if they are less than 0.
                inputMath = 0;
            }
            return inputMath;
        }
        else{
            cout << "The points entered are in an invalid format.\n";
            continue;
        }
    }
}