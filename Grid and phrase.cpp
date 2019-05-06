#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fast
    
    int n,m;
    
    cin >> n >> m;
    
    string s[n+1];
    
    for(int i = 0; i < n; i++)
        cin >> s[i];
        
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == 's')
            {
                if(j+1 < m and j+2 < m and j+3 < m)
                {
                    if(s[i][j+1] == 'a' and s[i][j+2] == 'b' and s[i][j+3] == 'a')
                    {
                        ans++;
                    }
                    if(i+1 < n and i+2 < n and i+3 < n)
                    {
                        if(s[i+1][j+1] == 'a' and s[i+2][j+2] == 'b' and s[i+3][j+3] == 'a')
                        {
                            ans++;
                        }
                    }
                    if(i-1 >= 0 and i-2 >= 0 and i-3 >= 0)
                    {
                        if(s[i-1][j+1] == 'a' and s[i-2][j+2] == 'b' and s[i-3][j+3] == 'a')
                        {
                            ans++;
                        }
                    }
                }
                if(i+1 < n and i+2 < n and i+3 < n)
                {
                    if(s[i+1][j] == 'a' and s[i+2][j] == 'b' and s[i+3][j] == 'a')
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
}
