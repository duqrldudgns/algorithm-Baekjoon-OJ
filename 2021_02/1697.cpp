#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

#define MAX 100001

int N, K;
vector<int> check(MAX, 0);
bool visited[MAX];
queue<int> q;

void BFS(int x, int y){

    visited[x] = true;
    q.push(x);

    while(!q.empty()){

        int now = q.front();
        q.pop();

        if( now == y ){
            cout << check[now] << endl;
            break;
        }

        if( now+1 < MAX && visited[now+1] == false ){
            q.push(now+1);
            visited[now+1] = true;
            check[now+1] = check[now] +1;
        }

        if( now-1 >= 0 && visited[now-1] == false ){
            q.push(now-1);
            visited[now-1] = true;
            check[now-1] = check[now] +1;
        }        
        
        if( now*2 < MAX && visited[now*2] == false ){
            q.push(now*2);
            visited[now*2] = true;
            check[now*2] = check[now] +1;
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    
    BFS(N, K);
}