/*

Name:	Gulnoza Khakimova
Course: CS 201R
Program: Vehicle menu	
Due Date:	01/31/2016
Description:	This program is a monthly payment calculator which calculates 
the monthly payment for selected vehicle type from 1 to 4 years. It asks user 
to choose the vehicle type, put their credit score number and if they 
want to make a down payment or not.
Inputs:	User's car selection, credit score number and down payment.
Outputs: Price of a vehicle, monthly payments from 1 to 4 years.
Algorithm:	
1. Initialize all variables.
2. Ask user to enter vehicle type number from the menu.
3. Show selected vehicle price.
4. Ask user to put credit score number.
5. Calculate interest rate depanding on credit score number.
6. Ask user to enter down payment amount.
7. Calculate monthly payment from 1 to 4 years.

*/



#include <iostream>
#include <cmath>
using namespace std;

int CreditScore(int vehicleType, double vehiclePrice);
// PRE: CreditScore initialized. VehiclePrice and vehicleType passed to the function.
// POST: None
// RETURNS: 0.

int main()

{
    int vehicleType;
    double vehiclePrice = 0.0;
    // initialize vehicle price
    cout << "Choose vehicle type: \n" << "1. Honda \n" << "2. Ford \n" << "3. Toyota \n" << "4. Mazda" << endl;
    cin >> vehicleType; // get intput

    switch (vehicleType) // set vehicle price depending on vehicle type
    {
    case 1:
        vehiclePrice = 30000;
        cout << "This vehicle price is " << vehiclePrice;
        break;
    case 2:
        vehiclePrice = 25000;
        cout << "This vehicle price is " << vehiclePrice;
        break;
    case 3:
        vehiclePrice = 20000;
        cout << "This vehicle price is " << vehiclePrice;
        break;
    case 4:
        vehiclePrice = 18000;
        cout << "This vehicle price is " << vehiclePrice;
        break;
    default:
        cerr << "Unknown vehicle type. Choose again." << endl;
        break;
    }
    CreditScore(vehicleType, vehiclePrice); 
    //call CreditScore function. Passing vehicle type (int) and price (double)
        
}

int CreditScore(int vehicleType, double vehiclePrice) 
// call by value vehicle type and vehicle price from 1st function
    
{
        double creditScore = 0.0;
        double interestRate = 0.0;
        double downPayment = 0.0; //initializing all variables used in function
        cout << "\nEnter your credit score:" << endl;
        cin >> creditScore;

        if (creditScore <= 500) // set interest rate depending on credit score
    {
            interestRate = 0.05;
    }
            else if (creditScore >= 501, creditScore <= 700)
        {
                interestRate = 0.02;
        }
        else
    {
            interestRate = 0.01;
    }
        cout << "Would you like to make a down payment. "
            <<"If yes please put the amount:" << endl;
        cin >> downPayment; // input down payment amount

        double monthPayment1, monthPayment2, monthPayment3, monthPayment4; 
        // payments from 1 to 4 years

        monthPayment1=((vehiclePrice-downPayment)*pow((1+interestRate),1))/(12*1); 
        // calculate monthly payment from 1 to 4 years
        monthPayment2=((vehiclePrice-downPayment)*pow((1+interestRate),2))/(12*2);
        monthPayment3=((vehiclePrice-downPayment)*pow((1+interestRate),3))/(12*3);
        monthPayment4=((vehiclePrice-downPayment)*pow((1+interestRate),4))/(12*4);

        cout << "Monthly payment for 1 year is " << monthPayment1 << endl;
        // output monthly payment amount from 1 to 4 years
        cout << "Monthly payment for 2 years is " << monthPayment2 << endl;
        cout << "Monthly payment for 3 years is " << monthPayment3 << endl;
        cout << "Monthly payment for 4 years is " << monthPayment4 << endl;

        system("pause");
        return 0;
}
