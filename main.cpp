
#include "main.hpp"

void PrintGameStatistics(vector <Player*> Players)
{
	vector <Player*> :: iterator it;
	vector <string> :: iterator it2;
	vector <string> AttackNames,DefenseNames,MoneyNames;
	int BestAttack = 0,BestDefense = 0,Money = 0;
	for(it = Players.begin(); it != Players.end(); it++)
	{
		if((*it)->TotalAttack() > BestAttack)
		{
			BestAttack = (*it)->TotalAttack();
			AttackNames.erase(AttackNames.begin(),AttackNames.end());
			AttackNames.push_back((*it)->returnname());
		}
		else if((*it)->TotalAttack() == BestAttack)
			AttackNames.push_back((*it)->returnname());
		if((*it)->TotalDefense() > BestDefense)
		{
			BestDefense = (*it)->TotalDefense();
			DefenseNames.erase(DefenseNames.begin(),DefenseNames.end());
			DefenseNames.push_back((*it)->returnname());
		}
		else if((*it)->TotalDefense() == BestDefense)
			DefenseNames.push_back((*it)->returnname());
		if((*it)->returnmoney() > Money)
		{
			Money = (*it)->returnmoney();
			MoneyNames.erase(MoneyNames.begin(),MoneyNames.end());
			MoneyNames.push_back((*it)->returnname());
		}
		else if((*it)->returnmoney() == Money)
			MoneyNames.push_back((*it)->returnname());
	}
	cout <<"Printing General Game Statistics : "<<endl<<endl;
	if(AttackNames.size() > 1)
	{
		cout<<"The Players with the most Attack Points this round were : "<<endl;
		for(it2 = AttackNames.begin(); it2 != AttackNames.end(); it2++)
			cout<<*it2<<", ";
		cout<<endl<<endl<<"With Total Attack of : "<<BestAttack<<endl<<endl;
	}
	else
	{
		it2 = AttackNames.begin();
		cout<<"The Player with the most Attack Points this round was : "<<endl
			<<*it2<<endl<<endl
			<<"With Total Attack of : "<<BestAttack<<endl<<endl;
	}
	if(DefenseNames.size() > 1)
	{
		cout<<"The Players with the most Defense Points this round were : "<<endl;
		for(it2 = DefenseNames.begin(); it2 != DefenseNames.end(); it2++)
			cout<<*it2<<", ";
		cout<<endl<<endl<<"With Total Defense of : "<<BestDefense<<endl<<endl;
	}
	else
	{
		it2 = DefenseNames.begin();
		cout<<"The Player with the most Defense Points this round was : "<<endl
			<<*it2<<endl<<endl
			<<"With Total Defense of : "<<BestDefense<<endl<<endl;
	}
	if(MoneyNames.size() > 1)
	{
		cout<<"The Players with the most Money this round were : "<<endl;
		for(it2 = MoneyNames.begin(); it2 != MoneyNames.end(); it2++)
			cout<<*it2<<", ";
		cout<<endl<<endl<<"With Total Balance of : "<<Money<<endl<<endl;
	}
	else
	{
		it2 = MoneyNames.begin();
		cout<<"The Player with the most Money this round was : "<<endl
			<<*it2<<endl<<endl
			<<"With Total Balance of : "<<Money<<endl<<endl;
	}	
}

void PlayRound(vector <Player*> Players)
{
	vector <Player*> :: iterator it;
	static int NoOfRounds=1;
	cout << "Starting phase of this round begins" << endl;
	for(it = Players.begin();it != Players.end();it++)
		(*it)->StartingPhase(Players);
	cout << "Moving to equip phase of the round" << endl;
	for(it = Players.begin();it != Players.end();it++)	
		(*it)->EquipPhase();
	cout << "Moving to battle phase of the round" << endl;	
	if(NoOfRounds!=1)										//first round no battle phase can occur
	{
		for(it = Players.begin();it != Players.end();it++)	
			(*it)->BattlePhase(Players);
	}
	else
		cout << "Battle phase is skipped because it is still the first round of the game!" << endl;
	cout << "Moving to economy phase of the round" << endl;
	for(it = Players.begin();it != Players.end();it++)
		(*it)->EconomyPhase();
	NoOfRounds++;			//round is actually finished so increase it by one
	for(it = Players.begin();it != Players.end();it++)
	{
		(*it)->FinalPhase(Players);
		PrintGameStatistics(Players);		//print some interesting statistics at the end of each round
		cout << NoOfRounds << "rounds are completed so far!" << endl;
		if((*it)->CheckWinningCondition(Players)) //if a winner is found,the game has ended
		{
			cout << (*it)->returnname() << "wins the game!!!Congratulations!!!" << endl << "End of game!" << endl;
			return ;
		}
	}
	PlayRound(Players);
}

vector <Player*> CreatePlayers(vector <Player*> Players,int number)
{
	vector <Player*> :: iterator it;
	char j='1';
	for(int i=0 ; i< number ; i++)
		Players.push_back(new Player);
	for(it= Players.begin();it != Players.end();it++)
	{
		(*it)->CreateDeck();  //create the deck of every player
		(*it)->SetName(j);	//insert the name of every player
		j++;
	}
	for(it = Players.begin();it != Players.end();it++)
		(*it)->Begin();	//create their initial provinces and their strongholds
	return Players;
}

void InitializeGameBoard()
{
	vector <Player*> Players;
	vector <Player*> :: iterator it;
	int number;
	//cout << "How many players are going to participate in game?" << endl;
	//cin >> number;
	number = 2; //testing line
	Players=CreatePlayers(Players,number);
	cout << "A game was just created with" << number << "players!" << endl;
	PlayRound(Players);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	InitializeGameBoard();
	return 0;
}