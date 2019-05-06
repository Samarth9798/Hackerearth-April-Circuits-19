#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

vector<int> v[100005];
int ans[100005];
int vis[100005];

void dfs(int x)
{
    vis[x] = 1;
    
    ans[x] = v[x].size();
    
    for(int i = 0 ; i < v[x].size(); i++)
    {
        if(vis[v[x][i]] == 0)
        {
            dfs(v[x][i]);
        }
    }
}

int main()
{
    fast
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n-1; i++)
    {
        int x,y;
        
        cin >> x >> y;
        
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    dfs(1);
    
    set<int> s;
    int c = 0;
    
    int m = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(ans[i] > m)
            m = ans[i];
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(ans[i] == m)
        {
            c++;
            s.insert(i);
        }
    }
    
    cout << c << endl;
    for(auto it = s.begin(); it != s.end(); it++)
        cout << *it << ' ';
}
