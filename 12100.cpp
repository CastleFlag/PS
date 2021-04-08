#include <bits/stdc++.h>
using namespace std;

int N;
int board[21][21];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0,  0,-1, 1};
int sx[4] = {0, 0, 0, 0}; // N 0 0 0
int sy[4] = {0, 0, 0, 0}; // 0 0 N 0
int di[4] = {-1, 0, -1, 0};

int solve(){
    int dir = 0;
    int number, isSumed;
    int _dx = dx[dir], _dy = dy[dir], _sx = sx[dir], _sy = sy[dir], _di = di[dir];

    for(int i=1; i<=N; i++){
        isSumed = 0;
        number = -1;
        for(int j=1; j<=N; j++){
            if(number==board[i][j] && isSumed==0){
                isSumed = 1;
                board[i][j] = number*2;
                board[i-dy[dir]][j-dx[dir]] = 0;
            }
            else if(board[i][j] == 0){
                for(int k=j; k>=1; k--){
                    board[i][k] = board[i-dy[dir]][k-dx[dir]];
                }
            }
            else{
                isSumed = 0;
                number = board[i][j];
            }
        }
    }
    return 0;
}
int main(){
    cin >> N;
    sx[0]=N;
    sy[2]=N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }
    solve();
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            printf("%3d", board[i][j]);
        }
        cout<<endl;
    }


}