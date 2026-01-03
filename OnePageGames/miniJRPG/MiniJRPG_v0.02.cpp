#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
//战斗选项 runaway,fight,persuade
enum BattleChoice
{
	runaway=0,
	fight,
	persuade
};

template <typename T>
class Entity {
public:
	string name;
	T hp;
	T attack;
	int runaway_chance;
	Entity(const string& n, T h, T a,int r) :name(n),hp(h),attack(a),runaway_chance(r){
	}

	bool isAlive()const {
		return hp > 0;
	}

	void takeDamage(T dmg) {
		hp -= dmg;
		//防止溢出
		if (hp < 0) hp = 0;
	}
	bool can_runaway(int runaway_chance) {
		
		if ((rand() % 100) > runaway_chance) {
			return true;
		}
		else {
			return false;
		}

	}
};

template <typename T>
void attack(Entity<T>& attacker, Entity<T>& defender) {
	cout << attacker.name << "攻击了" << defender.name
		<< "造成了" << attacker.attack << "点伤害" << endl;
	defender.takeDamage(attacker.attack);
}


int main() {
	srand((unsigned)time(nullptr));
	Entity<int> player("玩家", 100, 9, 90);
	Entity<int> monster("史莱姆", 30, rand() % 10 + 5, 10);
	cout << "战斗开始" << endl;
	//fight_on是判断是否投降或者逃跑
	bool battle_on = true;
	while (player.isAlive() && monster.isAlive() && battle_on)
	{
		cout << "\n\t当前状态:\n";
		cout << player.name << "HP:" << player.hp << endl;
		cout << monster.name << "HP:" << monster.hp << endl;
	

		cout << "你要做什么:";
		//创建三种选项，0是逃跑，1是战斗，2是说服
		cout << "\t0: 逃跑，1: 战斗，2:说服" << endl;
		int user_input;
		cin >> user_input;
		BattleChoice choice;
		choice = static_cast<BattleChoice>(user_input);
		switch (choice) {
			//如果玩家能逃离，打印逃走语句，结束游戏
		case runaway:
			if (player.can_runaway(monster.runaway_chance)) {
				cout << player.name << "成功逃走了！" << endl;
				battle_on = false;
				break;
			}
			else {
				cout << player.name << "逃走失败了！" << endl;
				attack(monster, player);
			}break;

			//战斗
		case fight:
			attack(player, monster);
			attack(monster, player);
			break;

			//说服对方
		case persuade:
			if (rand() % 100 > monster.runaway_chance) {
				cout << "你说服了" << monster.name << endl;
				battle_on = false;
		}break;
	}
		
	}
	if (player.hp == 0) {
		cout << "玩家血量为0，死亡";
	}
	else if (monster.hp == 0) {
		cout << "怪物血量为0，死亡";
	}
}