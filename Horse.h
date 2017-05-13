/*
 * Horse.h
 *
 *  Created on: Apr 19, 2017
 *      Author: David Storey
 */

#ifndef HORSE_H_
#define HORSE_H_
#include<string>

namespace std {

class Horse {
public:
	string name, rider;
	int maxRunningDistPerSecond, distanceTraveled, racesWon;
	int toString(int), winTally(), getDistance(), getRecord();
	void getHorse(string), getRider(string), runASecond(), sendToGate();
	Horse();
	virtual ~Horse();
};

} /* namespace std */

#endif /* HORSE_H_ */
