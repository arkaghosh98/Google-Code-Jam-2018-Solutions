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
        int area;
        cin>>area;
        bool mat[1000][1000];
        memset(mat, false, sizeof(mat));
        int x = -2, y = -2, x1 = 401, y1 = 401, x2, y2;
        cout<<x1<<" "<<y1<<endl;
        cin>>x1>>y1;
        if(area == 20) {
            x2 = x1 + 5;
            y2 = y1 + 6;
        } else {
            x2 = x1 + 11;
            y2 = y1 + 21;
        }
        cout<<x2<<" "<<y2<<endl;
        cin>>x2>>y2;
        mat[x1][y1] = true;
        mat[x2][y2] = true;
        int done;
        while(x != 0 && y != 0) {
            int i, j; x = -1; y = -1;
            for(i = x1; i <= x2; i++)
            {
                for(j = y1; j <= y2; j++)
                {
                    if(mat[i][j] == false) {
                        if(i == x1)
                            x = x1+1;
                        else if(i == x2)
                            x = x2-1;
                        else
                            x = i;
                        if(j == y1)
                            y = y1+1;
                        else if(j == y2)
                            y = y2-1;
                        else
                            y = j;
                        break;
                    }
                }
                if(x != -1 && y != -1)
                        break;
            }
            cout<<x<<" "<<y<<endl;
            cin>>x>>y;
            if(x == -1 && y == -1)
                break;
            mat[x][y] = true;
        }
        if(x == -1 && y == -1)
            break;
	}
	return 0;
}
