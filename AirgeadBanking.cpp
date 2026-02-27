#include <iostream>
#include <iomanip>
#include "AirgeadBanking.h"

using namespace std;

AirgeadBanking::AirgeadBanking() {
    initialInvestment = 0.0;
    monthlyDeposit = 0.0;
    annualInterest = 0.0;
    years = 0;
}

void AirgeadBanking::DisplayMenu() const {
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;
    cout << "Initial Investment Amount: $" << initialInvestment << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest: " << annualInterest << "%" << endl;
    cout << "Number of Years: " << years << endl;
    cout << "**********************************" << endl;
}

void AirgeadBanking::GetUserInput() {
    cout << "Enter Initial Investment Amount: ";
    cin >> initialInvestment;

    cout << "Enter Monthly Deposit: ";
    cin >> monthlyDeposit;

    cout << "Enter Annual Interest Rate (in %): ";
    cin >> annualInterest;

    cout << "Enter Number of Years: ";
    cin >> years;
}

void AirgeadBanking::CalculateWithoutMonthlyDeposit() const {
    double balance = initialInvestment;
    double interestEarned = 0.0;

    cout << "\nBalance and Interest Without Additional Monthly Deposits" << endl;
    cout << "=========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    for (int i = 1; i <= years; ++i) {
        interestEarned = balance * (annualInterest / 100);
        balance += interestEarned;

        cout << i << "\t$" << fixed << setprecision(2) << balance
             << "\t\t\t$" << interestEarned << endl;
    }
}

void AirgeadBanking::CalculateWithMonthlyDeposit() const {
    double balance = initialInvestment;
    double monthlyInterestRate = (annualInterest / 100) / 12;
    double yearlyInterest = 0.0;

    cout << "\nBalance and Interest With Additional Monthly Deposits" << endl;
    cout << "======================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    for (int i = 1; i <= years; ++i) {
        yearlyInterest = 0.0;

        for (int j = 0; j < 12; ++j) {
            double monthlyInterest = (balance + monthlyDeposit) * monthlyInterestRate;
            yearlyInterest += monthlyInterest;
            balance += monthlyDeposit + monthlyInterest;
        }

        cout << i << "\t$" << fixed << setprecision(2) << balance
             << "\t\t\t$" << yearlyInterest << endl;
    }
}
