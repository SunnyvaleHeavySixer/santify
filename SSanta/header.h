//
//  header.h
//  SSanta
//
//  Created by Will Andrews on 24/11/2016.
//  Copyright © 2016 WA. All rights reserved.
// test

#ifndef header_h
#define header_h

#include <string>

// Structure to contain peoples names, emails, partners and an id number
struct Participants
{
    std::string name, email, partner;
    int idNumber;
    Participants(std::string n_, std::string e_, std::string p_, int i_)
    {
        name = n_;
        email = e_;
        partner = p_;
        idNumber = i_; // stores the current counter number and uses it as an ID for each participant
    }
};

// Method to check if email has an @ sign
bool isEmail(std::string x)
{
    long int lStr = x.length();
    //bool isValid = false;
    char c = '\0';
    for(int i=0;i<lStr;i++)
        c = x[i];
    if (c == '@')
        return true;
    //                {
    //                std::cout<<"This loop has found the @ sign \n";
    //                isValid = true;
    //                }
    else
    {
        std::cout<<"This loop has not found the @ sign \n";
        //isValid = false;
    }
    //if (isValid == true){return true;}
    return false;
}



#endif /* header_h */
