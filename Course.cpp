//
// Created by Yannick Fumukani on 6/21/22.
//

#include "headers/Course.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

Course::Course(const string &code, const string &name) {
    this->code = code;
    this->name = name;
}

void Course::addPrereq(const string &prereq) {
    this->prereq.push_back(prereq);
}

string Course::getCode() const {
    return this->code;
}

vector<string> Course::getPrereq() const {
    return this->prereq;
}

void Course::setCode(const string &code) {
    Course::code = code;
}

string Course::getName() const {
    return this->name;
}

void Course::setName(const string &name) {
    Course::name = name;
}

Course::~Course() {
    //  delete (this);
}

