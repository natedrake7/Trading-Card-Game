#include "BlackCard.hpp"

#define DECKSIZE          40
#define MAXDECKSIZE       60

#define NO_FOLLOWERS      28
#define NO_FOOTSOLDIER    6
#define NO_ARCHER         6
#define NO_SIEGER         4
#define NO_CAVALRY        5
#define NO_NAVAL          5
#define NO_BUSHIDO        2

#define NO_ITEMS          12
#define NO_KATANA         4
#define NO_SPEAR          3
#define NO_BOW            2
#define NO_NINJATO        2
#define NO_WAKIZASHI      1

#define NO_ATTACKING      10
#define NO_DEFENSIVE      10
#define NO_SHOGUN         2
#define NO_CHANCELLOR     2
#define NO_CHAMPION       1

#define NO_SOLO           2
#define NO_PLAIN          3
#define NO_FARMS          3
#define NO_MINE           3
#define NO_GOLD_MINE      3
#define NO_CRYSTAL_MINE   3

struct Chain {					//each node of list struct chain represents a fully chain of the 3 holdings
	BlackCard* CurrentHolding;
	BlackCard* SubHolding;
	BlackCard* UpperHolding;
	string CurrentName;
	string SubName;
	string UpperName;
};

class Player {
	private:
		vector <GreenCard> Deck1;    				//if there was a way to delete it.. 
		vector <BlackCard> Deck2;    				//if there was a way to delete it.. 
		vector <GreenCard*> FateDeck;
		vector <BlackCard*> DynastyDeck;
		vector <BlackCard*> Army;
		vector <BlackCard*> Property;               //Holdings = Property + ChainList
		vector <BlackCard*> Provinces;
		vector <BlackCard*> tempProvinces;
		vector <GreenCard*> Hand;
		vector <BlackCard*> Graveyard;
		vector <Chain> ChainList;
		BlackCard StrongHold;
		string Name;
		int Money;
		int hidden;
	public:
		Player() {};
		~Player() {};
		void SetName(char j);							//creation and initialization of entity Player
		void Begin();
		void CreateDeck();
		void FillGreenDeck(vector <GreenCard> tempDeck);
		void FillBlackDeck(vector <BlackCard> tempdeck);
		void AddChainNode(BlackCard* OwnedCard);
		int ChainListFunc(BlackCard* OwnedCard);
		void DrawGreenCard();
		void DrawBlackCard();
		void StartingPhase(vector <Player*> Players);		//Starting phase functions for the correspoding phase
		void UntapEverything();
		void EquipPhase();									//Equip phase functions for the correspoding phase
		void EquipPhase2();
		void EquipPhase3(vector <GreenCard*> :: iterator it);
		void EquipPhase4(vector <GreenCard*> :: iterator it);
		void EquipEffect(vector <GreenCard*> :: iterator it);
		void BattlePhase(vector <Player*> Players);			//Battle phase functions for the correspoding phase
		int SelectCards(string deploying);
		void SelectAttackPlayer(vector <Player*> Players);
		vector <BlackCard*> :: iterator SelectProvince();
		int AttackProvince(vector <Player*> :: iterator it);
		void LostFight(vector <BlackCard*> :: iterator it1);
		void LostAttackers();
		void LostDefenders();
		int LoseAttackers(int Defense);
		int LoseDefenders(int Attack);
		void LoseHonor();
		int TotalAttack();
		int TotalDefense();
		void Tap();
		int CheckLosingCondition();
		void ClearArmy(string deploying);
		void EconomyPhase();								//Economy phase functions for the correspoding phase
		void EconomyPhase2();
		void EconomyPhase3();
		void ChooseHoldings();
		void TapProperties();
		void TapHoldings();
		void FinalPhase(vector <Player*> Players);		//Final phase functions for the correspoding phase
		void DiscardSurplusFateCards();
		int CheckWinningCondition(vector <Player*> Players);
		int InitialDefense() { return StrongHold.returndefense(); } 	//Some returning functions needed
		string returnname() { return Name; }
		int returnmoney() { return Money; }
		vector <BlackCard*> returnprovinces() { return Provinces; }
		vector <BlackCard*> returnarmy() { return Army; }
		void PrintGreenCards(vector <GreenCard*> GreenCardVector); 		//Printing functions needed
		void PrintBlackCards(vector <BlackCard*> BlackCardVector);
		void PrintBlackCards(vector <Chain> BlackCardVector);
		void PrintAttackers();
		void PrintDefenders();
};