#include <bits/stdc++.h>
using namespace std;

//#define JUDGE

#define pb push_back
#define ppb pop_back
#define mt make_tuple
#define ll long long
#define uset unordered_set
#define umap unordered_map
#define T int tt, t = 1; cin>>tt; while(tt--)

int main()
{
	#ifdef JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
    cin.tie(0);
	T {
		cout<<"Case #"<<t++<<": ";
		int r, c, h, v;
		cin>>r>>c>>h>>v;
		char mat[r][c];
		int chips = 0;
		for(int i = 0; i < r; i++)
		{
		    string s;
		    cin>>s;
		    int j = 0;
		    for(char x : s) {
		        if(x == '@') {
		            mat[i][j] = '@';   
		            chips++;
		        }
		        else
		            mat[i][j] = '.';
		        j++;
		    }
		}
		if(chips % ((h+1)*(v+1)) != 0)
		    cout<<"IMPOSSIBLE";
		else {
		    int flag = 0;
			for(int i = 1; i < r; i++)
			{
				for(int j = 1; j < c; j++)
				{
					int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
					for(int x = 0; x < i; x++)
					{
						for(int y = 0; y < j; y++)
						{
							if(mat[x][y] == '@')
								c1++;
						}
					}
					for(int x = i; x < r; x++)
					{
						for(int y = 0; y < j; y++)
						{
							if(mat[x][y] == '@')
								c2++;
						}
					}
					for(int x = 0; x < i; x++)
					{
						for(int y = j; y < c; y++)
						{
							if(mat[x][y] == '@')
								c3++;
						}
					}
					for(int x = i; x < r; x++)
					{
						for(int y = j; y < c; y++)
						{
							if(mat[x][y] == '@')
								c4++;
						}
					}
					if(c1 == c2) {
					    if(c2 == c3) {
					        if(c3 == c4)
					            flag = 1;
					    }
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}
			if(flag)
				cout<<"POSSIBLE";
			else
				cout<<"IMPOSSIBLE";
		}
		cout<<endl;
	}
	return 0;
}
