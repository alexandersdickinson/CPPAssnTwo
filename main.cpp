//
//  main.cpp
//  StudentGradingSystem
//
//  Created by Alex Dickinson on 15.02.16.
//  Copyright © 2016 Alex Dickinson. All rights reserved.
//  This program takes points scored for CS11, CS12, and CS21. Out of a total of 300 points, it displays the
//  points accrued by the student and their letter grade along with basic information about the student.

#include <iostream>
using std::cout;
using std::cin;
using std::string;

//This function takes a string and makes sure it only contains digits.
string stringValidator(string desiredChars, string inputMsg);

int main(int argc, const char * argv[]) {
    string id;
    string lastName;
    string firstName;
    string points;
    double pointsMath;//used for calculating percentage.
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
    firstName = stringValidator("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", "first name");
    points = stringValidator("1234567890.", "points");
    pointsMath = stod(points);
    percentage = (pointsMath / 300) * 100;
    
    cout << "ID: " << id << std::endl;
    cout << "Last Name: " << lastName << std::endl;
    cout << "First Name " << firstName << std::endl;
    cout << "Points out of 300: " << pointsMath << std::endl;
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
 This function takes a string and makes sure it only contains digits. DesiredChars is a string representing
 a set of desired characters, which is passed to find_first_not_of. InputMsg is what the user is being asked
 to input (ex. user ID).
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