// ------------- FILE HEADER -------------
// Author: [Your Name]
// Assignment: Assignment 3 - Washington State Ferries
// Date: 2026-10-06
// Citations: Assignment instructions and fare table

// ------------- CODE -------------
#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include "fare_strings.h"

using namespace std;

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main()
{
  const double vehicleFareAmount = 57.90;
  const double adultFareAmount = 14.95;
  const double seniorFareAmount = 7.40;
  const double youthFareAmount = 5.55;
  const double bicycleFareAmount = 4.00;

  char ridingVehicle_y_n;
  long long adults;
  long long seniors;
  long long youths;
  long long bikes = 0;

  cout << MESSAGE_WELCOME
       << endl
       << endl;
  cout << left << setw(59) << LABEL_FARE_DESCRIPTION << LABEL_TICKET_PRICE << endl;
  cout << LABEL_SEPARATOR << endl;
  cout << left << setw(59) << LABEL_VEHICLE << VALUE_VEHICLE_FARE << endl;
  cout << left << setw(59) << LABEL_ADULT << VALUE_ADULT_FARE << endl;
  cout << left << setw(59) << LABEL_SENIOR << VALUE_SENIOR_FARE << endl;
  cout << left << setw(59) << LABEL_YOUTH << VALUE_YOUTH_FARE << endl;
  cout << left << setw(59) << LABEL_BICYCLE << VALUE_BICYCLE_FARE << endl;
  cout << endl
       << PROMPT_VEHICLE;
  cin >> ridingVehicle_y_n;

  bool vehicle = false;
  bool valid = true;
  
  switch(ridingVehicle_y_n) {
    case 'Y': // fallthrough
    case 'y': 
      vehicle = true;
      break;
    case 'N': // fallthrough
    case 'n': 
      vehicle = false;
      break;      
    default:
      valid = false;
  }

  if (valid)
  {
    cout << endl;
    cout << PROMPT_ADULTS;
    valid = (cin >> adults) && adults >= 0;
  }

  if (valid)
  {
    cout << endl;
    cout << PROMPT_SENIORS;
    valid = (cin >> seniors) && seniors >= 0;
  }  

  if (valid)
  {
    cout << endl;
    cout << PROMPT_YOUTHS;
    valid = (cin >> youths) && youths >= 0;
  } 

  if (valid)
  {
    if(!vehicle) {
      cout << PROMPT_BIKES;
      valid = (cin >> bikes) && bikes >= 0;
    }
  }   

  if (!valid)
  {
    cout << ERROR_INVALID_ANSWER << endl;
    cout << MESSAGE_GOODBYE << endl;
    return 0;
  }

  if (adults > numeric_limits<long long>::max() - seniors ||
      adults + seniors > numeric_limits<long long>::max() - youths)
  {
    cout << ERROR_INVALID_ANSWER << endl;
    cout << MESSAGE_GOODBYE << endl;
    return 0;
  }

  const long long people = adults + seniors + youths;
  if (people > 20)
  {
    const long long groups = people / 20 + (people % 20 != 0);
    cout << endl;
    cout << MESSAGE_GROUP_LIMIT_PREFIX << groups << MESSAGE_GROUP_LIMIT_SUFFIX << endl;
    cout << endl;
    cout << MESSAGE_GOODBYE << endl;
    return 0;
  }

  double total = adults * adultFareAmount + seniors * seniorFareAmount + youths * youthFareAmount;
  if (vehicle)
  {
    total += vehicleFareAmount;
  }
  else
  {
    total += bikes * bicycleFareAmount;
  }

  cout << endl;
  cout << MESSAGE_TOTAL_CHARGE_PREFIX << fixed << setprecision(2) << total << endl;
  cout << endl;
  if (total > 100.00)
  {
    cout << MESSAGE_FREE_TICKET << endl;
    cout << endl;
  }
  else
  {
    cout << MESSAGE_SPEND_MORE_PREFIX << 100.00 - total << MESSAGE_SPEND_MORE_SUFFIX << endl;
    cout << endl;
  }

  cout << MESSAGE_GOODBYE << endl;
  return 0;
}

// ------------- DESIGN -------------
/*
Program Name:
Washington State Ferries Fare Calculator

Program Description:
Calculate ferry charges from the passenger, vehicle, and bicycle counts.

Design:
A. INPUT
  ridingVehicle: char, whether the group is taking a vehicle (Y/N)
  adults: long long, number of adults
  seniors: long long, number of seniors
  youths: long long, number of youths
  bikes: long long, number of bicycles when there is no vehicle

B. OUTPUT
  total: double, total fare formatted as currency
  Error or group-size message when applicable
  Free-ticket eligibility or the amount remaining to spend

C. CALCULATIONS
  Passenger fare = adults * 14.95 + seniors * 7.40 + youths * 5.55
  Add 57.90 for a vehicle, otherwise add bikes * 4.00
  Groups needed = people / 20, rounded up
  Amount remaining = 100.00 - total when total is not over 100.00

D. LOGIC and ALGORITHMS
  Display the welcome message and fare menu.
  Ask whether the group is riding a vehicle; accept Y/y or N/n only.
  Prompt for adult, senior, and youth counts; reject invalid or negative input.
  If there is no vehicle, prompt for the number of bikes.
  If passenger count exceeds 20, display the number of groups needed and end.
  Calculate and display the total fare with two decimal places.
  If the fare is over $100, award the free-ticket eligibility message;
  otherwise display the amount remaining to spend.
  Display the goodbye message.

SAMPLE RUNS
Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                 $57.90
Adult (age 19 - 64)                                         $14.95
Senior (age 65 & over) / Disability                         $7.40
Youth (age 6 - 18)                                          $5.55
Bicycle Surcharge (included with Vehicle)                   $4.00

Are you riding a vehicle on the Ferry (Y/N): y

How many adults? 2
How many seniors? 1
How many youths? 0

Your total charge is $95.20

If you spend $4.80 more, you are eligible for a free adult ticket for the next trip.

Thank you for using Washington State Ferries Fare Calculator!

Welcome to the Washington State Ferries Fare Calculator!

Are you riding a vehicle on the Ferry (Y/N): a

Error!! Invalid answer!! Please try again later!!!

Thank you for using Washington State Ferries Fare Calculator!

Welcome to the Washington State Ferries Fare Calculator!

Are you riding a vehicle on the Ferry (Y/N): n

How many adults? 2
How many seniors? 1
How many youths? 1
How many bikes? 2

Your total charge is $50.85

If you spend $49.15 more, you are eligible for a free adult ticket for the next trip.

Thank you for using Washington State Ferries Fare Calculator!

Welcome to the Washington State Ferries Fare Calculator!

Are you riding a vehicle on the Ferry (Y/N): n
How many adults? -7

Error!! Invalid answer!! Please try again later!!!

Thank you for using Washington State Ferries Fare Calculator!

Welcome to the Washington State Ferries Fare Calculator!

Are you riding a vehicle on the Ferry (Y/N): n

How many adults? 12
How many seniors? 4
How many youths? 5
How many bikes? 2

Uh oh!! Too many people in your group. Split into 2 groups and try again!

Thank you for using Washington State Ferries Fare Calculator!
*/
