#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

string tab[9] = {" "," "," "," "," "," "," "," "};
int player = 1;
int pos = 0;

void introduction() {
	cout << "---------------------------------\n";
	cout << "---------------------------------\n";
	cout << "           MORPION				          \n";
	cout << "---------------------------------\n";
	cout << "---------------------------------\n";
	cout << "\n";
	cout << "Player1:" << "'X'\n";
	cout << "Player2:" << "'O'\n";
	std::cout << "     |     |      \n";
	std::cout << "  1  |  2  |  3   \n";
	std::cout << "_____|_____|_____ \n";
	std::cout << "     |     |      \n";
	std::cout << "  4  |  5  |  6   \n";
	std::cout << "_____|_____|_____ \n";
	std::cout << "     |     |      \n";
	std::cout << "  7  |  8  |  9   \n";
	std::cout << "     |     |      \n\n";
}
void draw() {
	cout << "     |     |      \n";

	cout << "  " << tab[0] << "  |  " << tab[1] << "  |  " << tab[2] << "\n";

	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";

	cout << "  " << tab[3] << "  |  " << tab[4] << "  |  " << tab[5] << "\n";

	cout << "_____|_____|_____ \n";
	cout << "     |     |      \n";

	cout << "  " << tab[6] << "  |  " << tab[7] << "  |  " << tab[8] << "\n";
	cout << "     |     |      \n";

	cout << "\n";
}
bool is_winner(){
	bool winner = false;
	if (tab[0] == tab[1] && tab[1] == tab[2] && tab[0] != " ") {
		winner = true;
	}
	else if (tab[0] == tab[3] && tab[0] == tab[6] && tab[0] != " ") {
		winner = true;
	}
	else if (tab[1] == tab[4] && tab[1] == tab[7] && tab[1] != " ") {
		winner = true;
	}
	else if (tab[2] == tab[5] && tab[2] == tab[8] && tab[2] != " ") {
		winner = true;
	}
	else if (tab[3] == tab[4] && tab[3] == tab[5] && tab[3] != " ") {
		winner = true;
	}
	else if (tab[6] == tab[7] && tab[6] == tab[8] && tab[6] != " ") {
		winner = true;
	}
	else if (tab[0] == tab[4] && tab[0] == tab[8] && tab[0] != " ") {
		winner = true;
	}
	else if (tab[2] == tab[4] && tab[2] == tab[6] && tab[2] != " ") {
		winner = true;
	}
	return winner;
}

bool remplir() {
	bool rempli = true;
	for (int i = 0; i < 9; i++) {
		if (tab[i] == " ") {
			rempli = false;
		}
	}
	return rempli;
}
void setPosition() {
	cout << "Player" << player << " rentrer un nombre de 1 a 9: \n";

	while (!(cin >> pos)) {
		cout << "Player" << player << "rentrer un nombre de 1 a 9: \n";
		cin.clear();
		cin.ignore();
	}

	cout << "\n";

	while (tab[pos - 1] != " ") {

		cout << "deja quelque chose a cette position\n";

		cout << "Player: " << player << "rentrer un nombre de 1 a 9: \n";
		cin >> pos;
		
		cout << "\n";
	}
}
void tableau_a_jour() {
	if (player % 2 == 1) {
		tab[pos - 1] = "X";
	}
	else {
		tab[pos - 1] = "O";
	}
}

void change_player() {
	if (player == 1) {
		player++;
	}
	else {
		player--;
	}
}
void tourne() {
	while (!is_winner() && !remplir()) {
		setPosition();
		tableau_a_jour();
		change_player();
		draw();
	}
}
void end_game() {
	if (is_winner()) {
		cout << "Il y a un gagnant\n";
	}
	else if(remplir()) {
		cout << "Houps le morpion est remplis pas de gagnant !\n";

	}
}
