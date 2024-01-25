class Solution {
public:
    int dp[1002][1002];
    
    int f(string &a,string &b,int x,int y)
    {
        int ans=0;
        if(x<0 || y<0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
            if(a[x]==b[y])
            {
                cout << "EKHANE" << endl;
                ans=1+f(a,b,x-1,y-1);
            }
            else 
            {
                 ans = max(f(a,b,x-1,y),f(a,b,x,y-1));
            }
        return dp[x][y]=ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return f(text1,text2,text1.size()-1,text2.size()-1);
    }
};