#pragma once

#include <string>

using std::string;

const string MESSAGE_WELCOME = "Welcome to the Washington State Ferries Fare Calculator!";
const string MESSAGE_GOODBYE = "Thank you for using Washington State Ferries Fare Calculator!";

const string LABEL_FARE_DESCRIPTION = "Fare Description";
const string LABEL_TICKET_PRICE = "Ticket $";

const string LABEL_SEPARATOR = "--------------------------------------                     --------";

const string LABEL_VEHICLE = "Vehicle Under 14' (less than 168\") & Driver";
const string VALUE_VEHICLE_FARE = "$57.90";

const string LABEL_ADULT = "Adult (age 19 - 64)";
const string VALUE_ADULT_FARE = "$14.95";

const string LABEL_SENIOR = "Senior (age 65 & over) / Disability";
const string VALUE_SENIOR_FARE = "$7.40";

const string LABEL_YOUTH = "Youth (age 6 - 18)";
const string VALUE_YOUTH_FARE = "$5.55";

const string LABEL_BICYCLE = "Bicycle Surcharge (included with Vehicle)";
const string VALUE_BICYCLE_FARE = "$4.00";

const string PROMPT_VEHICLE = "Are you riding a vehicle on the Ferry (Y/N): ";
const string PROMPT_ADULTS = "How many adults? ";
const string PROMPT_SENIORS = "How many seniors? ";
const string PROMPT_YOUTHS = "How many youths? ";
const string PROMPT_BIKES = "How many bikes? ";

const string MESSAGE_GROUP_LIMIT_PREFIX = "Uh oh!! Too many people in your group. Split into ";
const string MESSAGE_GROUP_LIMIT_SUFFIX = " groups and try again!";
const string MESSAGE_TOTAL_CHARGE_PREFIX = "Your total charge is $";
const string MESSAGE_FREE_TICKET = "You are eligible for a free adult ticket for your next trip!";
const string MESSAGE_SPEND_MORE_PREFIX = "If you spend $";
const string MESSAGE_SPEND_MORE_SUFFIX = " more, you are eligible for a free adult ticket for the next trip.";

const string ERROR_INVALID_ANSWER = "Error!! Invalid answer!! Please try again later!!!";
