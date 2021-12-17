//////////////////////////////////
/*          <İREMSU KARDAŞ>         */
/*          <150180081>           */
//////////////////////////////////
#include <string>
#include "Person.h"
#include <iostream>

/*Constructor with arguments can also give optionally take
// Default constructor
Person::Person(){
    this->name = "";
    this->surname = "";
}*/


// Constructor with arguments
Person::Person(string name, string surname){
    this->name = name;
    this->surname = surname;
}
/* Constructor with arguments can also give optionally take
// Default constructor
Passenger::Passenger(){
    this->name = "";
    this->surname = "";
    this->cash = 0;
    this->ticket = false;
    this->next = NULL;
}*/

// Constructor with arguments    
Passenger::Passenger(string name, string surname,int cash, bool ticket, Passenger *next):Person(name,surname){
    this->cash = cash;
    this->ticket = ticket;
    this->next = NULL;
}

Passenger::Passenger(const Passenger& copy){
            this->name = copy.name;
            this->surname = copy.surname;
            this->cash = copy.cash;
            this->ticket = copy.ticket;
}

// Take ticket price if passenger can buy return true
bool Passenger::buyTicket(int ticket_price){
    if(ticket_price <= this->cash){
        this->ticket = true;
    }
    else{
        cout << "Passenger " << this->getName() << " " << this->getSurname() << " does not have a valid ticket!" << endl;
    }
    return ticket;
}

/*Constructor with arguments can also give optionally take
//Default constructor
Astronaut::Astronaut(){
    this->name = "";
    this->surname = "";
    this->numMissions = 0;
    this->next = NULL;
} */

// Constructor with argument
Astronaut::Astronaut(string name, string surname,int numMis, Astronaut* next):Person(name,surname){
    setNumMissions(numMis);
    this->next = next;
}

// Increment number mission 1
void Astronaut::completeMission() {
    this->numMissions += 1;
}

Astronaut::Astronaut(const Astronaut& copy){
            this->name = copy.name;
            this->surname = copy.surname;
            this->numMissions = copy.numMissions;
            this->next = copy.next;
        }