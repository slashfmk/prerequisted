//
// Created by Yannick Fumukani on 6/21/22.
//

#ifndef FINALPROJECT_COURSE_H
#define FINALPROJECT_COURSE_H

#include <string>
#include <vector>
#include <iostream>

//using namespace std;

using std::cin;
using std::cout;
using std::string;
using std::vector;

class Course {

private:
    // Attributes
    string code;
    string name;
    vector<string> prereq;

public:
    // the constructor
    Course(const string &code, const string &name);

    void addPrereq(const string &prereq);

    vector<string> getPrereq() const;

    string getCode() const;

    void setCode(const string &code);

    string getName() const;

    void setName(const string &name);

    ~Course();
};

#endif //FINALPROJECT_COURSE_H
