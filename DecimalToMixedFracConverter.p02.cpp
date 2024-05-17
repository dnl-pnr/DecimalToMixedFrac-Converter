
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int gcd(int a, int b)
{
    // Find Minimum of a and b 
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b 
    return result;
}

int main()
{
    bool run = true;
    bool negative;
    bool workOrNo = true;

    while (run == true) {

        //receive user number
        string number;
        cout << "Enter you decimal: ";
        cin >> number;
        negative = false;

        try {
            double dub = stod(number);
        }
        catch(...) {
            workOrNo = false;
        }

        if (number.find('.') == string::npos) { //if there is no decimal
            cout << "There's no decimal." << "\n";
        }
        else if (workOrNo == false) { //only numbers, -, and . allowed
            cout << "Do not use letters in your number or any other symbols besides a negative sign." << "\n";
        }
        else {
            if (number.find('-') == 1) { //checks for negative sign
                negative = true;
                number.erase(0, 1);
            }
            if (number.find('.') == 0) { //put a 0 at front if it needs one
                number.insert(0, "0");
            }

            string dummyNum = number; //copy string
            int decimalLoc = number.find('.'); //find location of the decimal point
            int numLength = number.length(); //find the length of the number
            string wholeNum = number.erase(decimalLoc, string::npos); //erase numbers after decimal point to get the whole number
            string numeratorStr = dummyNum.erase(0, decimalLoc + 1); //erase numbers before decimal point to get only the decimal numbers
            int numerLength = numeratorStr.length(); //find how many numbers are after the decimal point
            int denominator = pow(10, numerLength); //make denominator with correct power of 10 depending on length of numerator
            int numerator = stoi(numeratorStr, nullptr, 0); //change string to integer
            int GCF = gcd(numerator, denominator); //find the greatest common factor
            numerator = numerator / GCF; //devide by greatest common factor
            denominator = denominator / GCF; //devide by greatest common factor

            //print results
            if (negative == true) {
                if (stoi(wholeNum, nullptr, 0) == 0) { //if whole number is 0
                    cout << "Your decimal in exact fraction form is -" << numerator << "/" << denominator << "\n";
                }
                else {
                    cout << "Your decimal in exact fraction form is -" << wholeNum << " and " << numerator << "/" << denominator << "\n";
                }
            }
            else if (stoi(wholeNum, nullptr, 0) == 0) { //if whole number is 0
                cout << "Your decimal in exact fraction form is " << numerator << "/" << denominator << "\n";
            }
            else {
                cout << "Your decimal in exact fraction form is " << wholeNum << " and " << numerator << "/" << denominator << "\n";
            }
        }

        //check if user wants to run code again
        string response;
        cout << "Type STOP to end code, otherwise type 1." << "\n";
        cin >> response;
        if (response == "STOP") {
            run = false;
        }
    }  
}
