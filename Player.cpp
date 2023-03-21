#include "Player.hpp"

void Player :: SetName(char j) 
{ 
	Name = "player";  //name is player[number]
	Name.push_back(j);		//push at the end of the string their corresponding number
	cout << Name << endl; 
}
void Player :: Begin()
{
	int i = 0;
	hidden = 1;
	Property.push_back(&StrongHold);
	for(i=0;i<5;i++)
		DrawGreenCard();
	for(i=0;i<4;i++)
		DrawBlackCard();
}
void Player :: CreateDeck()
{
	ifstream fatedeckstats("fatedeckstats.txt");	//open the txt file with the Green Cards's stats
	ifstream dynastydeckstats("dynastydeckstats.txt");	//open the txt file with the Black Cards'stats
	vector <GreenCard> tempGDeck;	//create a temporary vector
	vector <BlackCard> tempBDeck;	//create a temporary vector
	int i;
    for (i = 0; i < 11; i++)
	{
		GreenCard G;	
		int costtemp, adtemp, deftemp, mintemp, effectbtemp, effectctemp, durabilitytemp;
		string tempname;
		fatedeckstats >> tempname >> costtemp >> adtemp >> deftemp >> mintemp >> effectbtemp >> effectctemp;//the first 6 are followers
		if (i > 5)
			fatedeckstats >> durabilitytemp;	//if i is greater than 5 ,then these are items and not followers
		tempGDeck.push_back(G);	//push back the created card 
		tempGDeck[i].setdatabasestatsgreen(costtemp, adtemp, deftemp, mintemp, effectbtemp, effectctemp, tempname, durabilitytemp, i);//call a function to set the stats of each card
	}
	FillGreenDeck(tempGDeck);	//call the function to create the deck that will be used throughout the game
	for (i = 0; i < 12; i++)
	{
		BlackCard B;
		string tempname;
		int costtemp,adtemp, deftemp, honortemp,harvesttemp;
		if (i < 5)	//if i is smaller than 5,these are Personalities
		{
			dynastydeckstats >> tempname >> costtemp >> adtemp >> deftemp >> honortemp;	//take the necessary stats
			tempBDeck.push_back(B);	//push back the created card
			tempBDeck[i].setdatabasestatsblack(costtemp,tempname,adtemp,deftemp,honortemp,harvesttemp,i);	//set their stats
		}	
		else if (i < 11)	//if 5 < i < 11 ,these are Holdings
		{
			dynastydeckstats >> tempname >> costtemp >> harvesttemp;	//take the necessary stats
			tempBDeck.push_back(B);	//push back the created card
			tempBDeck[i].setdatabasestatsblack(costtemp,tempname,adtemp,deftemp,honortemp,harvesttemp,i);	//set their stats
		}
		if(i == 11)	//if i = 11 we know its the Stronghold
		{
			dynastydeckstats >> tempname >> honortemp >> deftemp >> harvesttemp;	//take the necessary stats
			StrongHold.setdatabasestatsblack(costtemp,tempname,adtemp,deftemp,honortemp,harvesttemp,i);	//set its stats
		}
	}
	FillBlackDeck(tempBDeck);	//call a function that creates the deck that will be used throughout the game
}
void Player :: FillGreenDeck(vector <GreenCard> tempDeck)
{
	vector <GreenCard> :: iterator it;
	int i, j;
    j = 0;
	for (i = 0; i < NO_FOOTSOLDIER; i++)
		Deck1.push_back(tempDeck[j]);	//push back the first card of the temp deck (because we know it is the FOOTSOLDIER)
	j++;
	for (i = 0; i < NO_ARCHER; i++)
		Deck1.push_back(tempDeck[j]);	//push back the second card of the temp deck (because we know it is the ARCHER)
	j++;
	for (i = 0; i < NO_SIEGER; i++)
		Deck1.push_back(tempDeck[j]);	//push back the third card of the temp deck (because we know it is the SIEGER)
	j++;
	for (i = 0; i < NO_CAVALRY; i++)
		Deck1.push_back(tempDeck[j]);	//push back the fourth card of the temp deck (because we know it is the CAVALRY)
	j++;
	for (i = 0; i < NO_NAVAL; i++)
		Deck1.push_back(tempDeck[j]);	//push back the fifth card of the temp deck (because we know it is the NAVAL)
	j++;
	for (i = 0; i < NO_BUSHIDO; i++)	
		Deck1.push_back(tempDeck[j]);	//push back the sixth card of the temp deck (because we know it is the BUSHIDO)
	j++;
	for (i = 0; i < NO_KATANA; i++)
		Deck1.push_back(tempDeck[j]);	//push back the seventh card of the temp deck (because we know it is the KATANA)
	j++;
	for (i = 0; i < NO_SPEAR; i++)
		Deck1.push_back(tempDeck[j]);	//push back the eighth card of the temp deck (because we know it is the SPEAR)
	j++;
	for (i = 0; i < NO_BOW; i++)
		Deck1.push_back(tempDeck[j]);	//push back the ninth card of the temp deck (because we know it is the BOW)
	j++;
	for (i = 0; i < NO_NINJATO; i++)
		Deck1.push_back(tempDeck[j]);	//push back the tenth card of the temp deck (because we know it is the NINJATO)
	j++;
	for (i = 0; i < NO_WAKIZASHI; i++)
		Deck1.push_back(tempDeck[j]);	//push back the eleventh card of the temp deck (because we know it is the WAKIZASHI)
	i = 0;	
	for(it = Deck1.begin();it!=Deck1.end();it++)
	{
		FateDeck.push_back(&Deck1[i]);	//push back every card from the Deck(whose cards are type <GreenCard>) to a vector whose cards a type <GreenCard*> 
		i++;	//so we use the deck consisted of pointers and not the other one
	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();	//take a random seed
	shuffle(FateDeck.begin(),FateDeck.end(),default_random_engine(seed));	//shuffle the deck that way,so it is different every time
	//PrintGreenCards(FateDeck);
}
void Player :: FillBlackDeck(vector <BlackCard> tempdeck)	//fill the dynasty deck
{
	vector <BlackCard> :: iterator it;
	int i, j;
	j = 0;
	for (i = 0; i < NO_ATTACKING; i++)	
		Deck2.push_back(tempdeck[j]);	//push back the first card of the temp deck (because we know it is the ATTACKER)
	j++;
	for (i = 0; i < NO_DEFENSIVE; i++)
		Deck2.push_back(tempdeck[j]); 	//push back the second card of the temp deck (because we know it is the DEFENDER)
	j++;
	for (i = 0; i < NO_SHOGUN; i++)
		Deck2.push_back(tempdeck[j]);	//push back the third card of the temp deck (because we know it is the SHOGUN)
	j++;
	for (i = 0; i < NO_CHANCELLOR; i++)
		Deck2.push_back(tempdeck[j]);	//push back the fourth card of the temp deck (because we know it is the CHANCELLOR)
	j++;
	for (i = 0; i < NO_CHAMPION; i++)
		Deck2.push_back(tempdeck[j]);	//push back the fifth card of the temp deck (because we know it is the CHAMPION)
	j++;
	for (i = 0; i < NO_SOLO ; i++)
		Deck2.push_back(tempdeck[j]);	//push back the sixth card of the temp deck (because we know it is the SOLO)
	j++;
	for (i = 0; i < NO_PLAIN; i++)	
		Deck2.push_back(tempdeck[j]);	//push back the seventh card of the temp deck (because we know it is the PLAIN)
	j++;
	for(i = 0; i< NO_FARMS; i++)
		Deck2.push_back(tempdeck[j]);	//push back the eighth card of the temp deck (because we know it is the FARMS)
	j++;
	for (i = 0; i < NO_MINE; i++)
		Deck2.push_back(tempdeck[j]);	//push back the ninth card of the temp deck (because we know it is the MINE)
	j++;
	for (i = 0; i < NO_GOLD_MINE; i++)
		Deck2.push_back(tempdeck[j]);	//push back the tenth card of the temp deck (because we know it is the GOLD MINE)
	j++;
	for (i = 0; i <NO_CRYSTAL_MINE; i++)
		Deck2.push_back(tempdeck[j]);	//push back the eleventh card of the temp deck (because we know it is the CRYSTAL MINE)
	i = 0;
	for(it = Deck2.begin();it!=Deck2.end();it++)
    {
		DynastyDeck.push_back(&Deck2[i]);	//push back every card from the Deck(whose cards are type <BlackCard>) to a vector whose cards a type <BlackCard*> 
		i++;		//so we use the deck consisted of pointers and not the other one
	}
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();	//take a random seed
	shuffle(DynastyDeck.begin(),DynastyDeck.end(),default_random_engine(seed));	//shuffle the deck that way,so it is different every time
	//PrintBlackCards(DynastyDeck);
}
void Player :: AddChainNode(BlackCard* OwnedCard)
{
	Chain C;					//get our new object
	ChainList.push_back(C);		//push it into our list of chains
	if( OwnedCard->returnname() == "MINE")		//three cases , each one for the unique type of holding
	{	//for mine,the subHolding of the chain do the corresponding initialization of the new node
		ChainList.back().SubName = OwnedCard->returnname();
		ChainList.back().SubHolding=OwnedCard;
		ChainList.back().CurrentHolding=NULL;
		ChainList.back().UpperHolding=NULL;	
		ChainList.back().CurrentName = "";
		ChainList.back().UpperName = "";
	}
	else if(OwnedCard->returnname() == "GOLD_MINE")
	{	//for gold_mine,the MidHolding of the chain do the corresponding initialization of the new node
		ChainList.back().CurrentName = OwnedCard->returnname();
		ChainList.back().CurrentHolding=OwnedCard;
		ChainList.back().SubHolding=NULL;
		ChainList.back().UpperHolding=NULL;	
		ChainList.back().SubName = "";
		ChainList.back().UpperName = "";
	}
	else{ //for crystak_mine,the UpperHolding of the chain do the corresponding initialization of the new node
		ChainList.back().UpperName = OwnedCard->returnname();
		ChainList.back().UpperHolding=OwnedCard;
		ChainList.back().SubHolding=NULL;
		ChainList.back().CurrentHolding=NULL;	
		ChainList.back().SubName = "";
		ChainList.back().CurrentName = "";
	}
}
int Player :: ChainListFunc(BlackCard* OwnedCard)
{
	vector <Chain>::iterator it;
	string NameOwnedCard=OwnedCard->returnname();
	int flag=0,flag2=0;
	if(NameOwnedCard == "MINE") //depending on what holding is, list is iterated for the right chain member
	{
		flag2++;  //yes indeed the new OwnedCard is chain and it shouldnt be inserted in property vector
		for( it=ChainList.begin(); it!=ChainList.end(); it++)
		{
			if(it->SubHolding == NULL)
			{
				it->SubHolding=OwnedCard;  //do the linking
				it->SubName=NameOwnedCard;
				flag=1;	//if it found an existant node that has not the corresponding holding already,flag it
				if(it->CurrentHolding != NULL) //if the mine is connected to an existant gold mine do the change
				{
					it->SubHolding->ModifyHarvest("addition",2);
					if(it->UpperHolding==NULL) //if crystal mine is missing then gold mine has addition
						it->CurrentHolding->ModifyHarvest("addition",4); 
					else //if a full chain was made then double the gold mine and triple the crystal mine harvest
					{    //gold mine harvest is actually already doubled due to +5 bonus with crystal mine chain
						it->UpperHolding->ModifyHarvest("multiplication",1.5); //already doubled,and needed to be tripled
					}
				}
				break; //if you found the first empty spot don't traverse the following chain lists 
			}	
		}
		if(!flag)  //if flag still zero,no existant node was found for the holding type so a new one is created
			AddChainNode(OwnedCard); //since it's a new chain(node) no harvest changes can occur
	}
	else if(NameOwnedCard == "GOLD_MINE") 
	{
		flag2++;  //yes indeed the new OwnedCard is chain and it shouldnt be inserted in property vector
		for(it=ChainList.begin(); it!=ChainList.end(); it++)
		{
			if(it->CurrentHolding == NULL)
			{
				it->CurrentHolding=OwnedCard;
				it->CurrentName=NameOwnedCard;
				flag=1;  //if it found an existant node that has not the corresponding holding already,flag it
				if(it->SubHolding!= NULL && it->UpperHolding== NULL)
				{	//if gold mine got chained only with mine ,missing crystal mine
					it->CurrentHolding->ModifyHarvest("addition",4);
					it->SubHolding->ModifyHarvest("addition",2);
				}
				else if(it->SubHolding== NULL && it->UpperHolding!= NULL)
				{	//if gold mine got chained only with crystal mine ,missing mine
					it->CurrentHolding->ModifyHarvest("addition",5);
					it->UpperHolding->ModifyHarvest("multiplication",2);
				}
				else //if gold mine completed fully the chain , then all 3 holdings have modifications
				{
					it->SubHolding->ModifyHarvest("addition",2);
					it->CurrentHolding->ModifyHarvest("multiplication",2);
					it->UpperHolding->ModifyHarvest("multiplication",3);
				}
				break; //if you found the first empty spot don't traverse the following chain lists 
			}	
		}
		if(!flag) //if flag still zero,no existant node was found for the holding type so a new one is created
			AddChainNode(OwnedCard);  //since it's a new chain(node) no harvest changes can occur
	}
    else if(NameOwnedCard == "CRYSTAL_MINE") 
	{
		flag2++;  //yes indeed the new OwnedCard is chain and it shouldnt be inserted in property vector
		for(it=ChainList.begin(); it!=ChainList.end(); it++)
		{
			if(it->UpperHolding == NULL)
			{
				it->UpperHolding=OwnedCard;
				it->UpperName=NameOwnedCard;
    			flag=1; //if it found an existant node that has not the corresponding holding already,flag it
				if(it->SubHolding == NULL && it->CurrentHolding != NULL)
				{  //if crystal mine got chained only with gold mine , missing mine
					it->CurrentHolding->ModifyHarvest("addition",5);
					it->UpperHolding->ModifyHarvest("multiplication",2);
				}
				else if(it->SubHolding != NULL && it->CurrentHolding != NULL) 
				{ //if crystal mine completed fully the chain , mine does not get any additional bonus
					it->CurrentHolding->ModifyHarvest("addition",1); //since it has +4 bonus already to get doubled needs one more
					it->UpperHolding->ModifyHarvest("multiplication",3);
				}
				break; //if you found the first empty spot don't traverse the following chain lists 
			}	
		}
		if(!flag) //if flag still zero,no existant node was found for the holding type so a new one is created
			AddChainNode(OwnedCard);  //since it's a new chain(node) no harvest changes can occur
	}
}
void Player :: DrawGreenCard()
{
	vector <GreenCard*> :: iterator it;
	it = FateDeck.begin();
	Hand.push_back(*it);   //Transfer first card of fate deck to the hand of the player (drawing)
	FateDeck.erase(it);   //Deleting from the fate deck the drawn card 
}
void Player :: DrawBlackCard()
{
	vector <BlackCard*> :: iterator it,it2;
	it = Provinces.begin();
	it2 = DynastyDeck.begin();
	if(Provinces.size()<4)  //provinces must be at most 4
	{
		Provinces.push_back(*it2);  //Transfer black card to the province empty spot of the player
		DynastyDeck.erase(it2);     //delete from the dynasty deck the drawn card
	}	
}
void Player :: StartingPhase(vector <Player*> Players)
{
	vector <BlackCard*> :: iterator it;
	UntapEverything();		//untap all the cards
	DrawGreenCard();	//draw a new Green Card
	hidden = 0;
	cout<<"Printing " << this->Name  << " Hand  :" <<endl<<endl;
	PrintGreenCards(Hand);
	cout<<"Printing " << this->Name << " Provinces : " <<endl<<endl;
	PrintBlackCards(Provinces);
}
void Player :: UntapEverything()
{
	vector <BlackCard*> :: iterator it;
	vector <Chain> :: iterator it2;
	vector <GreenCard*> :: iterator it3;
	vector <GreenCard*> temp;
	for(it = Army.begin();it!=Army.end();it++)
	{
		(*it)->SetTap(0);	//untap the Army cards
		temp = (*it)->returnattached();
		for(it3 = temp.begin(); it3 != temp.end(); it3++)
			(*it3)->SetTap(0);
	}
	for(it = Provinces.begin();it!=Provinces.end();it++)
		(*it)->SetTap(0);	//untap the Provinces cards
	for(it = Property.begin(); it!=Property.end();it++)
		(*it)->SetTap(0);	//untap the Properties cards (we use the Istapped variable during the economy phase,so the user can't tap the same property twice)
	for(it2 = ChainList.begin() ;it2!= ChainList.end(); it2++)
	{
		it2->CurrentHolding->SetTap(0);	//same as the Properties vector above
		it2->SubHolding->SetTap(0);
		it2->UpperHolding->SetTap(0);
	}
}
void Player :: EquipPhase()
{
	if(Army.size()>0)
	{
		string temp;
		cout<<"Do you wish to tap your Holdings in order to attach a card?"<<endl
			<<"Please note you will not have this option again in the Equip Phase!"<<endl
			<<"Press YES if you wish to tap"<<endl<<endl;
		cin>>temp;
		if(temp == "YES")
			ChooseHoldings();
		cout<<"Printing " << this->Name <<" Army : "<<endl<<endl;
		PrintBlackCards(Army);
		cout<<"Printing "<< this->Name <<" Hand : "<<endl<<endl;
		PrintGreenCards(Hand);
		EquipPhase2();
	}
	else
		cout<<"You currently don't have any Personalities in your Army!"<<endl<<"You can buy one in the Economy Phase!"<<endl<<endl;
}
void Player :: EquipPhase2()
{
	vector <GreenCard*> :: iterator it;
	string name;
	int flag = 0;
	cout << "Your total balance is : " << this->Money << endl
		<<"Printing Player's Hand : "<<endl<<endl;
	PrintGreenCards(Hand);
	cout<<"Select a Green Card from your hand to attach it at a Personality,by typing its name"<<endl
		<<"Or type SKIP to move on to the battle phase!"<<endl;
	cin>>name;
	for(it = Hand.begin() ; it!=Hand.end();it++)	//traverse the vector
	{
		if((*it)->returnname() == name)	//if the correct card is found
		{
			if(Money >= (*it)->returncost())	//check if user has enough money
				EquipPhase3(it);	//move on to the next phase of equipping a card
			else 
				cout<<"You dont have enough money to purchase this card,please select another one!"<<endl<<endl;
			flag++; //flag it so we know user typed correct input
		}
	}
	if(name == "SKIP")	//if user wishes to skip
		return;	//move on to battle phase
	else if(flag == 0 && name != "SKIP")	//if user gave wrong input and didn't type skip
	{
		cout<<"You didn't select any cards!"<<endl
			<<"Please select again!"<<endl<<endl;
	}
	EquipPhase2();	//he may wish to attach more green cards from his hand
	
}
void Player :: EquipPhase3(vector <GreenCard*> :: iterator it)
{
	vector <BlackCard*> :: iterator it2;
	string name;
	int flag = 0;
	cout<<"Please select the Personality you wish to attach it to : "<<endl<<endl;
	cin>>name;
	for(it2 = Army.begin();it2!=Army.end();it2++)//traverse the vector
	{
		if((*it2)->returnname() == name)//if the correct card is found
		{
			if((*it2)->returnHonor() >= (*it)->returnhonor())	//check if the card has the required Honour
			{
				EquipEffect(it);
				(*it2)->AttachCard(it);
				Money -= (*it)->returncost();
				Hand.erase(it);
			}
			else
			{
				cout<<"This Personality doesnt have the required Honour!"<<endl;
				EquipPhase4(it);
			}	
		}
    }
}
void Player :: EquipPhase4(vector <GreenCard*> :: iterator it)
{
    string temp;
	cout<<"If you wish to select another Personality,type : PERSONALITY"<<endl
		<<"If you wish to select another card from your hand,type : HAND"<<endl
		<<"If you wish not to equip a card from your hand to a Personality,type :SKIP"<<endl<<endl;
    	cin>>temp;
	if(temp == "PERSONALITY")
		EquipPhase3(it);
	else if(temp == "HAND")
		EquipPhase2();
	else if(temp == "SKIP")
		return ;
	else 
	{
		cout<<"You must select one of the 3 options to continue!"<<endl<<endl;
		EquipPhase4(it);
	}
}
void Player :: EquipEffect(vector <GreenCard*> :: iterator it)
{
	string name;
	cout << "Personality found,press YES if you want to pay for the extra effect,else press NO" << endl;
	cout << "Cost of extra attributes (effect) is :" << (*it)->returneffectcost() << endl;
	cin >> name;
	if(name == "YES")	//if user wishes to pay for the extra effect
	{
		if(Money > (*it)->returneffectcost() + (*it)->returncost())	//check if he has the required money
		{
			(*it)->SetAttack((*it)->returnattack()+(*it)->returneffectbonus());	//increase the attack of the Green Card by the effect bonus
			(*it)->SetDefense((*it)->returndefense()+(*it)->returneffectbonus()); //same for the defense of the cardc
			Money -= (*it)->returneffectcost();	//decrease the user's balance by the effect cost
		}
		else
		{		//he doesn't have enought money
			cout<<"You don't have enough money to attach this card and activate its effect bonus!"<<endl<<endl;	
			return;	//return cause he can't select to equip the effect
		}		
	}
	else if(name == "NO")	//he doesn't want to equip the extra effect bonus
		return;
	else	//he probably didn't select either of those options
	{
		cout<<"You didn't select a correct option!"<<endl <<"Please select again"<<endl<<endl;
		EquipEffect(it);	//call recursively until he selects correctly
	}
}
void Player :: BattlePhase(vector <Player*> Players)
{
	cout << returnname() << " is playing" << endl;
	cout << "Army of current player: " << endl ;
	PrintBlackCards(Army);
	cout<<"Please select which cards you wish to use to attack by input the number of card "<<endl;
	cout<<"Type OK when you have selected the personalities you wish to deploy : "<<endl<<endl;
	if(SelectCards("Attacking"))
	{
		cout<<"Please select which player you wish to attack : "<<endl<<endl;
		SelectAttackPlayer(Players);
	}
}
int Player :: SelectCards(string deploying)		
{
	string temp;
	vector <BlackCard*> :: iterator it;
	int flag=0;
	static int i=0;
	cin >> temp;
	if(temp!="OK")
	{
		if(stoi(temp)>Army.size() || stoi(temp)<0) //check in case number does not represent a card of the army
			{
				cout<<"There is no Personality with that number in your Army."<<endl <<"Please select again!"<<endl<<endl;
				SelectCards(deploying); //player also may wants to add more cards to battle so call again recursively
			}
		for(it = Army.begin() ; it != Army.end() ; it++)  //traverse the army vector ,searching based on input
		{
			i++;
			if(i=stoi(temp))
			{
				if(!(*it)->returntap())
				{
					if(deploying == "Attacking")	
						(*it)->DeployAttacker(1);
					else
						(*it)->DeployDefender(1);	
					cout << "Card with number: " << i << " was succesfully deployed!" << endl;
				}
				else						//try again because this card is tapped , cannot attack
					cout<<"This Personality is tapped and cannot be used in a fight!"<<endl <<"Please Select another one!"<<endl<<endl;
				i=0; //since the card was found the traversing stops and we reset i	
				SelectCards(deploying); //try again beacuse either this card was tapped or another card wants to be deployed
			}
		}
	}
	else
	{
		for(it = Army.begin() ; it != Army.end() ; it++)
		{ 	//since ok is inputed traverse all the army,flag it if you find a deployed card for battle
			if(deploying == "Attacking")
				{
					if((*it)->returnattacking())
						flag++;
				}
			else
				if((*it)->returndefending())
					flag++;
		}
		if(!flag)   //if you did not find an employed card
		{
			if(deploying == "Attacking")
				cout<<"No cards chosen,you wil not make any attack this round!" << endl;
			else
				cout<<"No cards chosen,you wil not defend your province from the attacking player!" << endl;
		}
		else	//a deployed card was found and no more cards are gonna be deployed so army is set
			cout<<"Army is deployed and ready to battle!" << endl;	
	}
	return flag;
}
void Player :: SelectAttackPlayer(vector <Player*> Players)
{
	vector <Player*> :: iterator it;
	int PlayerDefeated=0;
	string temp;
	cin>>temp;			//get the name of the player
	if(this->Name==temp) //in case player inputed himself , make him try again
	{
		cout << "Sorry , you cannot attack yourself,please retry!" << endl << endl;
		SelectAttackPlayer(Players);
	}
	for(it = Players.begin();it!=Players.end();it++) //search the players of the game
	{
		if((*it)->returnname() == temp)
		{			
			if(PlayerDefeated=AttackProvince(it)); //if you found the player,attack him and check if you destroyed him
				Players.erase(it);		//delete from the game , the defeated player
			return ;
		}
	}
	cout<<"There is no Player with that name!"<<endl<<"Please select again!"<<endl<<endl; 
	SelectAttackPlayer(Players);
}
vector <BlackCard*> :: iterator Player :: SelectProvince()
{
	string temp;
	vector <BlackCard*> :: iterator it;
	cout<<"Please select which Province you wish to attack : "<<endl<<endl;
	cin>>temp;
	for(it = Provinces.begin();it!=Provinces.end();it++)
	{
		if((*it)->returnname() == temp)			//if you found a province with name end it
			return it;
	}	//else try again to find a province
	cout<<"This player has no Province named "<<temp<<endl <<"Please select again!"<<endl<<endl;
	SelectProvince();
}
int Player :: AttackProvince(vector <Player*> :: iterator it)
{
	vector <BlackCard*> ::iterator it1;
	int Attack=0,Defense=0;
	cout << endl << "Provinces of the chosen player to attack: " << endl;
	(*it)->PrintBlackCards((*it)->returnprovinces());  //show the available provinces to attack
	it1 = (*it)->SelectProvince();
	cout << "Army of the defending player: " << endl ;
	(*it)->PrintBlackCards((*it)->returnarmy()); //show the available army for defending player to recruit defenders
	cout<< (*it)->returnname() << " please select which cards you wish to use to defend your province named: ";
	cout << (*it1)->returnname()<< endl << "Type OK when you have selected the personalities you wish to deploy :"<<endl; 
	(*it)->SelectCards("Defending");
	Defense = (*it)->TotalDefense();  //get the defending army's defence
	Attack = TotalAttack();		   //get the attack points of the attacking army, and then examine battle cases
	if(Attack - Defense > (*it)->InitialDefense())  //if attacking points are more than the total defence
	{
		cout<<"Attacker won!" <<endl<<endl;
		(*it)->LostFight(it1);
		cout<<returnname()<<" won the fight and "<<(*it)->returnname()<<" lost his army and his province"<<endl<<endl;
		LoseHonor();  //also it loses a point of honor the attacking army
		Tap();
		if((*it)->CheckLosingCondition())  //check if the defender's destroyed province was the last one,thus he lost
			return 1;  //defending player is true that he lost the game
	}	
	else if(Attack - Defense > 0) //if attacker won the battle but province was not destroyed
	{							  //all defending army is lost and some of attacking army
		cout<<"Attacker won!" <<endl<<endl;
		int AttPointsLost = LoseAttackers(Defense); //delete the value of attacking damage points equal to the total
		(*it)->LostDefenders();
		cout<<returnname()<<" won the fight but some of his army is lost"<<endl<<endl;
		LoseHonor();  //also it loses a point of honor the attacking army
		Tap();
	}
	else if(Attack == Defense) //both armies are destroyed 
	{
		cout<<"Armies were equal ,both armies were lost, province was not destroyed!"<<endl<<endl;
		(*it)->LostDefenders();
		LostAttackers();
	}
	else if(Defense > Attack) //if defender won the battle some of defenders army is lost
	{						  //and attacker loses all his army
		cout<<"Defender won!" <<endl<<endl;
		int DefPointsLost = (*it)->LoseDefenders(Attack); //delete the value of defensive points equal to the total
		LostAttackers();
		cout<<(*it)->returnname()<<" won the fight but some of his army is lost"<<endl<<endl;
	}
	ClearArmy("Attacking");       //clear both armies so they can be reused in the next battle round of the game
	(*it)->ClearArmy("Defensive");
	return 0;   //defending player didn not lost completely to the game
}
void Player :: LostFight(vector <BlackCard*> :: iterator it1)
{
	vector <BlackCard*> :: iterator it;
	Provinces.erase(it1); 					//lost the province
	for(it = Army.begin();it!=Army.end();it++)	//traverse the army of the defending player
	{
		if((*it)->returndefending())
			Army.erase(it);	//plus the defending army with its attached followers/items
	}
}
void Player :: LostAttackers() 
{
	vector <BlackCard*> :: iterator it;
	for(it = Army.begin();it!=Army.end();it++)	//traverse the army of the attacker player
	{
		if((*it)->returnattacking())	//if you find in army a deployed card , than erase it since it is lost
			Army.erase(it);
	}
}
void Player :: LostDefenders() 
{  
	vector <BlackCard*> :: iterator it;		
	for(it = Army.begin();it!=Army.end();it++)	//traverse the army of the defending player
	{
		if((*it)->returndefending())  //if you find in army a deployed card , than erase it since it is lost
			Army.erase(it);
	}
}
int Player :: LoseAttackers(int Defense)
{
	vector <BlackCard*> :: iterator it;
	vector <GreenCard*> :: iterator it2;
	vector <GreenCard*> array;
	string temp;
	int i = 0;
	static int AttPointsLost = 0;
	PrintAttackers();
	cout << "Please type the number of the card you wish to remove from" << endl;
	cin>>temp;	//get input of desired number of deployed card to erase it possibly or an attachment of it
	for(it = Army.begin();it!=Army.end();it++)  //traverse all the army
	{
		if((*it)->returnattacking())	//if you find in army a deployed card, that means participated in the battle
		{
			i++;
			if(i==stoi(temp))  //conversion needed from string to integer
			{
				if((*it)->returnattached().empty() == true) //in case the chosen card has no attachments then direct erase it
				{
					AttPointsLost += (*it)->returnattack(); //get the sum of lost attacking points
					Army.erase(it);							  //erase it
					cout<<"Total attacking points lost: "<<AttPointsLost<<endl<<endl;
					if(Defense > AttPointsLost) //in case the number of needed lost attacking points isn't achieved
					{
						if(Army.empty()==false)  //in case there is more to delete procceed to possible recursion
							AttPointsLost=LoseAttackers(Defense); //erase(lose) another army card or attachment
						else
						{
							cout << "Cannot delete anything else, army is all deleted!" << endl;
							return AttPointsLost;
						}
					}
					else
						return AttPointsLost; //else its done the erasing of lost attacking army
				}
				cout << "Please type which attachment of the card or even the whole card you wish to lose" << endl;
				cin >>temp;  //get the name of the desired card to be lost (attachment or personality)
				if((*it)->returnname() == temp)  //in case input is to delete the whole personality card
				{
					AttPointsLost += (*it)->returnattack();	  //get the sum of lost attacking points
					Army.erase(it);							  //erase it
					cout<<"Total attacking points lost: "<<AttPointsLost<<endl<<endl;
					if(Defense > AttPointsLost) //in case the number of needed lost attacking points isn't achieved
					{
						if(Army.empty()==false)  //in case there is more to delete procceed to possible recursion
							AttPointsLost=LoseAttackers(Defense); //erase(lose) another army card or attachment
						else
						{
							cout << "Cannot delete anything else, army is all deleted!" << endl;
							return AttPointsLost;
						}
					}
					else
						return AttPointsLost; //else its done the erasing of lost attacking army
				}	
				array = (*it)->returnattached();	//get it's attachments(in case input is to delete attachment)
				for(it2 = array.begin();it2!=array.end();it2++)
				{
					if((*it2)->returnname() == temp) //if you found an attachment in a card with that name
					{
						AttPointsLost +=(*it2)->returnattack();  //get the sum of lost attacking points
						(*it)->Detach(it2);						//erase it
							cout<<"AtTotal attacking points lost: "<<AttPointsLost<<endl<<endl;
					} //army vector cannot be empty since an attachment of a card was only removed
					if(Defense > AttPointsLost) //in case the number of needed lost attacking points isn't achieved
						AttPointsLost=LoseAttackers(Defense); //erase(lose) another army card or attachment
					else
						return AttPointsLost;	//else its done the erasing of lost attacking army	
				}
			}
		}
	}   //if you finished traversing the army without successfully losing the equal damage from the battle,then :
	cout<<"There is no attacker or attachment with that number or named like that."<<endl<<"Please select again!"<<endl<<endl;
	LoseAttackers(Defense); //try again
}
int Player :: LoseDefenders(int Attack)
{
	vector <BlackCard*> :: iterator it;
	vector <GreenCard*> :: iterator it2;
	vector <GreenCard*> array;
	string temp;
	int i = 0;
	static int DefPointsLost = 0;
	PrintDefenders();
	cout << "Please defender type the number of the card you wish to remove from" << endl;
	cin>>temp;	//get input of desired number of deployed card to erase it possibly or an attachment of it
	for(it = Army.begin();it!=Army.end();it++)  //traverse all the army
	{
		if((*it)->returndefending())	//if you find in army a deployed card, that means participated in the battle
		{
			i++;
			if(i==stoi(temp))  //conversion needed from string to integer
			{
				if((*it)->returnattached().empty() == true)//in case the chosen card has no attachments then direct erase it
				{
					DefPointsLost += (*it)->returnattack(); //get the sum of lost attacking points
					Army.erase(it);							  //erase it
					cout<<"Total attacking points lost: "<<DefPointsLost<<endl<<endl;
					if(Attack > DefPointsLost) //in case the number of needed lost attacking points isn't achieved
					{	
						if(Army.empty()==false)
							DefPointsLost=LoseAttackers(Attack); //erase(lose) another army card or attachment
						else
						{
							cout << "Cannot delete anything else, army is all deleted!" << endl;
							return DefPointsLost;
						}
					}
					else
						return DefPointsLost;	//else its done the erasing of lost defensive army
				}
				cout << "Please type which attachment of the card or even the whole card you wish to lose" << endl;
				cin >>temp;  //get the name of the desired card to be lost (attachment or personality)
				if((*it)->returnname() == temp)  //in case input is to delete the whole personality card
				{
					DefPointsLost += (*it)->returnattack();	  //get the sum of lost attacking points
					Army.erase(it);							  //erase it
					cout<<"Total attacking points lost: "<<DefPointsLost<<endl<<endl;
					if(Attack > DefPointsLost) //in case the number of needed lost attacking points isn't achieved
					{
						if(Army.empty()==false)
							DefPointsLost=LoseAttackers(Attack); //erase(lose) another army card or attachment
						else
						{
							cout << "Cannot delete anything else, army is all deleted!" << endl;
							return DefPointsLost;
						}
					}
					else
						return DefPointsLost; //else its done the erasing of lost defending army
				}	
				array = (*it)->returnattached();	//get it's attachments(in case input is to delete attachment)
				for(it2 = array.begin();it2!=array.end();it2++)
				{
					if((*it2)->returnname() == temp) //if you found an attachment in a card with that name
					{
						DefPointsLost +=(*it2)->returnattack();  //get the sum of lost attacking points
						(*it)->Detach(it2);						  //erase it
						cout<<"Total attacking points lost: "<<DefPointsLost<<endl<<endl;
					} //army vector cannot be empty since an attachment of a card was only removed
					if(Attack > DefPointsLost) //in case the number of needed lost attacking points isn't achieved
						DefPointsLost=LoseDefenders(Attack); //erase(lose) another army card or attachment
					else
						return DefPointsLost;	//else its done the erasing of lost defensive army	
				}
			}
		}   //if you finished traversing the army without successfully losing the equal damage from the battle,then :
	}
	cout<<"There is no defender or attachment with that number or named like that."<<endl<<"Please select again!"<<endl<<endl;
	LoseDefenders(Attack); //try again
}	
void Player :: LoseHonor()
{
	vector <BlackCard*> :: iterator it;
	for(it = Army.begin();it!=Army.end();it++)
	{
		if((*it)->returnattacking())	 //if you find in army a deployed card then it must lose one point of honor
		{
			(*it)->SetHonor();
			if((*it)->returnHonor() == 0)  //if personality has reached 0 honor after the battle do Seppuku
			{
				Army.erase(it);
				cout<<(*it)->returnname()<<" has performed Seppuku to save his family Honor!"<<endl<<endl;
			}
		}
	}
}
int Player :: TotalAttack()
{
	vector <BlackCard*> :: iterator it;
	int Attack=0;
	for(it = Army.begin();it!=Army.end();it++)
	{
		if((*it)->returnattacking())   //if card is deployed from the army, then add it to battle attacking points
			Attack +=(*it)->returnattack();
	}
	return Attack;
}
int Player :: TotalDefense()
{
	vector <BlackCard*> :: iterator it;
	int Defense=0;
	for(it = Army.begin();it!=Army.end();it++)
	{
		if((*it)->returndefending()) //if card is deployed from the army, then add it to battle defensive points
			Defense += (*it)->returndefense();
	}
	return Defense;
}
void Player :: Tap()
{
	vector <BlackCard*> :: iterator it;
	vector <GreenCard*> temp;
	vector <GreenCard*> :: iterator it2;
	for(it = Army.begin();it!=Army.end();it++)	//traverse the vector
	{	
		if((*it)->returnattacking() == 1)	//card must have been used in an attack
		{
			(*it)->SetTap(1);	//tap the personality so he can't use it again this round ,or to defend if need be
			temp = (*it)->returnattached();	//return the attached vector of the personality to a temporary vector
			for(it2 = temp.begin();it2!=temp.end();it2++)	//traverse the vector
			{
				(*it2)->SetTap(1);	//tap the every card in the attached vector of the personality
				if((*it2)->returndurability() == 0)	//if the item has lost its durability
					(*it)->Detach(it2);	//detach it from the personality
			}	
		}
	}	
}
int Player :: CheckLosingCondition()
{
	if(!Provinces.size())
	{
		cout << this->Name << ",you are defeated! All your provinces are lost!" << endl;
		return 1;
	}
	return 0;
}
void Player :: ClearArmy(string deploying)
{
	vector <BlackCard*> :: iterator it;
	if(deploying=="Attacking")
	{
		for(it = Army.begin();it != Army.end();it++)
			(*it)->DeployAttacker(0); //since another battle is going to take place in next round,undeploy all the attackers
	}
	else
	{
		for(it = Army.begin();it != Army.end();it++)
			(*it)->DeployDefender(0); //since another battle is going to take place in next round,undeploy all the defenders
	}
}
void Player :: EconomyPhase()
{
	vector <BlackCard*> :: iterator it;
	string temp;
	cout<<"Do you wish to tap your Holdings in order to purchase a card?"<< endl <<"Type YES or NO"<<endl<<endl;
	cin>>temp;
	if(temp == "YES")
		ChooseHoldings();	//user chooses which Holdings he wishes to tap
	else
		cout<<"You will have the opportunity to do it later anyways"<<endl<<endl;
	for(it = Provinces.begin(); it != Provinces.end();it++)	//move them temporarily to a new vector cause if user buys a card,there will be a new card in the vector
		tempProvinces.push_back(*it);	//which user can't purchase this round
	EconomyPhase2(); //user chooses which card to buy
	tempProvinces.erase(tempProvinces.begin(),tempProvinces.end()); //erase the temporary vector ,so it can be used correctly next round
}
void Player :: EconomyPhase2()
{
	vector <BlackCard*> :: iterator it;
	string temp;
	int flag = 0;
	cout<<"Printing Player's Provinces : "<<endl<<endl;
	PrintBlackCards(tempProvinces);
	cout<<"Please Select the cards you wish to purchase."<<endl<<"Type SKIP to exit the Economy Phase!"<<endl<<endl;
	cin>>temp;
	if(temp == "SKIP")
		return;
	for(it = Provinces.begin();it != Provinces.end();it++)
	{
		if((*it)->returnname() == temp)	//find the correct card
		{
			if((*it)->returncost() <= Money)	//make sure user has enough money
			{
				if((*it)->returntype() == "Personality")	//if card is a personality
					Army.push_back(*it);	//move it to the Army
				else	//else it is a Holding
				{
					if(!ChainListFunc((*it)))	//Build possible chain in case our new property card is chain-holding 
						Property.push_back(*it);	//Move it to the Properties
				}
				Provinces.erase(it);	//erase the card from the vector
				Money -= (*it)->returncost();	//decrease the balance by the cost of the card
				cout <<"Your total balance now is :" << this->Money << endl;
				DrawBlackCard();	//Draw another one so the Provinces always remain 4
			}
			else	//User doesn't have enough money
			{
				cout<<"You don't have enough money to make this purchase!"<<endl;
				EconomyPhase3(); //help him decide
			}						
			flag++;	//if the vector is traversed at least once ,flag changes value 
		}
	}
	if(flag == 0 && temp!="OK")	//If there is no province named like that and user didn't type OK
	{
		cout<<"There is no card name like that in your Provinces!"<<endl
		<<"If you wish to skip the Economy Phase type : SKIP"<<endl<<endl;
	}
	EconomyPhase2();	//user may want to select more cards to purchase
}
void Player :: EconomyPhase3()
{
	string temp;
	cout<<"Do you wish to tap your Holdings , or select another card?"<<endl
	<<"Type CARD to select again or HOLDINGS to increase your balance(if you are able to)"<<endl<<endl;
	cin>>temp;
	if(temp == "CARD")
	cout<<"Please Select another Card!"<<endl<<endl;
	else if(temp == "HOLDINGS")
		ChooseHoldings();	
	else
	{
		cout<<"You didn't select either of those!"<< endl <<"Please select again!"<<endl<<endl;
		EconomyPhase3();	//user didn't type CARD or HOLDINGS so he must choose again
	}
}
void Player :: ChooseHoldings()
{
	string temp;
	cout<<"Do you wish to tap your FARMS,PLAINS and SOLOS or your MINES,GOLD MINES,CRYSTAL MINES?"<<endl
	<<"To tap the former, type : FARM or PLAIN or SOLO"<<endl
	<<"To tap the latter, type : MINE or GOLD MINE or CRYSTAL MINE"<<endl
	<<"If you wish to tap neither of those type : SKIP"<<endl<<endl;
	cin>>temp;
	if(temp == "FARM" || temp == "PLAIN" || temp == "SOLO")	//if user wants to tap the Properties that don't create chains
	{
		if(Property.size() > 0)	//he must have at least one
			TapProperties();
		else	//he doesn't have any Properties of that type
		{
			cout<<"You don't have any Holdings of that type!"<<endl	
						<<"Please Select another option!"<<endl<<endl;
		}
	}	
	else if(temp == "MINE" || temp == "GOLD MINE" || temp == "CRYSTAL MINE")//if user wants to select the type of Properties that create chains
	{
		if(ChainList.size() > 0)//He must have at least one
			TapHoldings();
		else	//he doesnt have any of that type
			cout<<"You don't have any Holdings of that type!"<< endl <<"Please select another option!"<<endl<<endl;
	}	
	else if (temp == "SKIP")	//if he wants to skip this phase
	{
		cout<<endl<<endl;
		return;	//return so it doesn't create any problems
	}		
	else	//he didn't type any of the key-words
		cout<<"You didn't select either of those!"<< endl <<"Please select again!"<<endl<<endl;
	ChooseHoldings();	//he may wish to tap another type of properties or to tap more of the same type
}
void Player :: TapProperties()
{
	vector <BlackCard*> :: iterator it;
	string temp;
	int flag = 0;
	cout<<"These are your Properties :"<<endl<<endl;
	PrintBlackCards(Property);
	cout<<"To skip this section please type SKIP!"<<endl
	<<"Please enter the name of the Property you wish to tap : "<<endl<<endl;
	cin>>temp;
	for(it = Property.begin(); it != Property.end(); it++)	//traverse the vector for the given name
	{
		if((*it)->returnname() == temp && (*it)->returntap() == 0)	//if the given property is found and we know it is not tapped before
		{
			Money += (*it)->returnharvest();	//increase the user's balance
			(*it)->SetTap(1);	//tap it so we know it is tapped,so user can't get infinite money
			flag++;	//flag that there was a property with the given name
		}
		else if((*it)->returnname() == temp && (*it)->returntap() == 1)	//if user gave the correct name but the property was used this round
		{
			cout<<"You already have tapped this Property and cannot do it again this round!"<<endl
			<<"Please select another one!"<<endl<<endl;
			flag++;	//flag the fact that he type a correct name so it goes directly to the else condition and is called recursively
		}
	}
	if(flag == 0 && temp != "SKIP")	//if user didn't give the correct input
	{
		cout<<"You didn't select any Properties or type SKIP"<< endl <<"Please select again!"<<endl<<endl;
		TapProperties();	//call recursively
	}
	else if(temp == "SKIP")	//if user wants to skip this phase
		return;	
	else
		TapProperties();	//he may want to tap more properties or he gave the name of a tapped card

}
void Player :: TapHoldings()
{
	int flag = 0,i;
	char c;
	string temp;
	vector <Chain> :: iterator it;
	cout<<"Your input should be like : 1.MINE"<<endl<<endl;
	cin>>temp;
	if(temp != "OK")	//if input is OK and we remove the 2 character there won't be a string
	{
		c = temp.at(0); //input is like : 1.Mine,so take the number as a char
		temp.erase(0,2); //erase the first 2 chars of the string so only the name remains
	}			
	for(it = ChainList.begin();it != ChainList.end();it++)	//traverse the vector
	{
		if(i == atoi(&c))	//if i is equal to the integer of the char
		{
			if(it->CurrentName == temp && it->CurrentHolding->returntap() == 0)	//if found the card with the given name
			{
				Money += it->CurrentHolding->returnharvest();	//tap the Holding and increase the user's balance
				it->CurrentHolding->SetTap(1); //mark it so user can't tap it again
				flag++;	//flag it so we know user typed a correct Holding
			}
			else if(it->CurrentName == temp && it->CurrentHolding->returntap() == 1)//if user tries to tap the same Holding twice
			{
				cout<<"This Holding is already tapped and cannot be used for the rest of this round!"<<endl
				<<"Please select another one!"<<endl<<endl;
				flag++;//flag it so the program goes directly to the else condition and the function is called recursively
			}
			else if(it->SubName == temp && it->SubHolding->returntap() == 0)	//same as the first if condition
			{
				Money += it->SubHolding->returnharvest();	
				it->SubHolding->SetTap(1);
				flag++;
			}
			else if(it->SubName == temp && it->SubHolding->returntap() == 1)
			{
				cout<<"This Holding is already tapped and cannot be used for the rest of this round!"<<endl
				<<"Please select another one!"<<endl<<endl;
				flag++;//flag it so the program goes directly to the else condition and the function is called recursively
			}
			else if(it->UpperName == temp && it->UpperHolding->returntap() == 0)	//same as the first if condition
			{
				Money += it->UpperHolding->returnharvest();
				it->UpperHolding->SetTap(1);
				flag++;
			}
			else if(it->UpperName == temp && it->UpperHolding->returntap() == 1)
			{
				cout<<"This Holding is already tapped and cannot be used for the rest of this round!"<<endl
				<<"Please select another one!"<<endl<<endl;
				flag++;//flag it so the program goes directly to the else condition and the function is called recursively						
			}
		}
		i++;
	}
	if(temp == "OK" && flag == 0)	//if user typed OK but vector wasn't traversed
		cout<<"You didn't select to tap any Holding"<<endl<<endl;	//He probably didn't want to tap holdings
	else if(temp == "OK")	//if user types OK and flag differs from 0
		cout<<"Your total balance after tapping the Holdings is : "<<Money<<endl<<endl;	//Show him his current balance
	else	//else he may want to tap more holdings
		TapHoldings();		//call recursively
}
void Player :: FinalPhase(vector <Player*> Players)
{
	if(Hand.size() > 6)
	{
		cout<<"Please Select which cards you wish to send to the Graveyard by typing their name"<<endl
		<<"Remember you can only throw as many cards as need,so in the end you have 6 cards in you Hand"<<endl<<endl;
		PrintGreenCards(Hand);
		DiscardSurplusFateCards();
	}
	cout<<"Printing "<<returnname()<<" statistics!"<<endl<<endl	
		<<"Printing "<<returnname()<<" Hand : "<<endl<<endl;
		PrintGreenCards(Hand);
	cout<<"Printing "<<returnname()<<" Provinces : "<<endl<<endl;
		PrintBlackCards(Provinces);
	cout<<"Printing "<<returnname()<<" Army : "<<endl<<endl;
		PrintBlackCards(Army);
	cout<<"Printing "<<returnname()<<" Holdings : "<<endl<<endl;
		PrintBlackCards(Property);
}
void Player :: DiscardSurplusFateCards()
{
	vector <GreenCard*> :: iterator it;
	string temp;
	int flag;
	cin>>temp;
	for(it = Hand.begin(); it != Hand.end(); it++) //traverse vector to find the given card
	{
		if((*it)->returnname() == temp)	//if the card is found
		{
			cout<<(*it)->returnname()<<" was discarded!"<<endl<<endl;
			Hand.erase(it);	//erase it from the user's Hand
			flag++;	//mark the fact that there was a card with that name
		}
	}
	if(flag == 0)	//if there was no card with that name
	{
		cout<<"There is no card with that name in your Hand!"<<endl	<<"Please Select again"<<endl<<endl;
		DiscardSurplusFateCards(); //call recursively
	}
	else if(Hand.size() > 6)	//if user's hand is still greater than 6
		DiscardSurplusFateCards();	//call recursively
}
int Player :: CheckWinningCondition(vector <Player*> Players)
{
	if(Provinces.size()>0 && Players.size()==1) //if stills in game with at least one province,and he is the last player
		return 1;								//then we have a winner!
	else
		return 0;								//otherwise return false , no winner occurs yet
}
void Player :: PrintGreenCards(vector <GreenCard*> GreenCardVector)
{
	vector <GreenCard*> ::iterator it;
	int i=1;
	for (it = GreenCardVector.begin(); it != GreenCardVector.end(); it++)
	{
		cout << i++ << ". " ;
		(*it)->printstats();	
	}
	cout<<endl;	
}
void Player :: PrintBlackCards(vector <BlackCard*> BlackCardVector)
{
	vector <BlackCard*> ::iterator it;
	vector <GreenCard*> :: iterator it2;
	int i=1,j=1;
	for (it = BlackCardVector.begin(); it != BlackCardVector.end(); it++)
	{
		cout << i++ << ". " ;
		(*it)->printstats();
		if((*it)->returnattached().size())   //in case of printing army vector print also attachments of them too 
		{
			cout<<" Printing attached cards stats : "<<endl<<endl;
			for(it2 = (*it)->returnattached().begin();it2!=(*it)->returnattached().end();it2++)
			{	//print its attachment of each card of the army
				cout << "   " << i << "." << j++ << " "; 
				(*it2)->printstats();
			}
		}
	}
	cout<<endl;
}
void Player :: PrintBlackCards(vector <Chain> BlackCardVector)
{
	vector <Chain> ::iterator it;
	for(it = BlackCardVector.begin(); it != BlackCardVector.end(); it++)
		cout << it->SubName << " - " << it->CurrentName << " - " << it->UpperName << endl;
}
void Player :: PrintAttackers()
{
	vector <BlackCard*> :: iterator it;
	vector <GreenCard*> :: iterator it2;
	int i=1,j=1;
	for(it = Army.begin();it!=Army.end();it++)	//traverse the army of the attacker player
	{
		if((*it)->returnattacking())	//if you find in army a deployed card
		{
			cout << i++ << ". " ;
			(*it)->printstats();   //print the attacking army card card first
			cout<<" Printing attached cards stats : "<<endl;
			for(it2 = (*it)->returnattached().begin();it2!=(*it)->returnattached().end();it2++) 
			{	//and then its attachments
				cout << "  " << i << "." << j++ << " "; 
				(*it2)->printstats();
			}
		}
	}
}
void Player :: PrintDefenders()
{
	vector <BlackCard*> :: iterator it;
	vector <GreenCard*> :: iterator it2;
	vector <GreenCard*> temp;
	int i=1,j=1;
	for(it = Army.begin();it!=Army.end();it++)	//traverse the army of the defender player
	{
		if((*it)->returndefending())
		{
			cout << i++ << ". " ;
			(*it)->printstats();   //print the defensive army card card first
			cout<<" Printing attached cards stats : "<<endl;
			for(it2 = (*it)->returnattached().begin();it2!=(*it)->returnattached().end();it2++) 
			{	//and then its attachments
				cout << "  " << i << "." << j++ << " "; 
				(*it2)->printstats();
			}
		}
	}
}