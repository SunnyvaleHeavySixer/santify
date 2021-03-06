//
//  main.cpp
//  SSanta
//
//  Created by Will Andrews on 24/11/2016.
//  Copyright © 2016 WA. All rights reserved.
// test

// C++ script to enter names, email addresses and partners of a known amount of participants
// Relies on names being entered identically
// TODO: Matching logic

#include <iostream>
#include <vector>
#include "header.h"

using namespace std;

int main()
{
    int numParticipants, temp_idNumber;
    string temp_name, temp_email, temp_partner; //variables to store user inputs
    std::vector<Participants> ParticipantsList; //expandable list of Participants (struct is defined in header file)
    

    
   // RecipientsList = ParticipantsList;
    
    //std::cout<<"Enter Number of Participants: ";
    numParticipants = getParticipants(); //get number of Participants
    
    for(int i=0;i<numParticipants;i++) //loop according to how many Participants you have
    {
        std::cout<<"Enter name of of Participant "<<(i+1)<<": ";
        std::cin>>temp_name; //get name
        
            // Email address simple validation (defined in header)
            do
                {
                    std::cout << "Please enter email address of Participant "<<(i+1)<<":\n";
                    std::cin>>temp_email;
                }
            while (isEmail(temp_email) == false);
        
        std::cout<<"Enter partner of Participant "<<(i+1)<<" (type 0 if no partner)"<<": ";
        std::cin>>temp_partner; //get partner
        temp_idNumber = i+1; //add one to shift ID from 0-9 to 1-10 for clarity
        ParticipantsList.push_back(Participants(temp_name, temp_email, temp_partner, temp_idNumber));
        //push back the current Participants
    }
    
    // Displays all data collected before proceeding
    std::cout<<"\nNumber of Participants: "<<ParticipantsList.size()<<std::endl<<std::endl;
    for(int i=0;i<ParticipantsList.size();i++)
        std::cout<<"Participant "<<(i+1)<<": \n"
                                               <<"Name: "<<ParticipantsList.at(i).name<<" \n"
                                               <<"Email: "<<ParticipantsList.at(i).email<<" \n"
                                               <<"Partner: "<<ParticipantsList.at(i).partner<<" \n"
                                               <<"ID: "<<ParticipantsList.at(i).idNumber<<std::endl;
    
    cout << "\n\n<<<<<  S E C R E T    S A N T A  >>>>> \n";
    cout <<     "<<<<<          selections:       >>>>> \n \n";
    
    // Logic for Secret Santa selections:
    // 2 arrays? One for Sender, one for recipient? Randomize each time?
    // Step sequentially through Sender array > ignore sender's Partner if valid + still available
    // Pick recipient and remove them from the Recipient array
    
    //THIS RANDOM NUMBER GENERATOR IS BROKEN.  SAME EACH TIME.  FIX ME
    for(int i=0;i<numParticipants;i++)
        cout<<ParticipantsList[i].name << " is getting a present for: " <<ParticipantsList[RandY(ParticipantsList.size())].name << " \n\n";
    
    
    
    return 0;
}
