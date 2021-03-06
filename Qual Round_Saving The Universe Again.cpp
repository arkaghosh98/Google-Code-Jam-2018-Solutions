#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ppb pop_back
#define mt make_tuple
#define ll long long
#define ull unsigned long long
#define uset unordered_set
#define umap unordered_map
#define T int tt, t = 1; cin>>tt; while(tt--)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	T {
		cout<<"Case #"<<t++<<": ";
		ull d;
		string p;
		cin>>d>>p;
		int n = p.size();
		ull current_charge = 1, total_damage = 0;
		vector<pair<char, ull> > a;
		for(int i = 0; i < n; i++)
		{
		    if(p[i] == 'S') {
		        a.pb({p[i], current_charge});
		        total_damage += current_charge;
		    } else {
		        current_charge *= 2;
		        a.pb({p[i], current_charge});
		    }
		}
	    ull count = 0, flag = 0;
	    while(total_damage > d) {
	        flag = 1;
	        for(int i = n-1; i > 0; i--)
	        {
	            if(a[i].first == 'S' && a[i-1].first == 'C') {
	                a[i].first = 'C'; a[i-1].first = 'S';
	                a[i-1].second = a[i].second/2;
	                total_damage -= a[i-1].second;
	                flag = 0;
	                count++;
	                break;
	            }
	        }
	        if(flag)
	            break;
	    }
	    if(flag)
	        cout<<"IMPOSSIBLE";
	    else
	        cout<<count;
		cout<<endl;
	}
	return 0;
}
