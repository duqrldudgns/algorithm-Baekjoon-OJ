#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int num[10][7] = {
    {1,1,1,0,1,1,1}, // 0
    {0,0,1,0,0,1,0}, // 1
    {1,0,1,1,1,0,1}, // 2
    {1,0,1,1,0,1,1}, // 3
    {0,1,1,1,0,1,0}, // 4
    {1,1,0,1,0,1,1}, // 5
    {1,1,0,1,1,1,1}, // 6
    {1,0,1,0,0,1,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
};

int k,p,ans;
string n,x;

void dfs(int idx, int cnt, string s){  //k, p check
    
    if(idx == k){
        if(s == x || stoi(s) > stoi(n) || stoi(s) == 0) return; // �������� �������. n�� �Ѵ� ���, 0���� ���
        // cout << s << endl;
        ans++;
        return;
    }

    for(int i=0; i<10; i++){
        
        int diff=0, nx = s[idx]-'0';
        for(int j=0; j<7; j++){
            if(num[nx][j] != num[i][j]) diff++;
        }

        if(cnt - diff >= 0){
            string str = s;
            str[idx] = i + '0';
            
            dfs(idx+1 ,cnt-diff, str);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k >> p >> x;
    
    while(x.size() < n.size())
        x.insert(0, "0");

    dfs(0,p, x);

    cout << ans;
}
/*8:32 ~ 9:19
 _   1
| | 2 3
 -   4
| | 5 6
 -   7
*/

/*
�ݷ�
boj - 22251
[2022.4.1/2:44:9]   1sec

[input]
205 4 37 108

[answer]
204

[wrong]
2040

2���ݷ�
boj - 22251
[2022.4.1/3:0:47]	0sec

[input]
108075 6 31 46875

[answer]
108074

[wrong]
999880

*/