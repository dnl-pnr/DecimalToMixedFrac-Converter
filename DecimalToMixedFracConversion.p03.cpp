#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    bool run = true;
    bool negative = false;
    bool workOrNo = true;

    while (run == true) {

        //receive user number
        string number;
        cout << "Enter you decimal: ";
        cin >> number;

        try {
            double dub = stod(number);
        }
        catch (...) {
            workOrNo = false;
        }

        if (number.find('.') == string::npos) { //if there is no decimal
            cout << "There's no decimal. Your whole number is: " << number << "\n";
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

            string dummyStr = number; //copy string
            int decimalLoc = number.find('.'); //find location of the decimal point
            string wholeNumStr = number.erase(decimalLoc, string::npos);//erase numbers after decimal point to get the whole number
            string deciStr = dummyStr.erase(0, decimalLoc); //erase numbers before decimal point to get only the decimal numbers
            
            //declare variables
            vector<int> z;
            vector<int> N;
            vector<int> D;
            bool toler = true;
            double val;

            deciStr.erase(0, 1); //get rid of decimal point
            int divis = stoi(deciStr); //convert to string to int

            for (int i = 0; toler == true; ++i) { //fill vector z
                z.insert(z.begin() + i, pow(10, deciStr.length()) / divis);
                val = (pow(10, deciStr.length()) / divis) - z.at(i);
                if (val < 0.01) {
                    toler = false;
                }
                deciStr = to_string((pow(10, deciStr.length()) / divis) - z.at(i));
                deciStr.erase(0, 2);
                divis = stoi(deciStr);
            }
            //give N and D starting values
            int vecLen = z.size();
            D.assign(1, 1);
            N.assign(1, 0);

            //add element to end of vector calculated based off the previous elements
            for (int i = 0; i < vecLen; ++i) {
                N.push_back(D.at(i));
                D.push_back((D.at(i) * z.at(z.size() - 1 - i)) + N.at(i));
            }
         
            int numerator = N.at(vecLen);
            int denominator = D.at(vecLen);

            //print results
            if (negative == true) {
                if (stoi(wholeNumStr, nullptr, 0) == 0) { //if whole number is 0
                    cout << "Your decimal in exact fraction form is -" << numerator << "/" << denominator << "\n";
                }
                else {
                    cout << "Your decimal in exact fraction form is -" << stoi(wholeNumStr) << " and " << numerator << "/" << denominator << "\n";
                }
            }
            else if (stoi(wholeNumStr, nullptr, 0) == 0) { //if whole number is 0
                cout << "Your decimal in exact fraction form is " << numerator << "/" << denominator << "\n";
            }
            else {
                cout << "Your decimal in exact fraction form is " << stoi(wholeNumStr) << " and " << numerator << "/" << denominator << "\n";
            }
            
        }
        //check if user wants to run code again
        string response;
        cout << "Enter 1 to run again." << "\n";
        cin >> response;
        if (response == "1") {
            run = true;
        }
        else {
            run = false;
        }
    }
}
