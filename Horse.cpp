/*
 * Horse.cpp
 *
 *  Created on: Apr 19, 2017
 *      Author: David Storey
 */

#include "Horse.h"
#include <ctime>
#include <iostream>

namespace std {

Horse::Horse() {
	srand(time(0));
	maxRunningDistPerSecond = rand() % (100);
	racesWon = 0;
	distanceTraveled = 0;
}

int Horse::getDistance(){
	return distanceTraveled;
}

int Horse::getRecord(){
	return racesWon;
}

void Horse::runASecond(){
	distanceTraveled = distanceTraveled + (rand() % (maxRunningDistPerSecond));
}

void Horse::sendToGate(){
	distanceTraveled = 0;
}

int Horse::toString(int goalLength){
	int scale, display, hyphens, i, value;
	display = 10;
	cout << "|";
	scale = goalLength / display;
	hyphens = distanceTraveled / scale;
	if (distanceTraveled < goalLength){
		for(i = 0; i < hyphens; i++)
				cout << "-";
		if (i == hyphens)
				cout << ">";
		for (i = hyphens; i < display; i++)
				cout << " ";
		cout << "| ";
		value = 0;
	}
	else if (distanceTraveled >= goalLength){
		for ( i = 0; i < display; i++)
			cout << "-";
		cout << "-|> ";
		value = 1;
		}
	cout << name << " ridden by " << rider << endl;
	return value;
}

void Horse::getHorse(string horseName){
	name = horseName;
}

void Horse::getRider(string riderName){
	rider = riderName;
}

int Horse::winTally(){
	racesWon +=1;
	return racesWon;
}

Horse::~Horse() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
