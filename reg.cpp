#include "reg.h"
#include <iostream>

using namespace std;

// Uses iostream:
bool Registration::input()
{
    cout << "Enter the access code: ";
    cin >> code;

    if (checkCode())
    {
        setRecord(true);
        return true;
    }
    else
    {
        setRecord(false);
        return false;
    }
}

void Registration::output()
{
    cout << "attend = " << attend << endl;
}

void Registration::setRecord(bool index)
{
    if (index)
        attend = "TRUE";
    else
        attend = "False";
}

bool Registration::checkCode()
{
    int accesscode = 123456;
    if (code == accesscode)
    {
        cout << "Register successfully.\n";
        return true;
    }
    else
    {
        return false;
    }
}

int Registration::getCode()
{
    return code;
}
