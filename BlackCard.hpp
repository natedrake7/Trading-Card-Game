#include "GreenCard.hpp"

class BlackCard {
	private:
		vector <GreenCard*> Attachments;
		int Cost;
		int Istapped;
		int Attack;
		int Defense;
		int Honor;
		int Harvest;
		int StartingHonour;
		int Attacking;
		int Defending;
		string Name;
		string type;
	public:
		BlackCard():Attacking(0),Defending(0) {};
		~BlackCard() {};
		void setdatabasestatsblack(int costtemp, string tempname, int adtemp, int deftemp, int honortemp, int harvesttemp, int i) //set all the necessary stats
		{
			Cost = costtemp;	
			Name = tempname;
			if (i < 5)	//if i is smaller than 5 it is a Personality
			{
				type = "Personality";
				Attack = adtemp;
				Defense = deftemp;
				Honor = honortemp;
			}	
			else if (i < 11) //if 5 < i < 11 it is a Holding
			{
				type = "Holding";
				Harvest = harvesttemp;
				Attack = 0;
				Defense = 0;
			}
			if(i == 11)	//if i = 11 it is a StrongHold
			{
				type = "StrongHold";
				StartingHonour = honortemp;
				Harvest = harvesttemp;
				Attack = 0;
				Defense = deftemp;
			}
		}
		void SetTap(int i) { Istapped = i; }
		void SetHonor() {Honor--;}
		void DeployAttacker(int i) { Attacking=i; }
		void DeployDefender(int i) { Defending = i; }
		void ModifyHarvest(string operation,double value)	//takes the name of the operation and changes the value of the harvest
		{
			if(operation == "addition")
				Harvest+=value;
			else if(operation == "multiplication")
				Harvest*=value;
			else
				cout << "Error! Wrong input in ModifyHarvest!" << endl;
		}
		void AttachCard(vector <GreenCard*> :: iterator it)
		{
			Attachments.push_back(*it);	//push back the selected card
			cout<<(*it)->returnname()<<" has been attached to : "<<Name<<endl<<endl;	//inform the user about it
			Attack += (*it)->returnattack();	//increase the attack of the personality
			Defense += (*it)->returndefense();	//increase the defense of the personality
		}
		void Detach(vector <GreenCard*> :: iterator it)
		{
			Attack-=(*it)->returnattack();	//decrease the attack of the personality
			Defense-=(*it)->returndefense();	//decrease the defense of the personality
			Attachments.erase(it);		//erase the card from the vector
		}
		string returnname() { return Name; }
		string returntype() { return type; }
		int returntap() { return Istapped; }
		int returnHonor() { return Honor; }
		int returnattacking() { return Attacking; }
		int returndefending() { return Defending; }
		int returncost(){ return Cost; }
		int returnharvest() { return Harvest; }
		int returnattack() { return Attack; }
		int returndefense() { return Defense; }
		vector <GreenCard*> returnattached() { return Attachments; }
		void printstats()
		{
			cout << Name <<endl;/*"\n\n"
			<< "Cost : " << Cost << endl;
			if (type == "Personality")
			{
				cout << "Attack : " << Attack << endl
				<< "Defense : " << Defense << endl
				<< "Honor : " << Honor << endl
				<< "Type : " << type << endl
				<< "\n";
			}
			else if (type == "Holding")
			{	
				cout << "Harvest : " << Harvest << endl
				<< "Type : " << type << endl
				<< "\n";
			}
			else if (type == "StrongHold")
			{
				cout << "Harvest : " << Harvest << endl
				<< "Starting Honour : " << StartingHonour << endl
				<< "Type : " << type << endl
				<< "\n";
			}*/
		}
};