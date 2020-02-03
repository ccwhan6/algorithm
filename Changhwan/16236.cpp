#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

typedef struct _feed {
    int x;
    int y;
    int mv_cnt;
}feed;

int search_feed();

int N = 0;
char map_c[20][20];
int map[20][20] = {10, };
int map_t[20][20] = {10, };
int baby_shark_sz = 2;
int baby_shark_lc[2] = {0,};
int next_tar[2] = {0, };

int main(void){

    int cnt = 0;
    int move = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> map_c[i];
    }

    for(int i = 0; i< N; i++){
        for(int j = 0; j<N; j++){
            map[i][j] = map_c[i][j] - '0';
            if (map[i][j] == 9){
                baby_shark_lc[0] = i;
                baby_shark_lc[1] = j;
                map[i][j] = 10;
            }
        }
    }

    cnt = search_feed();
    while(cnt > 0){

    }

    return 0;
}

int search_feed(){
    int cnt = 0;
    int shortest = 40;
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] < baby_shark_sz && map[i][j] != 0){
                if (shortest > (abs(i-baby_shark_lc[0]) + abs(j-baby_shark_lc[1]))){
                    next_tar[0] = i;
                    next_tar[1] = j;
                    shortest = (abs(i-baby_shark_lc[0]) + abs(j-baby_shark_lc[1]));
                }
            }
        }
    }
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] < baby_shark_sz && map[i][j] != 0){
                if (shortest == (abs(i-baby_shark_lc[0]) + abs(j-baby_shark_lc[1]))){
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int move_shark(int **map){
    queue<feed> feed_q;

}
