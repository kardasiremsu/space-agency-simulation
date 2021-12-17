//////////////////////////////////
/*          <İREMSU KARDAŞ>         */
/*          <150180081>           */
//////////////////////////////////
#ifndef MISSION_H
#define MISSION_H

#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

class Mission{
	private:
		string name;
		int cost;
		int faultProbability;
		int missionNumber;
		bool completed;
		Passenger* passengers;
		Astronaut* crew;
		static int numMissions;
	public:	
		Mission *next = NULL;

		//Mission();  //with other constructor this becomes unnecessary
		Mission(string,int = 0,int = 0,int = 0,bool = false, Passenger* = NULL, Astronaut* = NULL,Mission* = NULL);  // can optionally take
		Mission(const Mission&);

		//***************GETTERS*************
		Passenger* getPassengers(){return this->passengers;}
		Astronaut* getCrew() {return this->crew;}
		Mission* getNext(){return this->next;}
		int getCost() { return this->cost; }
		string getName()const { return this->name; } // get Mission's name
		int getMissionNumber(){return this->missionNumber;}
		int getFaultProbability() { return this->faultProbability; }
		bool getCompleted() { return this->completed;}
		static int getNumMissions() { return numMissions; }
		//***********SETTERS******************
		void setCost(int cost) { this->cost = cost; }
		void setNext(Mission *next){this->next = next;}
		void setName(string name) { //using in constructors also
				if (name.length() == 5) {
				string up_case = name.substr(0, 2);
				string digit = name.substr(3,2);

				if (up_case[0] >= 'A' && up_case[0] <= 'Z' && up_case[1] >= 'A' && up_case[1] <= 'Z' && isdigit(digit[0]) && isdigit(digit[1])){
					this->name = name;
					return;
				}
			}
		cerr << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
		this->name = "AA-00";
		}		
		void setMissionNumber(int missionNumber){this->missionNumber= missionNumber;}
		void setFaultProbability(int faultProbability) {
			if (faultProbability >= 0 && faultProbability <= 100) {
				this->faultProbability = faultProbability;
				if (faultProbability == 100) {
					this->completed = false;
				}
			}
			else
				cerr << "It could be 0-100" << endl;
		}
		void setCompleted(bool completed) { this->completed = completed;}
		static void setNumMissions(int numMissions_) { numMissions = numMissions_; } //in static could not used this pointer
		//******************FUNCTIONS*************
		Mission& operator+=(Passenger*); //add passenger to the passengers linkedlist for mission 
		Mission& operator+=(Astronaut*); //add astronaut to the crew linkedlist for mission 
		bool executeMission(); //Is mission succesful
		int calculateProfit(int); //Calculte profit

		//~Mission();


};
#endif
