//////////////////////////////////
/*          <İREMSU KARDAŞ>         */
/*          <150180081>           */
//////////////////////////////////
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
        string name;
        string surname;
    public:
        string getName()const{return this->name;} // get person name
        void setName(string name){this->name = name;}  // set person name

        string getSurname()const{return this->surname;}  // get person surname
        void setSurname(string surname){this->surname = surname;} // set person surname

        Person(const Person& copy){
            this->name = copy.name;
            this->surname = copy.name;
        }
       // Person(); // default constructor
        Person(string = "" , string = ""); // //constructor that optionally take attributess
};


class Passenger : public Person{
    private:
        int cash;
        bool ticket;
    public:
        Passenger *next = NULL;
        int getCash()const {return this->cash;} // get passenger cash
        void setCash(int cash){this->cash = cash;} // set passenger cash

        bool getTicket()const {return this->ticket;} // get passenger ticket information
        void setTicket(bool ticket){this->ticket = ticket; }    // set passenger ticket information}
        Passenger(const Passenger&);
        //Passenger(); // default constructor
        Passenger(string ="", string = "", int =0, bool = false, Passenger* = NULL); // constructor that optionally take attributes
        bool buyTicket(int); // take ticket price if passenger can buy return true
        ~Passenger(){ //destructor
            delete next;
        }
};

class Astronaut : public Person{
    private:
        int numMissions;
    public:
        Astronaut *next = NULL;
        int getNumMissions()const {return this->numMissions;} // get Astronaut's number mission
        void setNumMissions(int numMissions){
            if(numMissions>=0){
                this->numMissions = numMissions;} //set Astronaut's number mission
            else{
                std::cout << "Number of missions that astronaut completed can't be negative. It is set to 0." << std::endl;
                this->numMissions = 0;
            }
        }
        Astronaut(const Astronaut&); // copy constructor
        //Astronaut(); // default constructor
        Astronaut(string ="", string ="",int = 0,Astronaut* = NULL); // constructor that optionally take attributes
        void completeMission(); // increment number mission 1
        ~Astronaut(){ //destructor
            delete next;
        }
};

#endif