#pragma once
#ifndef REG_H
#define REG_H

#include <string>

class Registration
{
public:
    bool input();
    void output();
    void setRecord(bool index);
    int getCode();
    // Returns the input code

private:
    bool checkCode(); // to check the input matches the access code
    int code;
    std::string attend;
};

#endif // REG_H
