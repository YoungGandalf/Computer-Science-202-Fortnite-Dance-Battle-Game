//Title: Hero.h
//Author: Adam Hereth
//Date: 10/4/2018
//Description: This is part of the Fortnite Dance Royale Project in CMSC 202 @ UMBC

#ifndef HERO_H //Include/Header Guard
#define HERO_H //Include/Header Guard

#include "Dance.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>
using namespace std;

//Constants (allowed to add more as needed)
const int MIN_LEVEL = 1;
const int MAX_LEVEL = 10;
const int NUM_DANCES = 5;

//Hero class - allowed to add HELPER functions only

class Hero{
 public:
  // Name: Hero() - Default Constructor (unused)
  // Desc: Used to build a new hero
  // Preconditions - Requires default values
  // Postconditions - Creates a new hero
  Hero();
  // Name: Hero(name, isPlayer, isSeen, level) - Overloaded constructor
  // Desc - Used to build a new hero (player or enemy)
  // Preconditions - Requires name and isPlayer
  // Postconditions - Creates a new hero
  Hero(string name, bool isPlayer);
  // Name: GetName()
  // Desc - Getter for Hero name
  // Preconditions - Hero exists
  // Postconditions - Returns the name of the hero
  string GetName();
  // Name: SetName(string)
  // Desc - Allows the user to change the name of the hero
  // Preconditions - Hero exists
  // Postconditions - Sets name of hero
  void SetName(string name);
  // Name: GetIsPlayer()
  // Desc - Getter for if hero is a player or a non-player character (computer)
  // Preconditions - Hero Exists
  // Postconditions - Returns true (is user) or false (is computer)
  bool GetIsPlayer();
  // Name: IncreaseLevel()
  // Desc - After a hero wins a fight, if possible, levels up
  // Preconditions - Heros exist
  // Postconditions - If possible, curLevel increases, if increases, returns true else false
  bool IncreaseLevel();
  // Name: DisplayDances()
  // Desc - Displays a numbered list of all dance moves known by the player
  // Preconditions - Heros exist
  // Postconditions - None
  void DisplayDances();
  // Name: GetDanceCount()
  // Desc - Returns number of dances known by hero
  // Preconditions - Heros exist
  // Postconditions - None
  int GetDanceCount();
  // Name: DanceBattle(Hero&)
  // Desc - Allows the user to dance attack an enemy hero
  // Preconditions - Heros exist
  // Postconditions - Returns if hero hero wins fight (true wins, false loses)
  bool DanceBattle(Hero&);
  // Name: HeroicDance(Hero&)
  // Desc - Allows the user to attack an enemy hero using a special dance
  //        Returns the string of the specific dance
  // Preconditions - During normal attack, 5% chance a special dance attack called
  // Postconditions -  Automatically wins fight
  string HeroicDance();
  // Name: IncreaseDance(int)
  // Desc - Increases level of a dance up to 100 (value passed is index of dance to increase)
  // Preconditions - Hero has dances
  // Postconditions - None
  void IncreaseDance(int);
  // Name: CheckDance(string)
  // Desc - Checks the player to see if they know a specifice dance by name
  // Preconditions - Hero has dances
  // Postconditions - Returns true if player already has dance, else false
  bool CheckDance(string);  
  // Name: AddDance(Dance)
  // Desc - Adds a new dance to the player's dance list
  // Preconditions - Hero does not already know this dance
  // Postconditions - Dance is added (level 1)
  void AddDance(Dance);
 private:
  string m_name; //Name of Hero
  bool m_isPlayer; //Identifies user controled (true) or computer controlled (false)
  vector<Dance> m_dances; //List of known dance styles
};

#endif //Exit Header Guard
