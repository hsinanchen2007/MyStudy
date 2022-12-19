class Solution {
public:
    //递归规律
    //0 1 -> 00 10 11 01-> 000 100 110 010 011 111 101 001
    //在上一组里全部尾后补0再倒序全部补1->格雷编码
    //因此 正序*2然后在倒序*2+1->类似斐波那契数列动态规划
    vector<int> grayCode(int n) {
        if(n==0) return{0};
        vector<vector<int>> dp(n+1);
        dp[0]={0};dp[1]={0,1};
        for(int i=2;i<=n;++i){
            for(int j=0;j!=dp[i-1].size();++j)
                dp[i].push_back(dp[i-1][j]*2);
            for(int j=dp[i-1].size()-1;j>=0;--j)
                dp[i].push_back(dp[i-1][j]*2+1);
        }
        return dp[n];
    }
};