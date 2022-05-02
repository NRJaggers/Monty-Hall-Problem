/*******************************************************
PROGRAM NAME - Monty Hall Problem

PROGRAMMER - Nathan Jaggers

DATE - 04/26/22

DESCRIPTION - This program implements the Monty Hall
              Problem and shows how it is statisctically
              advantangous to switch your guess during
              the problem.

*******************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool montyHallGame(bool);

int main()
{
    //initialize random 
     srand (time(0));

    //create variables to hold stats
    int iterations = 5000, winsNoSwitch = 0, winsSwitch = 0;
    float probNoSwitch, probSwitch ;

    //welcome message, explain the program
    cout << "Welcome to the Monty Hall Problem!\n"
         << "Here we play the game and see how\n"
         << "switching doors leads to higher probability\n"
         << "of winning the car.\n";

    //game no switching
    cout << "Running game for " << iterations 
         << " iterations without switching.\n";

        for (int i = 0; i < iterations; i++)
        {
            if(montyHallGame(false))
                winsNoSwitch++;
        }

    //game with switching
    cout << "Running game for " << iterations 
         << " iterations with switching.\n";
        for (int i = 0; i < iterations; i++)
        {
            if(montyHallGame(true))
                winsSwitch++;
        }

    //results
    probNoSwitch = (float)winsNoSwitch/iterations;
    probSwitch = (float)winsSwitch/iterations;

    cout << "Game Stats:\n" 
         << "Games played: "<< iterations*2 << endl
         << "Games won without switching: " << winsNoSwitch << endl
         << "Probability winning without switching: " << probNoSwitch << endl 
         << "Games won with switching: " << winsSwitch << endl
         << "Probability winning with switching: " << probSwitch << endl ;

    return 0;
}

bool montyHallGame(bool switchGuess)
{
    /** This function will conduct the game where there
     * three doors and behind those door are two sheep
     * and a new car. After the first selection on the
     * doors, one of the sheeps will be revealed. Then
     * there will be an option to switch the doors or
     * stay with the current pick.
     * 
     * Input:
     * The fuction will take in a boolean input where
     * 0 is the choice not to switch and 1 is to switch.
     * 
     * Output:
     * The function will return a boolean variable representing
     * if the guess was correct or not, 0 for false and 1 for true.
     * 
     * Setup of the door and selection of the doors will be
     * handled by the program.
    */

    // create variables to conduct game and store results
    bool doors[3], correctGuess = false; 
    int guess, sheepDoor1, car;

    // set one random door in the array to be the car
    car = rand() % 3;
    for(int i = 0; i<3; i++)
        doors[i] = false;
    doors[car] = true;

    // set the guess for the correct door
    guess = rand() % 3;

    // reveal one of the sheep doors
    // find out a door with a sheep behind it
    for(int i = 0; i < 3; i++)
    {
        if ((i!=guess) & (doors[i]==0))
            sheepDoor1 = i;
    }

    // offer the chance to switch doors
    if (switchGuess)
    {
        for(int i = 0; i < 3; i++)
        {
            // switch to door that isn't revealed
            // and isn't current guess
            if ((i!=guess) & (i!=sheepDoor1))
            {
                guess = i;
                break;
            }

        }
    }

    //evaluate and return result
    correctGuess = (guess == car) ;

    return correctGuess;
}

