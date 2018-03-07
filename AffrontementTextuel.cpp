#include <iostream>
#include <random>
#include <ctime>

using namespace std;
int main()
{
	//Création des armées :
	int humains;
	int monstres;
	cout << "Les factions ne s'entendent plus, la guerre se prepare !" << endl;
	cout << "Indiquer le nombre de guerriers enroles : ";
	cin >> humains; //Demande à l'utilisateur d'entrer un nombre de soldats pour l'armée des humains.
	cout << "Indiquer le nombre de monstres a combattre : ";
	cin >> monstres; //Demande à l'utilisateur d'entrer un nombre de soldats pour l'armée des monstres.

	//Mise en place du système de combat :
	int humainHP = 20;
	int monstreHP = 20;
	default_random_engine dommageshumain(time(0)); //Générateur de dommages aléatoires pour les humains.
	uniform_int_distribution<int> degatsh(5, 10); //Les humains disciplinés infligent un nombre relativement stable de dommages.
	default_random_engine dommagesmonstre(time(0)); //Générateur de dommages aléatoires pour les monstres.
	uniform_int_distribution<int> degatsm(1, 20); //Les monstres impulsifs peuvent être très faibles ou très dangereux.
	int hit; //Variable contenant les dommages infligés à chaque tour.
	int victoire; //Variable pour récupérer le nombre de soldats restant à la fin de la guerre.

	//Guerre :
	cout << "La guerre commence !" << endl;
	while (humains > 0 && monstres > 0) { //La Guerre continue tant que les deux armées ont encore des soldats.
		hit = degatsh(dommageshumain); //Récupération des dommages infligés par l'humain.
		monstreHP = monstreHP - hit; //Le monstre perd des HP en fonction des dommages infligés.
		if (monstreHP <= 0) {
			monstres += -1; //Si un monstre n'a plus de HP, il meurt...
			//cout << "Un monstre est mort !" << endl;
			monstreHP = 20; //...Et le prochain, ayant tous ses HP, prend sa place.
		}
		hit = degatsm(dommagesmonstre); //Même fonctionnement pour les humains.
		humainHP = humainHP - hit;
		if (humainHP <= 0) {
			humains += -1;
			//cout << "Un humain est mort !" << endl;
			humainHP = 20;
		}
	}
	if (humains == 0) {
		cout << "Les Monstres ont gagne, ils ont pris le pouvoir !" << endl;
		victoire = monstres;
	}
	else {
		cout << "Les Humains ont gagne, ils ont ecrase la revolte des monstres !" << endl;
		victoire = humains;
	}
	cout << "Il ne reste plus que " << victoire << " soldats dans la faction gagnante." << endl;
	cout << "\n";
	system("PAUSE");
	return 0;
}