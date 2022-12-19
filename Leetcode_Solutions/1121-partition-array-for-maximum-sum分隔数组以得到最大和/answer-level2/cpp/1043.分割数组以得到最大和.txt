class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int dp[A.size()+1]={0};
        for(int i=1;i<=A.size();++i){
            int maxtemp=A[i-1];
            for(int j=1;j<=K;++j){
                if(i-j>=0){
                    maxtemp=max(maxtemp,A[i-j]);//标准就是A[i-1] 即求A[i-k]~A[i-1]中的最大值
                    dp[i]=max(dp[i],dp[i-j]+j*maxtemp);
                }
            }
        }
        return dp[A.size()];
    }
};