#ifndef AIRGEADBANKING_H
#define AIRGEADBANKING_H

class AirgeadBanking {
private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int years;

public:
    AirgeadBanking();
    void GetUserInput();
    void DisplayMenu() const;
    void CalculateWithoutMonthlyDeposit() const;
    void CalculateWithMonthlyDeposit() const;
};

#endif
