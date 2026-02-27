#include <iostream>
#include "AirgeadBanking.h"

using namespace std;

int main() {
    AirgeadBanking bankingApp;

    bankingApp.GetUserInput();
    bankingApp.DisplayMenu();

    cout << "\nPress Enter to Continue...";
    cin.ignore();
    cin.get();

    bankingApp.CalculateWithoutMonthlyDeposit();
    bankingApp.CalculateWithMonthlyDeposit();

    return 0;
}
