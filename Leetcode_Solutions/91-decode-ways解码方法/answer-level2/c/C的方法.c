int numDecodings(char * s){
        int len=strlen(s);

        if(len==0||s[0]=='0')  return 0;
                  //int res=s[0];
         //if(len==1)  return res;
       // if()
                 else {
        int dp[10000];
        int visited[1000];
        memset(visited,0,sizeof(visited));
        int i, j;
        dp[0]=1;  dp[1]=1;
        for(i=1;i<len;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                dp[i+1]=dp[i-1];
                else 
                return 0;
            }
            else 
            {
                if(s[i-1]=='1')
                dp[i+1]=dp[i]+dp[i-1];
                else if(s[i-1]=='2')
                {
                    if(s[i]<='6')
                    dp[i+1]=dp[i]+dp[i-1];
                    else 
                    dp[i+1]=dp[i];
                }
                else 
                dp[i+1]=dp[i];
            }

        }
        return dp[len];
        
        }

}