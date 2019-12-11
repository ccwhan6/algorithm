#include <iostream>
using namespace std;

struct map{
	int index;
	struct map* next;
	int score;
};
int maxcost = 0;
int d[10];
int k[4] = { 0, };

struct map m[33];
int score1[33] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35 };
int main(void) {
	
	for (int i = 0; i < 33; i++) {
		m[i].index = i;
		m[i].score = score1[i];
		m[i].next = NULL;
	}

	return 1;
}

void travers(int k[], int dice, int i, int cost) {
	struct map t;
	if (dice <= 9) {
		if (k[i] == 5) {
			if (d[dice] <= 3) {
				k[i] = 21 + d[dice];
				cost += m[k[i]].score;
			}
			else {
				k[i] = 30 + d[dice] - 4;
				cost += m[k[i]].score;
			}
		}
		else if (k[i] == 10) {
			if (d[dice] <= 2) {
				k[i] = 24 + d[dice];
				cost += m[k[i]].score;
			}
			else {
				k[i] = 30 + d[dice] - 3;
				cost += m[k[i]].score;
			}

		}
		else if (k[i] == 15) {

		}
		else {

		}
	}

}

