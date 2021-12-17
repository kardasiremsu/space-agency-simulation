//////////////////////////////////
/*          <İREMSU KARDAŞ>         */
/*          <150180081>           */
//////////////////////////////////

#include <iostream>
#include "Mission.h"

using namespace std;
/*
// Default constructor
Mission::Mission(){
	this->name = "";
	this->missionNumber = 0;
	this->cost = 0;
	this->faultProbability = 0;
	this->completed = false;
	this->passengers = NULL;
	this->crew = NULL;
	this->next = NULL;
	numMissions++;
}*/

// Constructor with arguments
Mission::Mission(string name,int cost, int faultProbability,int missionNumber, bool completed, Passenger* passengers, Astronaut* crew,Mission* next) { //,int size_pas, int size_ast
	this->setName(name);
	this->cost = cost;
	this->setFaultProbability(faultProbability);
	this->missionNumber = missionNumber;
	this->completed = completed;
	this->passengers = passengers;
	this->crew = crew;
	this->next = next;
	numMissions++;
}

// Copy Constructor
Mission::Mission(const Mission&copy){
	this->name = copy.name;
	this->missionNumber = copy.missionNumber;
	this->cost = copy.cost;
	this->faultProbability = copy.faultProbability;
	this->completed = copy.completed;
	Passenger* temp1 = copy.passengers; //for copy  all passengers' linked list
	while(temp1 != NULL){
		this->passengers = copy.passengers;
		temp1 = temp1->next;
	}
	Astronaut* temp2 = copy.crew; //for copy all astronaut's linked list
	while(temp2 != NULL){
		this->crew = copy.crew;
		temp2 = temp2->next;
	}
	this->next =NULL;
}

Mission& Mission::operator+=(Astronaut *astronaut) {
	if(crew == NULL){// if there is no astronaut linked list is empty, add to head
		crew= new Astronaut(astronaut->getName(), astronaut->getSurname(),astronaut->getNumMissions()); 
	}
	else{
		Astronaut *temp = crew;
		while(temp->next != NULL){
				temp = temp->next;
			}
		temp->next = new Astronaut(astronaut->getName(), astronaut->getSurname(),astronaut->getNumMissions()); ////adding as last element
	}
	astronaut->setNumMissions(astronaut->getNumMissions() + 1); //Astronaut's missions increased
	return *this;
}

Mission& Mission::operator+=(Passenger *passenger) {
	if(passengers == NULL){ // if there is no passengers linked list is empty, add to head
		passengers= new Passenger(passenger->getName(), passenger->getSurname(),passenger->getCash(), passenger->getTicket());
	}
	else{
		Passenger *temp = passengers;
		while(temp->next != NULL){
				temp = temp->next;
			}
		temp->next =  new Passenger(passenger->getName(), passenger->getSurname(),passenger->getCash(), passenger->getTicket()); 
	} //adding as last element
	return *this;
}

bool Mission::executeMission() {
	int random_value;
	random_value = rand()%100;
	if (random_value > faultProbability) { 		
		cout << "MISSION " << this->getName() << " SUCCESFUL!" <<endl;
		Astronaut *temp = this->getCrew();
		while(temp !=NULL) {
			temp->completeMission(); //for crew can success the mission
			cout << "Astronaut "<< (temp)->getName() << " " << (temp)->getSurname() << " successfully completed "<< (temp)->getNumMissions() << " missions." <<endl;
			temp = temp->next;
		}
		completed = true; //mission is succesfull
		return completed;
	}
	else {
		cout << "MISSION " << this->getName() << " FAILED!" << endl; 
		completed = false; //mission failed
		return completed;
	}
}

int Mission::calculateProfit(int ticketprice){
	int profit = 0;
	if (completed == 1) {
		Passenger *temp= getPassengers();
		int i=0; // for finding how many passengers
		while(temp != NULL){
			i++;
			temp = temp->next;
			}
		profit += i * ticketprice;
	}
		profit = profit - cost;
		return profit;
} //I tried a lot of times, this functions calculate profit but when returning negative value it gives error.

/*
Mission::~Mission(){
	Passenger *ptr1 = this->passengers;
	while(ptr1 !=NULL){
		this->passengers = ptr1->next;
		delete ptr1;
		ptr1 = this->passengers; 
	}

	Astronaut *ptr2 = this->crew;

	while(ptr2 !=NULL){
		this->crew = ptr2->next;
		delete ptr2;
		ptr2 = this->crew; 
	}
}*/