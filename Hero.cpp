//Title: Hero.cpp
//Author: Adam Hereth
//Date: 10/4/2018
//Description: This is part of the Fortnite Dance Royale Project in CMSC 202 @ UMBC

#include "Hero.h"
#include <ctime>
Hero::Hero(){/*Default Constructor*/}
Hero::Hero(string name, bool isPlayer)
{
  SetName(name);
  GetIsPlayer();
}
string Hero::GetName()
{
  return m_name;
}
void Hero::SetName(string name)
{
  m_name = name;
}
bool Hero::GetIsPlayer()
{
  if(m_isPlayer)
    return true;
  else
    return false;
}

void Hero::DisplayDances()
{
	string typeStyle; 
  cout <<setw(12)<< "Dance" <<setw(15)<< "Style" <<setw(15)<< "Level" <<setw(16)<< "Difficulty" << endl;
  //loops the size of the dance from the hero and changes the style to Freestyle = 0, Breakin = 1, Silly = 2
  for(unsigned int i=0;i<m_dances.size();i++)
    {
	  if (m_dances.at(i).m_style == 0)
	  {
		  typeStyle = "Freestyle";
	  }
	  else if (m_dances.at(i).m_style == 1)
	  {
		  typeStyle = "Breakin";
	  }
	  else if (m_dances.at(i).m_style == 2)
	  {
		  typeStyle = "Silly";
	  }
      cout << i+1 << ". " <<setw(10)<< m_dances.at(i).m_name <<setw(15)<< typeStyle <<setw(10)
		   << m_dances.at(i).m_level <<setw(15)<< m_dances.at(i).m_difficulty << endl;
    }
  cout << setw(10) << setw(15) << setw(10) << setw(15);

}
//gets the size of the dance
int Hero::GetDanceCount()
{
  return m_dances.size();
}
//passes the newHero object to fight against the user's hero
bool Hero::DanceBattle(Hero& newHero)
{
  int choice = 0;
  int enemyAttack = 0;
  string heroicDance = "";
  int playerDance = 0;
  int enemyDance = 0;
  //gets number from 1 - 20, if the number is 1 call the HeroicDance and returns true so the Tournament can keep looping
  if ((rand() % 20 + 1) == 1)
  {
	  HeroicDance();
	  cout << heroicDance << endl;
	  return true;
  }
  else
	  //input checking
	  do
	  {
		  cout << "Choose a dance to FIGHT!!!" << endl;
		  DisplayDances();
		  cin >> choice;
	  } while (choice < 1 || choice > GetDanceCount());
	      //takes the user choice and does (choice-1) to get the index at the dances vector at m_difficulty and adds 1 to it
		  playerDance = m_dances.at(choice - 1).m_difficulty + 1;
		  //chooses a random dance for the enemies attack
		  enemyAttack = rand() % NUM_DANCES;
		  //calculates the "quality" of the enemies dance attacl. Level * Difficulty
		  enemyDance = newHero.m_dances.at(enemyAttack).m_level * (newHero.m_dances.at(enemyAttack).m_difficulty + 1);
		  if (enemyDance == playerDance)
		  {
			  cout << "Tied the round" << endl;
			  return true;
		  }
		  else if (playerDance > enemyDance)
		  {
			  cout << "Winner" << endl;
			  return true;
		  }
		  else
		  {
			  cout << "You Lose" << endl;
			  return false;
		  }
}

string Hero::HeroicDance()
{
	string heroicDance = "The Little Kicks Ep.138";
	return heroicDance;
}

void Hero::IncreaseDance(int i)
{
  if(m_dances.at(i).m_level < MAX_LEVEL)
    {
      cout << m_dances.at(i).m_name << " dance leveled up" << endl;
	  //takes the initial dance level and adds 1 to increase the level
      m_dances.at(i).m_level = m_dances.at(i).m_level + 1;
    }
  else
    cout << "Max level" << endl;
}
//takes the input and see's if the input is the same as the dance in the hero's dance vector
bool Hero::CheckDance(string input)
{
	unsigned int i = 0;
	while (i< m_dances.size())
	{
		if (input == m_dances.at(i).m_name)
			return true;
		else
			i++;
	}
	return false;
}
//d is a new newHero dance object
void Hero::AddDance(Dance d)
{
	if (m_dances.size() < NUM_DANCES)
	{
		m_dances.push_back(d);
	}
	else
		cout << "Max dances" << endl;
}
