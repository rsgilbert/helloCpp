#include <iostream>
#include <string>
#include <vector>

using namespace std;

string spacer() {
    return " ";
}

vector<string> twentyStrings = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                                "eleven",
                                "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                                "nineteen", "twenty"};

string twenties(const string number) {
    return twentyStrings[stoi(number)];
}

vector<string> overTwenties = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

// middleware functions
string tens(string number) {
    number = to_string(stoi(number));
    int numberAsInt = stoi(number);

    if (numberAsInt > 20) {
        int tensDigitInt = stoi(number.substr(0, 1));
        string onesDigit = number.substr(1);
        return overTwenties[tensDigitInt] + spacer() + twenties(onesDigit);
    }
    return twenties(number);


}

string hundreds(string number) {
    number = to_string(stoi(number));
    string::size_type digits = number.size();
    string hundredString = "hundred";
    if (digits > 2) {
        string::size_type numberOfHundreds = digits - 2;
        string tensDigitsLeft = number.substr(0, numberOfHundreds);
        string tensDigitRight = number.substr(numberOfHundreds);
        return tens(tensDigitsLeft) + spacer() + hundredString + spacer() + tens(tensDigitRight);
    }
    return tens(number);
}


string thousands(string number) {
    number = to_string(stoi(number));
    string::size_type digits = number.size();
    string thousandString = "thousand";

    if (digits > 3) {
        string::size_type numberOfThousands = digits - 3;
        string hundredsDigitsLeft = number.substr(0, numberOfThousands);
        string hundredsDigitsRight = number.substr(numberOfThousands);
        return hundreds(hundredsDigitsLeft) + spacer() + thousandString + spacer() + hundreds(hundredsDigitsRight);
    }
    return hundreds(number);
}

string millions(string number) {
    string::size_type digits = number.size();
    string millionString = "million";

    if (digits > 6) {
        string::size_type numberOfMillions = digits - 6;
        string millionsDigitsLeft = number.substr(0, numberOfMillions);
        string millionsDigitRight = number.substr(numberOfMillions);
        return thousands(millionsDigitsLeft) + spacer() + millionString + spacer() + thousands(millionsDigitRight);
    }
    return thousands(number);
}


// convert a number below 10,000 to words;
int main() {
    string number = "1000000";

//    if (stoi(number) > 100000) {
//        cout << "OUT OF RANGE";
//        return 1;
//    }

    cin >> number;
    cout << number << " is " << millions(number);

}



