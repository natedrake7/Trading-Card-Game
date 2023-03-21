#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class GreenCard {
	private:
		int Cost;
		int AttackBonus;
		int DefenseBonus;
		int MinimumHonor;
		int EffectBonus;
		int EffectCost;
		int Istapped;
		int Health;
		string name;
		string type;
		int durability;
	public:
		GreenCard() {};
		~GreenCard() {};
		void setdatabasestatsgreen(int costtemp, int adtemp, int deftemp, int mintemp, int effectbtemp, int effectctemp, string tempname, int durabilitytemp, int i)
		{
			Cost = costtemp;
			AttackBonus = adtemp;
			DefenseBonus = deftemp;
			MinimumHonor = mintemp;
			EffectBonus = effectbtemp;
			EffectCost = effectctemp;
			name = tempname;
			if (i < 6)
			{
				type = "follower";
				Health = 1;
			}	
			else
			{
				type = "item";
				durability = durabilitytemp;
			}	
		}
		void SetAttack(int i) { AttackBonus = i; }
		void SetDefense(int i) { DefenseBonus = i; }
		void SetTap(int i)
		{
			if(i=1)
			{
				if(type == "Follower")
					Istapped = i;
				else
					durability--;
			}	
			else
				Istapped = i;
		}
		string returnname() { return name; }
		int returncost() { return Cost;}
		int returnhonor() { return MinimumHonor;}
		int returnattack() { return AttackBonus;}
		int returndefense() { return DefenseBonus;}
		int returndurability() { return durability; }
		int returneffectcost() { return EffectCost; }
		int returneffectbonus() { return EffectBonus; }
		void printstats()
		{
			cout << name << endl;
			/*	<<"Cost : "<<Cost<<endl
			<<"Attack Bonus : "<<AttackBonus<<endl
			<<"Defense Bonus : "<<DefenseBonus<<endl
			<<"Minumum Honor : "<<MinimumHonor<<endl
			<<"Effect Bonus : "<<EffectBonus<<endl
			<<"Effect Cost : "<<EffectCost<<endl
			<<"Type : "<<type<<endl;
			if(type=="item")
			{
				cout<<"Durability : "<<durability<<endl<<"\n";
			}
			else
			{
				cout<<"\n";
			}*/
		}
};