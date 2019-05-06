#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n,m;
int maze[1005][1005];
int ap,bp;
ll trace[1005][1005];
int vis[1005][1005];
string s[1010];
int done[1005][1005];

bool valid(int x,int y1)
{
    int col = y1*2;
    
    if(s[x][col] == '|')
        return false;
    return true;
}
bool valid1(int x1, int y)
{
    int col = y*2 - 1;
    
    if(s[x1][col] == '_')
        return false;
    return true;
}

void catchit(int x, int y, ll c)
{
    if(done[x][y] == 0){
        
        trace[x][y] = c;
        done[x][y] = 1;
    }else{
        
        trace[x][y] = min(trace[x][y], c);
    }
    
    vis[x][y] = 1;

    if(y+1 <= m)
    {
        if(valid(x,y) and trace[x][y+1] > 0 and vis[x][y+1] == 0)
        {
            if(trace[x][y+1] != c+1 or done[x][y+1] == 0)
                catchit(x,y+1,c+1);
        }
    }
    if(y-1 >= 1)
    {
        if(valid(x,y-1) and trace[x][y-1] > 0 and vis[x][y-1] == 0)
        {
            if(trace[x][y-1] != c+1 or done[x][y-1] == 0)
                catchit(x,y-1,c+1);
        }
    }
    if(x+1 <= n)
    {
        if(valid1(x,y) and trace[x+1][y] > 0 and vis[x+1][y] == 0)
        {
            if(trace[x+1][y] != c+1 or done[x+1][y] == 0)
                catchit(x+1,y,c+1);
        }
    }
    if(x-1 >= 1)
    {
        if(valid1(x-1,y) and trace[x-1][y] > 0 and vis[x-1][y] == 0)
        {
            if(trace[x-1][y] != c+1 or done[x-1][y] == 0)
                catchit(x-1,y,c+1);
        }
    }
}

void run(int x, int y, int c)
{
    trace[x][y] = c;
    vis[x][y] = 1;
    
    if(y+1 <= m)
    {
        if(valid(x,y) and maze[x][y+1] == 0 and vis[x][y+1] == 0)
        {
            run(x,y+1,c+1);
        }
    }
    if(y-1 >= 1)
    {
        if(valid(x,y-1) and maze[x][y-1] == 0 and vis[x][y-1] == 0)
        {
            run(x,y-1,c+1);
        }
    }
    if(x+1 <= n)
    {
        if(valid1(x,y) and maze[x+1][y] == 0 and vis[x+1][y] == 0)
        {
            run(x+1,y,c+1);
        }
    }
    if(x-1 >= 1)
    {
        if(valid1(x-1,y) and maze[x-1][y] == 0 and vis[x-1][y] == 0)
        {
            run(x-1,y,c+1);
        }
    }
}

int main()
{
    fast
    
    cin >> n >> m >> ap >> bp;

    cin.ignore();
    for(int i = 0; i < n+1; i++)
    {
        getline(cin, s[i]);
    }
    
    int k;
    cin >> k;
    
    memset(maze,0,sizeof(maze));
    set< pair<int,int> > edges;
    while(k--)
    {
        int a,b;
        cin >> a >> b;
        edges.insert({a,b});
        maze[a][b] = 1;
    }
    
    memset(trace,-1,sizeof(trace));
    memset(vis,0,sizeof(vis));
    
    run(ap,bp,0);
    
    trace[ap][bp] = 1e9;
    
    memset(done,0,sizeof(done));
    for(auto it = edges.begin(); it != edges.end(); it++)
    {
        pair<int,int> p;
        
        p = *it;
        
        memset(vis,0,sizeof(vis));
        
        catchit(p.first, p.second, 0);
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(ans < trace[i][j])
                ans = trace[i][j];
        }
    }
    cout << ans;
}
