```c++
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        if(n < 1) return 0;
        if(K > n) return 0;
        vector<vector<double>> dp(n, vector<double>(n+1, 0));
        vector<int> sum(n);
        sum[0] = A[0];
        dp[0][1] = A[0];
        for(int i=1;i<n;++i){
            sum[i] = sum[i-1] + A[i];
            dp[i][1] = sum[i] / double(i+1);
        }
        for(int i=1;i<n;++i){
            for(int k=2;k<=min(K, i+1);++k) {
                for(int j=k-2;j<i;++j) { //转移方程，dp[i][k]表示将0..i 数组划分成 k 个子数组后的最大平均值
                                        //j 必须>= k-1
                    dp[i][k] = max(dp[i][k], dp[j][k-1] + (sum[i]-sum[j]) / double(i - j));
                }
            }
        }
        return dp[n-1][K];
    }
};
```