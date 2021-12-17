//////////////////////////////////
/*          <İREMSU KARDAŞ>         */
/*          <150180081>           */
//////////////////////////////////
#ifndef AGENCY_H
#define AGENCY_H


#include <string>
//#include "Person.cpp"
//#include "Person.h"
//#include "Mission.cpp"
#include "Mission.h"
//#include "main.cpp"


class Agency {
	private:
		string name;
		int cash;
		int ticketPrice;
		Mission* completedMissions;
		Mission* nextMissions;
	public:
		//Agency(); //with other constructor this becomes unnecessary
		Agency(string = "", int = 0,int = 0, Mission* = NULL, Mission* = NULL);
		//***************GETTERS************
		string getName() const { return this->name; }
		int getCash() const { return this->cash; }
		Mission* getComp_Mis(){return &this->completedMissions[0];}
		Mission* getNext_Mis(){return &this->nextMissions[0];}
		int getTicketPrice() const { return this->ticketPrice; }
		//*************SETTERS***************
		void setName(string name) { this->name = name; }
		void setCash(int cash) { this->cash = cash; }
		void setTicketPrice(int ticketPrice) {
			if(ticketPrice <0){
                cout << "Ticket price can't be negative. It is set to 0." << endl;
                ticketPrice = 0;
            }
            this->ticketPrice = ticketPrice; 
		}
		//********************FUNCTIONS***************
		void addMission(Mission); //Adding Mission to the Agency
		void executeNextMission();//explained in function
		friend ostream & operator << (ostream& os, Agency & agency); //Print Agency Informations

		//~Agency();
};

#endif