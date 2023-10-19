#include <iostream>
#include <limits>

using namespace std;

class Registration
{
public: 
    Registration();  // defines constructor (member function with the same name as a class)
    bool input();
    void output();
    void setRecord(bool index);
    int getCode();
private: // "hides" the "sensitive" information like codes from public class access
    bool checkCode();
    int code;
    string attend;
};

Registration::Registration() : code(-1) {}  // tells the constructor to initialise the code 

bool Registration::checkCode() // performs the initital check on whether the access code is valid. Futher debugging is done in Registration::input
{
    int accesscode = 123456;
    if (code == accesscode)
    {
        cout << "registered successfully.\n";
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Registration myCode;
    cout << "Registration:\n";
    if (myCode.input()) // pulls the code from the public class input. Would likely be better if it was private
    {
        cout << "The input code is " << myCode.getCode() << "\n";
        cout << "The system has been updated with ";
        myCode.output();
    }
    else if (myCode.getCode() == -1) // generic catch all for non int/ascii set charecters
    {
        cout << "that is not a valid numerical code";
    }
    else
    {
        cout << "Your input code " << myCode.getCode() << " doesn't match the access code\n"; // compares valid numerical responses if the other two selections are not met
        cout << "registration unsuccessful. \n";
    }
    return 0;
}

bool Registration::input()
{
    cout << "Enter the access code: ";
    cin >> code;

    if (cin.fail()) // acts as a catch all 
    {
        cin.clear(); // clears existing error flags
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // dumps any charecters before "\n" (ignores anything before the new line) to stop old data being mixed in  
        code = -1; // -1 representing a fully invalid result, allows it to skip processing later
        return false;
    }

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
        attend = "True";
    else
        attend = "False";
}

int Registration::getCode()
{
    return code;
}
