#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <vector>
#include <map>

using namespace std;


bool isValidPrefix(const string& prefix) {
    map<string, string> bankMap = {
        {"603799", "MELI"},
        {"589210", "SADERAT"},
        {"627648", "TOSEE SADERAT"},
        {"627961", "SANAT O MADAN"},
        {"603770", "KESHAVARZI"},
        {"628023", "MASKAN"},
        {"627760", "POST BANK"},
        {"502908", "TOSEE TAVON"},
        {"627412", "EGHTESAD NOVIN"},
        {"622106", "PARSIAN"},
        {"502229", "PASARGAD"},
        {"627488", "KARAFARIN"},
        {"621986", "SAMAN"},
        {"639346", "SINA"},
        {"639607", "SARMAYEH"},
        {"636214", "AYANDEH"},
        {"505785", "IRAN ZAMIN"},
        {"636949", "HEKMAT IRANIAN"},
        {"628157", "ETEBARI TOSEE"},
        {"505416", "GARDESHGARI"},
        {"606373", "QARZOL HASANE MEHR IRAN"},
        {"628175", "MEHR IRAN"},
        {"639370", "MEHR EGHTESAD"},
        {"627381", "ANSAR"},
        {"639194", "SARMAYEG"},
        {"603769", "SHABAKE PAYE KASHI"}
    };
    return bankMap.find(prefix) != bankMap.end();
}

int main() {
    vector<int> cardNumber(16, -1);
    string input;
    int index = 0;

    while (index < 16) {
        cout << "Enter digit " << index + 1 << ": ";
        cin >> input;

        if (input.length() != 1 || !isdigit(input[0])) {
            cout << "Invalid input. Please enter a single digit." << endl;
            continue;
        }

        int digit = input[0] - '0';
        cardNumber[index] = digit;
        index++;

        cout << "Current card number: ";
        for (int i = 0; i < 16; i++) {
            if (cardNumber[i] == -1) {
                cout << "_";
            } else {
                cout << cardNumber[i];
            }
            if ((i + 1) % 4 == 0 && i != 15) {
                cout << " ";
            }
        }
        cout << endl;

        if (index == 4) {
            string prefix;
            for (int i = 0; i < 4; i++) {
                prefix += to_string(cardNumber[i]);
            }
            if (!isValidPrefix(prefix)) {
                cout << "Invalid card prefix. Please start over." << endl;
                fill(cardNumber.begin(), cardNumber.end(), -1);
                index = 0;
            } else {
                cout << "Card prefix is valid." << endl;
            }
        }
    }

    cout << "Final card number: ";
    for (int i = 0; i < 16; i++) {
        if (i > 0 && i % 4 == 0) {
            cout << " ";
        }
        cout << cardNumber[i];
    }
    cout << endl;

    return 0;
}
