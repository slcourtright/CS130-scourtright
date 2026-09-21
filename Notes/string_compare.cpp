#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2, str3;

    cout << "Enter 1st string: ";
    getline(cin, str1);

    cout << "Enter 2nd string: ";
    getline(cin, str2);

    cout << "Enter 3rd string: ";
    getline(cin, str3);

    if(str1 > str2 and str1 > str3) //str1 wins, is the biggest
    {
        cout <<"str1 is greater than str2 and str3: " << str1 << " > " << str2 << " and " << str3 << endl;
        if(str2 > str3)
        {

        }
        else if(str2 > str3)
    }
    else if(str1 < str2)
    {
        cout << "str1 is less than str2 " << str1 << " < " << str2 << endl;
    }
    else
    {
        cout << "str1 is equal to str2 " << str1 << " = " << str2 << endl;
    }
}