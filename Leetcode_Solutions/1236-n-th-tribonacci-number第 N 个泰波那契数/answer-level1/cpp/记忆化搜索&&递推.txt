class Solution {
public:
    int dp[38]={0,1,1};
    int tribonacci(int n) {
        if(n==0)return 0;
        return dp[n]?dp[n]:dp[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};

class Solution {
public:
    int tribonacci(int n) {
        int dp[1000]={0,1,1};
        if(n==0)return 0;
        else if(n==1||n==2)return 1;
        for(int i=3;i<=n;i++)dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        return dp[n];
    }
};
