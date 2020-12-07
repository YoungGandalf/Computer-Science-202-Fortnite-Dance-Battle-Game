//Title: Game.cpp
//Author: Adam Hereth
//Date: 10/4/2018
//Description: This is part of the Fortnite Dance Royale Project in CMSC 202 @ UMBC

#include "Game.h"
#include <ctime>

Game::Game()
{
  //seeds srand
  srand(time(NULL));
  string m_name; 
  cout << "What is your name?" << endl;
  cin >> m_name;
  //sets hero name
  m_myHero.SetName(m_name); 
  LoadDances();
  LoadHeroes();
  //sets the first dance of the hero to the index 0 of the dance vector
  m_myHero.AddDance(m_dances.at(0)); 
}     

void Game::LoadHeroes()
{
  ifstream infile;
  string enemyHero;
  infile.open(PROJ2_HEROES.c_str());
  if (infile.is_open())
  {
	  while (getline(infile, enemyHero))
	  {
		  //checks to see if the hero is the user or computer
		  Hero newHero(enemyHero, false);
		  for (int i = 0; i < 5; i++)
		  {
			  int randDance = rand() % int(m_dances.size());
			  newHero.AddDance(m_dances.at(randDance));
		  }
		  m_heroes.push_back(newHero);
	  }
	  infile.close();
  }
  else
    cout << "file not found" << endl;
}
void Game::LoadDances()
{
	ifstream infile;
	infile.open(PROJ2_DANCES.c_str());
	string name;
	int difficulty, style;
	if (infile.is_open())
	{
		while (getline(infile, name, ','))
		{
			infile >> style;
			if (infile.peek() == ',')
				infile.ignore(10, ',');
			infile >> difficulty;
			if (infile.peek() == '\n')
				infile.ignore(10, '\n');
			m_dances.push_back(Dance(name, style, difficulty, 1));
		}
		infile.close();
	}
	else
		cout << "Invalid file" << endl;
}

void Game::StartGame()
{
	int menu;
  do
    {
      cout << "What would you like to do?" << endl;
      cout << "1. Display Dances" << endl;
      cout << "2. Train Dance Move" << endl;
      cout << "3. Learn New Dance" << endl;
      cout << "4. Enter Dance Tournament" << endl;
      cout << "5. Quit" << endl;
      menu = MainMenu();
      if(menu==1)
	m_myHero.DisplayDances();
      else if(menu==2)
	TrainDance();
      else if(menu==3)
	LearnNewDance();
      else if(menu==4)
	EnterTournament();
      else if(menu<1 || menu>5)
	cout << "invalid option" << endl;
    }
  while(menu != 5);
}
void Game::DisplayDances()
{
	for (unsigned int i = 0; i < m_dances.size(); i++)
	{
		cout << i + 1 << ". " << m_dances.at(i).m_name << " " << m_dances.at(i).m_style << " "
			<< m_dances.at(i).m_level << " " << m_dances.at(i).m_difficulty << endl;
	}
}
int Game::MainMenu()
{
  int x;
  cout << "Please enter a number" << endl;
  cin >> x;
  return x;
}
void Game::TrainDance()
{
  cout << "Which dance would you like to train?" << endl;
  m_myHero.DisplayDances();
  int i;
  cin >> i;
  while(i>m_myHero.GetDanceCount() || i<1)
    {
	cout << "invalid choice please try again" << endl;
	cin >> i;
    }
  int randNum = rand() %2+1;
  if(randNum == 1)
    {
      m_myHero.IncreaseDance(i-1);
    }
  else
    cout << "Did not level up" << endl;
  
}
void Game::LearnNewDance()
{
	cout << "What difficulty of dance would you like to learn" << endl;
	int menu;
	int easyDanceNum;//30 (Dance 0 to 30)
	int diffDanceNum = 30;//41 (Dance 31+72)
	int hardDanceNum = 72;//21 (Dance 73 to 93)
	int rand1;
	int rand2;
	int rand3;
	int temp;
	cout << "1. Easy" << endl;
	cout << "2. Difficult" << endl;
	cout << "3. Epic" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
		rand1 = rand() % 2 + 1;
		if (rand1 == 1)
		{
			easyDanceNum = rand() % 30 + 1;
			if (m_myHero.CheckDance(m_dances.at(easyDanceNum).m_name) == false)
			{
				m_myHero.AddDance(m_dances.at(easyDanceNum - 1));
				cout << "Congrats!!! You learned a new dance called " << m_dances.at(easyDanceNum - 1).m_name << endl;
			}
			else
				cout << "You cannot learn the same dance" << endl;
		}
		else
			cout << "Failed to learn new dance" << endl;
		break;
	case 2:
		rand2 = rand() % 4 + 1;
		if (rand2 == 1)
		{
			temp = rand() % 41 + 1;
			diffDanceNum = diffDanceNum + temp;
			if (m_myHero.CheckDance(m_dances.at(diffDanceNum).m_name) == false)
			{
				m_myHero.AddDance(m_dances.at(diffDanceNum - 1));
				cout << "Congrats!!! You learned a new dance called " << m_dances.at(diffDanceNum - 1).m_name << endl;
			}
			else
				cout << "You cannot learn the same dance" << endl;
		}
		else
			cout << "Failed to learn new dance" << endl;
		break;
	case 3:
		rand3 = rand() % 10 + 1;
		if (rand3 == 1)
		{
			temp = rand() % 21 + 1;
			hardDanceNum = hardDanceNum + temp;
			cout << hardDanceNum << endl;
			if (m_myHero.CheckDance(m_dances.at(hardDanceNum).m_name) == false)
			{
				m_myHero.AddDance(m_dances.at(hardDanceNum - 1));
				cout << "Congrats!!! You learned a new dance called " << m_dances.at(hardDanceNum - 1).m_name << endl;
			}
			else
				cout << "You cannot learn the same dance" << endl;
		}
		else
			cout << "Failed to learn new dance" << endl;
		break;
	default:
		cout << "Invalid input please try again" << endl;
	}
}
void Game::EnterTournament()
{
  cout << "You have entered the tournament" << endl;
  cout << "How many players would you like to fight(1-10)?" << endl;
  int players;
  cin >> players;
  if (players > 0 && players <= 10)
  {
	  int count = 0;
	  bool x = true;
	  while (players > count && x)
	  {
		  int oppPlayer = rand() % m_heroes.size();
		  x = m_myHero.DanceBattle(m_heroes.at(oppPlayer));
		  count++;
	  }
  }
  else
	  cout << "Invalid amount of players" << endl;
}
