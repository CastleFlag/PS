#include <bits/stdc++.h>
using namespace std;

int N;
int main(){
    cin >> N;
    int divider = 2;
    while(divider <= N){
        if(N % divider == 0){
            N /= divider;
            cout << divider << endl;
        }
        else{
            divider++;
        }
    }
}