我们设dp[i][j]：以第j个元音字符结尾的方案数
然后去除掉所有不合法的方案数即可。。。
```
class Solution {
	int mod = 1000000007;
    public int countVowelPermutation(int n) {
        int[][] dp=new int[n+1][5];
        for(int i=0;i<5;i++)
        	dp[0][i]=1;
        for(int i=1;i<n;i++)
        	for(int j=0;j<5;j++)
        		for(int h=0;h<5;h++)
        		{
        			if(h==0 && j!=1 || h==1 && j!=0 && j!=2 || h==2 && j==2) 
        				continue;
        			if(h==3 && j!=2 && j!=4 || h==4 && j!=0)
        				continue;
        			dp[i][j]=(dp[i][j]+dp[i-1][h])%mod;
        		}
        int ans=0;
        for(int i=0;i<5;i++)
        	ans=(ans+dp[n-1][i])%mod;
        return ans;
    }
}
```
