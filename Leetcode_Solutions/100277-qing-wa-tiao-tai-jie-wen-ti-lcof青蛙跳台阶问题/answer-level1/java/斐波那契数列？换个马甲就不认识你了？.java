class Solution {
    public int numWays(int n) {
        int []dp=new int [n+3];
        dp[0]=1;dp[1]=1;dp[2]=2;
        int i;
        for(i=3;i<=n;i++)
            dp[i]=dp[i-1]%1000000007+dp[i-2]%1000000007;
        return dp[n]%1000000007;
    }
}
还可以直接利用斐波那契数列的通项公式求解。
{[(sqrt(5)+1)/2]^n+[(1-sqrt(5))/2]^n}/sqrt(5)。
[链接，斐波那契数列通项公式的推导](https://www.zhihu.com/question/25217301)