import java.util.*;
import java.io.*;

class TestClass {
    
    static void solve(String[] s, int n, int m)
    {
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i].charAt(j) == 's')
                {
                    if(j+1 < m && j+2 < m && j+3 < m)
                    {
                        if(s[i].charAt(j+1) == 'a' && s[i].charAt(j+2) == 'b' && s[i].charAt(j+3) == 'a')
                        {
                            ans++;
                        }
                        if(i+1 < n && i+2 < n && i+3 < n)
                        {
                            if(s[i+1].charAt(j+1) == 'a' && s[i+2].charAt(j+2) == 'b' && s[i+3].charAt(j+3) == 'a')
                            {
                                ans++;
                            }
                        }
                        if(i-1 >= 0 && i-2 >= 0 && i-3 >= 0)
                        {
                            if(s[i-1].charAt(j+1) == 'a' && s[i-2].charAt(j+2) == 'b' && s[i-3].charAt(j+3) == 'a')
                            {
                                ans++;
                            }
                        }
                    }
                    if(i+1 < n && i+2 < n && i+3 < n)
                    {
                        if(s[i+1].charAt(j) == 'a' && s[i+2].charAt(j) == 'b' && s[i+3].charAt(j) == 'a')
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        
        System.out.print(ans);
    }
    
    public static void main(String args[] ) throws Exception {
       
       Scanner in = new Scanner(System.in);
       
       int n,m;
       n = in.nextInt();
       m = in.nextInt();
       
       String s[] = new String[n];
       
       for(int i = 0; i < n; i++)
            s[i] = in.next();
            
        solve(s, n, m);
    }
}
