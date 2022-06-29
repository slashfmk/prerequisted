//
// Created by Yannick Fumukani on 6/21/22.
//

#include<iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <map>
#include "headers/Course.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;
using std::ifstream;
using std::map;
using std::stringstream;

// Prototype
int menu();
void loadData();
void printCourseList();
void courseDetails();

vector<string> splitString(const string &s);

// Global variables
map<string, Course> courseList;
ifstream inputData;

// Main func
int main() {

    int choice;

    cout << "Welcome to the course planner" << endl;

    do {

        choice = menu();

        switch (choice) {
            case 1:
                loadData();
                break;
            case 2:
                printCourseList();
                break;
            case 3:
                courseDetails();
                break;
            default:
                break;
        }

    } while (choice != 4);

    cout << "Thank you for using the course planner!" << endl;


    return 0;
}

// Main menu of the app
int menu() {

    int choice;

    do {
        cout << "" << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "4. Exit" << endl;
        cout << "What would you like to do? ";
        // get user choice
        cin >> choice;

        // check if it is a valid choice
        if (choice < 1 || choice > 4) {
            cout << choice << " is not a valid option." << endl;
            cout << "" << endl;
        }
        // As longer as the choice if greater than 4 or less the 1,
        // we are stuck in the loop
        // unless the provided value is between 1 - 4 (inclusive)
    } while (choice < 1 || choice > 4);

    // return the user choice
    return choice;
}

void loadData() {

    // Delete everything, so we can load new courses from the file
    courseList.clear();
    // select file to read
    inputData.open("courses.txt");

    // open the file
    if (inputData.is_open()) {
        string line;
        // iterate through a line at a time
        while (getline(inputData >> std::ws, line)) {
            // string split and stock in new vector
            vector<string> brokenString;
            // split line based on commas and assign them into the vector
            brokenString = splitString(line);
            // Insert into the map
            courseList.insert({brokenString.at(0),Course{brokenString.at(0), brokenString.at(1)}});
            // check if there are pre reqs
            // iterate and append pre reqs
            if (brokenString.size() > 2) {
                for (int i = 2; i < brokenString.size(); i++) {
                    courseList.at(brokenString.at(0)).addPrereq(brokenString.at(i));
                }
            }
        }
        // close the file to avoid potential errors
        inputData.close();
    } else {
        // display message if we can't open or locate the file
        cout << "Error: can't load courses file content\n" << endl;
    }

}

// string splitter
// split a string and retuns it as a vector of strings
vector<string> splitString(const string &s) {
    vector<string> v;

    stringstream ss(s);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    return v;
}

void printCourseList() {
    // print course list from the hashMap
    for (auto const &c: courseList) {
        cout << c.first << ", " << c.second.getName() << endl;
    }
}

void courseDetails() {

    string courseCode;

    cout << "What course do you want to know about? ";
    cin >> courseCode;

    char courseUpperCase[courseCode.length()];
    // convert to Uppercase
    for (int i = 0; i < courseCode.length(); i++) {
        courseUpperCase[i] = toupper(courseCode[i]);
    }

    courseCode = string(courseUpperCase);

    cout << courseList.at(courseCode).getCode() << ", " << courseList.at(courseCode).getName()<<endl;
    cout << "Prerequisites: "<<endl;
    // prints out pre req for this course
    if(!courseList.at(courseCode).getPrereq().empty()) {
        for(string lItem: courseList.at(courseCode).getPrereq()){
            cout<<lItem<<endl;
        }
    } else {
        cout<<"none"<<endl;
    }

}
