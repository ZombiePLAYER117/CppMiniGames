#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player
{
public:
	string name;
	int hp;
	int attack_damage;
	/// <summary>
	/// 玩家的构造函数
	/// </summary>
	/// <param name="name">玩家名字</param>
	/// <param name="hp">血量</param>
	/// <param name="a">攻击力</param>
	Player(const string& name, int hp,int a):name(name),hp(hp),attack_damage(a) {};
	bool isAlive() const {
		return hp > 0;
	};
private:
};

class Monster
{
public:
	string name;
	int hp;
	int attack_damage;
	Monster(const string& name, int hp, int a) :name(name), hp(hp), attack_damage(a) {};
	bool isAlive() const {
		return hp > 0;
	};
private:
};

void player_attack(Player& player, Monster& monster) {
	int damage = rand() % player.attack_damage + 1;
	monster.hp -= damage;
	cout << player.name << "攻击了" << monster.name << "造成了" << damage << "点伤害" << endl;
}

void monster_attack(Monster& monster, Player& player) {
	int damage = rand() % monster.attack_damage + 1;
	player.hp -= damage;
	cout << monster.name << "攻击了" << player.name << "造成了" << damage << "点伤害" << endl;
}

int main() {
	srand((unsigned)time(nullptr));
	Player player_1("勇者", 50, 10);
	Monster monster_1("史莱姆", 20, 5);

	cout << "BATTLE ON!\n"<<endl;

	while (player_1.isAlive() && monster_1.isAlive()) {
		player_attack(player_1, monster_1);
		cout << monster_1.name << "HP:" << monster_1.hp << endl;

		if (!monster_1.isAlive()) break;

		monster_attack(monster_1, player_1);
		cout << player_1.name << "HP:" << player_1.hp << endl;
	}
	if (player_1.isAlive()) {
		cout << "PLAYER WIN!!!" << endl;

	}
	else {
		cout << "PLAYER LOSE!!!" << endl;
	}
	return 0;
}
