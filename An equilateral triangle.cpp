#include<iostream>
using namespace std;

int a[105];

int find(int x)
{
    int res = 0;
    
    for(int i = x-2; i >= 1; i--)
    {
        res += (i * (i+1)/2);
    }
    
    return res+a[x-2];
}

int main()
{
    int n;
    
    cin >> n;
    
    a[0] = a[1] = a[2] = 0;
    
    a[3] = 1;
    
    for(int i = 4; i <= n; i++)
    {
        a[i] = find(i);
    }
    
    cout << a[n];
}
