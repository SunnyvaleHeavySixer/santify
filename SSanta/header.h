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

//Function to get number of participants
int getParticipants()
{   
    int x;
    std::cout<<"Enter Number of Participants: ";
    std::cin>>x;
    return x;
}

// Method to check if email has an @ sign
// Checks that the string contains at least one '@' and a '.'
// after it. This will have lots of false negatives (but no
// false negative), like "a@b@c.com" or "toto@com.".
bool isEmail(std::string const& address)
{
    size_t at_index = address.find_first_of('@', 0);
    return at_index != std::string::npos
    && address.find_first_of('.', at_index) != std::string::npos;
}

#endif /* header_h */
