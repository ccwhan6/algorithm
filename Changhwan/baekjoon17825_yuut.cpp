#include <iostream>
#include <algorithm>
using namespace std;

struct map {
	int index;
	struct map* next;
};
int maxcost = 0;
int d[10];
void travers(int k1, int k2, int k3, int k4, int dice, int i, int cost);
struct map m[33];
int score1[33] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35 };
int main(void) {
	for (int i = 0; i < 10; i++) {
		cin >> d[i];
	}

	for (int i = 0; i < 33; i++) {
		m[i].index = i;
		m[i].next = NULL;
	}
	m[5].next = &m[22];
	m[24].next = &m[30];
	m[32].next = &m[20];
	m[10].next = &m[25];
	m[26].next = &m[30];
	m[15].next = &m[27];

	travers(0, 0, 0, 0, 0, 0, 0);
	travers(0, 0, 0, 0, 0, 1, 0);
	travers(0, 0, 0, 0, 0, 2, 0);
	travers(0, 0, 0, 0, 0, 3, 0);

	cout << maxcost;

	return 1;
}

void travers(int k1, int k2, int k3, int k4, int dice, int i, int cost) {
	int k[4] = { k1, k2, k3, k4 };
	int loc = k[i];
	int done = 0;
	struct map* m_temp;

	int cnt = d[dice];
	if (cnt <= 20 && m[loc].next == NULL) {
		loc += cnt;
		if (loc > 20) {
			loc = 21;
		}
	}
	else if (m[loc].next != NULL || cnt >= 22) {
		for (cnt; cnt > 0; cnt--) {
			if (m[loc].next != NULL) {
				m_temp = m[loc].next;
				loc = m_temp->index;
			}
			else {
				loc++;
			}
			if (loc == 20 && cnt > 1) {
				loc = 21;
				break;
			}
		}
	}

	dice++;
	if (dice < 10) {
		k[i] = loc;
		if (k[i] != 21) {
			cost += score1[loc];
		}

		for (int i = 0; i < 4; i++) {
			if (k[i] != 21) {
				travers(k[0], k[1], k[2], k[3], dice, i, cost);
			}
		}

		if (k[0] == 21 && k[1] == 21 && k[2] == 21 && k[3] == 21) {
			if (cost >= maxcost) {
				maxcost = cost;
			}
		}
	}
	else {
		if (cost >= maxcost) {
			maxcost = cost;
		}
	}
}


