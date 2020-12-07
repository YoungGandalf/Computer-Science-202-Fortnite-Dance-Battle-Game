//Title: Game.h
//Author: Adam Hereth
//Date: 10/4/2018
//Description: This is part of the Fortnite Dance Royale Project in CMSC 202 @ UMBC

#ifndef GAME_H //Header Guard
#define GAME_H //Header Guard

#include "Hero.h"
#include "Dance.h"
#include <fstream>

const string PROJ2_HEROES = "proj2_heroes.txt"; //File constant
const string PROJ2_DANCES = "proj2_dances.txt"; //File constant

class Game{
public:
  /* Name: Game() Default Constructor
  // Desc - Builds a new game
  */ 
  Game(); //Default Constructor
  // Name: LoadHeroes
  // Desc - Loads each hero into m_hero from file and 
  //        adds 5 dances to each enemy dancer (random style, difficulty, level)
  void LoadHeroes();
  // Name: LoadDances
  // Desc - Loads each dance into m_dances from file
  void LoadDances();
  // Name: StartGame()
  // Desc - Manages the game itself including win conditions continually
  //         calling the main menu 
  void StartGame();
  // Name: DisplayMyDances()
  // Desc - Displays the current dances (calls hero version of function)
  void DisplayDances();
  // Name: MainMenu()
  // Desc - Displays and manages menu
  int MainMenu();
  // Name: TrainDance()
  // Desc - Allows player to train a dance (increases skill)
  void TrainDance();
  // Name: LearnNewDance()
  // Desc - Allows player to learn a new dance based on difficulty (1. easy, 2. difficult, 3. epic)
  //        1 easy occurs 50% of the time, 2. Difficult occurs 25% of the time, 
  //        and 3. Epic occurs 10% of the time
  void LearnNewDance();
  // Name: EnterTournament()
  // Desc - Creates a tournament (winner stay on) for 1-10 enemy dancers
  // Randomly chooses defined number of enemy dancers for tournament
  // Player chooses a dance from their list. Player quality is level * difficulty
  // Enemy dancer randomly chooses a dance and quality is level * difficulty
  void EnterTournament();
private:
  vector <Hero> m_heroes; //All enemy heroes in game (loaded from file)
  vector <Dance> m_dances; //All dances in the game (loaded from file)
  Hero m_myHero; //Player's hero
  string m_name; //Player's name
};

#endif //Exit Header Guard
