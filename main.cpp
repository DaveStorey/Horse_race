/*
 * main.cpp

 *
 *  Created on: Apr 19, 2017
 *      Author: David Storey
 */
#include <iostream>
#include <string>
#include "Horse.h"
using namespace std;


//Function for getting the horses and riders and running the race.

Horse *race(Horse *, int &);


int main(){

	/*Variables for (respectively): char for starting/continuing, int for number of horses to be raced,
	 two ints for checking the winner, and a Horse pointer for the racers.*/

	char start;
	int numHorses, wonTheRace, winnerDistance;
	Horse *racers = nullptr;
	cout << "Would you like to watch a horse race? (y/n)";
	cin >> start;

	//Sanity check on input

	while (start != 'y' && start != 'Y' && start != 'n' && start != 'N'){
		cout << "Invalid entry, please enter y or n.";
		cin >> start;
	}
	while (start == 'y' || start == 'Y'){
		racers = race(racers, numHorses);
		winnerDistance = 0;

		//For loop determining which horse ran the farthest, in case multiple horses pass the finish line.

		for (int i = 0; i < numHorses; i++){
			int x = racers[i].getDistance();
			if (x > winnerDistance){
				winnerDistance = racers[i].getDistance();
				wonTheRace = i;
			}
		}

		//Tallying the win for the horse that went the farthest and outputting the result and running tally.

		racers[wonTheRace].winTally();
		cout << "The winner is: " << racers[wonTheRace].name << " ridden by " << racers[wonTheRace].rider << endl;
		cout << "Win tally: \n -----------------------------------\n";
		for (int i = 0; i < numHorses; i++)
			cout << racers[i].name << " has " << racers[i].racesWon << " wins.\n";
		cout << "Would you like to run another race?";
		cin >> start;

		//Sanity check

		while (start != 'y' && start != 'Y' && start != 'n' && start != 'N'){
			cout << "Invalid entry, please enter y or n.";
			cin >> start;
		}
	}

	//Deleting dynamically allocated array.

	delete []racers;
	return 0;
}

//Function for getting the horses and running the race, returning a pointer to the array of racers.

Horse *race(Horse * racers, int & numHorses){

	/*Variables for (respectively): static int for ensuring the racers aren't reset every race,
	int for the race length, flag int for when a horse has finished, char for starting/continuing,
	and two strings for getting the horse's and rider's names.*/

	static int races = 0;
	int goalLength, finisher = 1;
	char startGun;
	string name, rider;

	//If statement with static int to keep from resetting the horses every race.

	if (races == 0){
		cout << "How many horses would you like to race?";
		cin >> numHorses;

		//Dual sanity check on the number of horses to race, disallowing 0 or negative number, and confirming if the number is too high.

		while (numHorses < 1){
			cout << "Cannot race that number of horses. Please try again.";
			cin >> numHorses;
		}
		if (numHorses > 10){
			cout << "That is a large number of horses. Please confirm by reentering the number of horses you would like to race.";
			cin >> numHorses;
		}
		racers = new Horse[numHorses];
		cin.ignore();
		for (int i = 0; i < numHorses; i++){
			cout << "What is one horse's name?";
			getline(cin, name);
			cout << "What is that horse's rider's name?";
			getline(cin, rider);
			racers[i].getHorse(name);
			racers[i].getRider(rider);
		}
	}

	//Resetting the distance traveled for each race.

	for(int i = 0; i < numHorses; i++){
		racers[i].sendToGate();
	}
	cout << "How long would you like the race to be?";
	cin >> goalLength;

	//Dual sanity checks, disallowing 0 and negative numbers, and confirming large numbers.

	while (goalLength < 0){
		cout << "Invalid distance, please reenter.";
		cin >> goalLength;
	}
	if (goalLength > 2000){
		cout << "That is a long race, please confirm by reentering your desired race distance.";
		cin >> goalLength;
	}
	cout << "Would you like to fire the starting gun? (y/n) ";
	cin >> startGun;

	//Sanity check on input.

	while (startGun != 'y' && startGun != 'Y' && startGun != 'n' && startGun != 'N'){
			cout << "Invalid entry, please enter y or n.";
			cin >> startGun;
		}
	while ((startGun == 'y' || startGun == 'Y') && finisher == 1){
		for (int i = 0; i < numHorses; i++){
			racers[i].runASecond();
			if (racers[i].toString(goalLength)){
				finisher = 0;
			}
		}
		if (finisher){
			cout << "Would you like to continue the race? (y/n)";
			cin >> startGun;
		}

		//Sanity check

		while (startGun != 'y' && startGun != 'Y' && startGun != 'n' && startGun != 'N'){
			cout << "Invalid entry, please enter y or n.";
			cin >> startGun;
		}
	}
	races = 1;
	return racers;
}
