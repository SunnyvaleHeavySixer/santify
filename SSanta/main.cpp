//
//  main.cpp
//  SSanta
//
//  Created by Will Andrews on 24/11/2016.
//  Copyright © 2016 WA. All rights reserved.
// test

// C++ script to enter names, email addresses and partners of a known amount of participants

#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

int main()
{
    int numParticipants, temp_idNumber;
    string temp_name, temp_email, temp_partner; //variables to store user inputs
    std::vector<Participants> ParticipantsList; //list of Participants
    
    std::cout<<"Enter Number of Participants: ";
    std::cin>>numParticipants; //get number of Participants
    
    for(int i=0;i<numParticipants;i++) //loop according to how many Participants you have
    {
        std::cout<<"Enter name of of Participant "<<(i+1)<<": ";
        std::cin>>temp_name; //get name
        std::cout<<"Enter email of Participant "<<(i+1)<<": ";
        std::cin>>temp_email; //get email
        //testing if email is valid
        if (isEmail(temp_email) == false){cout<<"WTF thats not an email ";}
        
        std::cout<<"Enter partner of Participant "<<(i+1)<<" (type 0 if no partner)"<<": ";
        std::cin>>temp_partner; //get partner
        temp_idNumber = i+1; //add one to shift ID from 0-9 to 1-10 for clarity
        ParticipantsList.push_back(Participants(temp_name, temp_email, temp_partner, temp_idNumber));
        //push back the current Participants
    }
    
    std::cout<<"\nNumber of Participants: "<<ParticipantsList.size()<<std::endl;
    for(int i=0;i<ParticipantsList.size();i++)
        std::cout<<"Participant "<<(i+1)<<" : "<<ParticipantsList.at(i).name<<" "
                                               <<ParticipantsList.at(i).email<<" "
                                               <<ParticipantsList.at(i).partner<<" "
                                               <<ParticipantsList.at(i).idNumber<<std::endl;
    
    return 0;
}
