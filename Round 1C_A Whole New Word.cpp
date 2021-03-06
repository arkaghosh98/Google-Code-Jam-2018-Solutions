#include   <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define T int tt; cin>>tt; while(tt--)

const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;

int main() {
    fastio;
    int t = 1;
    T {
        cout<<"Case #"<<t++<<": ";
        int n, l;
        cin>>n>>l;
        umap<string, int> m;
        vector<string> s(n);
        for(int i = 0; i < n; i++)
        {
            cin>>s[i];
            m[s[i]] = 1;
        }
        if(l == 1) {
            cout<<"-"<<endl;
        }
        else {
            int flag = 0, i;
            for(i = 0; i < l; i++)
            {
                for(int j = 1; j < n; j++)
                {
                    if(s[j][i] != s[j-1][i]) {
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            umap<char, int> c;
            for(int j = i; j < l; j++)
            {
                for(int k = 0; k < n; k++)
                    c[s[k][j]]++;
            }
            int sz = c.size();
            if(pow(sz, l-i) == n) {
                cout<<"-"<<endl;
            }
            else {
                int flag1 = 0;
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < l; j++)
                    {
                        string t = s[i].substr(0, j+1);
                        for(int k = 0; k < n; k++)
                        {
                            if(k != i) {
                                string y = t + s[k].substr(j+1, l-(j+1));
                                if(!m.count(y)) {
                                    flag1 = 1;
                                    cout<<y<<endl;
                                    break;
                                }
                            }
                        }
                        if(flag1)
                            break;
                    }
                    if(flag1)
                        break;
                }
                if(!flag1)
                    cout<<"-"<<endl;
            }
        }
    }
	return 0;
}  
