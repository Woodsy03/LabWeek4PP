#include "reg.h"
#include <iostream>

using namespace std;

int main()
{
    Registration myCode;
    cout << "Registration:\n";
    if (myCode.input())
    {
        cout << "The input code is " << myCode.getCode() << "\n";
        cout << "The system has been updated with ";
        myCode.output();
    }
    else
    {
        cout << "Your input code " << myCode.getCode() << " doesn't match the access code\n";
        cout << "Register unsuccessfully. \n";
    }
    return 0;
}
