//////////////////////////////////
/*          <İREMSU KARDAŞ>         */
/*          <150180081>           */
//////////////////////////////////
#include <iostream>
#include "Agency.h"

using namespace std;
/*
// Default constructor
Agency::Agency() {
	this->name = "";
	this->cash = 0;
	this->ticketPrice = 0;
	this->completedMissions = NULL;
	this->nextMissions = NULL;
}*/

// Constructor with arguments
Agency::Agency(string name, int cash, int ticketPrice, Mission* completedMissions, Mission* nextMissions) {//,int size_next, int size_completed
	this->name = name;
	this->cash = cash;
	this->setTicketPrice(ticketPrice);
	this->completedMissions = NULL;
	this->nextMissions = NULL;
}
void Agency::addMission(Mission mission){
	int mission_number = 1;
	if(nextMissions == NULL){
		nextMissions = new Mission(mission.getName(),mission.getCost(),mission.getFaultProbability(),mission_number,mission.getCompleted(),mission.getPassengers(),mission.getCrew());
		nextMissions->setNumMissions(nextMissions->getNumMissions() -1);
	}
	else{
		Mission *temp = nextMissions;
		mission_number ++;
		while(temp->next != NULL){
			temp = temp->next;
			mission_number++;
		}
		temp->next = new Mission(mission.getName(),mission.getCost(),mission.getFaultProbability(),mission_number,mission.getCompleted(),mission.getPassengers(),mission.getCrew());
		nextMissions->setNumMissions(nextMissions->getNumMissions() -1);
	}
}

void  Agency::executeNextMission(){
	if(this->nextMissions == NULL){
		cout << "No available mission to execute!" << endl;
	}
	else{
		bool iscompleted = nextMissions->executeMission();
		if(iscompleted){//next mission is exist
			int profit = nextMissions->calculateProfit(ticketPrice);
			profit -= nextMissions->getCost();
			cash += profit;
			Mission *first = nextMissions;
			//Delete from next mission, add to completed mission
			if(completedMissions == NULL){ //If completed mission empty
				completedMissions = new Mission(nextMissions->getName(), nextMissions->getCost(),nextMissions->getFaultProbability(),nextMissions->getMissionNumber(), nextMissions->getCompleted(),nextMissions->getPassengers(),nextMissions->getCrew());
				nextMissions->setNumMissions(nextMissions->getNumMissions() -1);
			}
			else{ //Completed mission is not empty
				Mission *temp = completedMissions;
				while(temp->next != NULL){
					temp = temp->next; //Go to the end of linked list
				}
				temp->next = new Mission(nextMissions->getName(), nextMissions->getCost(),nextMissions->getFaultProbability(),nextMissions->getMissionNumber(), nextMissions->getCompleted(),nextMissions->getPassengers(),nextMissions->getCrew());
				nextMissions->setNumMissions(nextMissions->getNumMissions() -1);
			}
			nextMissions = nextMissions->next;
			delete first; //Delete first element next mission
		}
		else{ //If mission failed
			cout << "Agency reschedules the mission." << endl;
			int profit = nextMissions->calculateProfit(this->ticketPrice);
			profit -= nextMissions->getCost();
			cash += profit;
			Mission *first = nextMissions;
			nextMissions = nextMissions->next;
			Mission *ptr = nextMissions;
			while(ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = new Mission(first->getName(), first->getCost(),first->getFaultProbability(),
			first->getMissionNumber(), first->getCompleted(),first->getPassengers(),first->getCrew()); //Add first element to last
			nextMissions->setNumMissions(nextMissions->getNumMissions() -1);
			delete first; //Delete first element
		}
	}
}

ostream& operator<< (ostream& os,Agency&agency) {
	os << "Agency name: " << agency.getName() << ", Total cash: " << agency.getCash() <<", Ticket Price:" << agency.getTicketPrice() << endl;
	os << "Next Missions:" << endl;
	if(agency.nextMissions == NULL){
		os << "No missions available." << endl;
	}
	else{
		Mission *temp1 = agency.nextMissions;
		while(temp1 != NULL){
			os <<"Mission number: " << (temp1)->getMissionNumber() << " Mission name: " << (temp1)->getName() << " Cost: " << (temp1)->getCost() << endl;
			temp1 = temp1->next;
		}
	}
	os << "Completed Missions:" << endl;
	if(agency.completedMissions == NULL){
		os << "No missions completed before." << endl;
	}
	else{
		Mission *temp2 = agency.completedMissions;
		while(temp2 != NULL){
			os <<"Mission number: " << (temp2)->getMissionNumber() << " Mission name: " << (temp2)->getName() << " Cost: " << (temp2)->getCost() << endl;
			temp2 = temp2->next;
		}
	}
	return os;
}
/*
Agency::~Agency(){
	Mission *ptr1 = this->nextMissions;
	while(ptr1 !=NULL){
		this->nextMissions = ptr1->next;
		delete ptr1;
		ptr1 = this->nextMissions;
	}

	Mission *ptr2 = this->completedMissions;
	while(ptr2 !=NULL){
		this->completedMissions = ptr2->next;
		delete ptr2;
		ptr2 = this->completedMissions;
	}
}*/


