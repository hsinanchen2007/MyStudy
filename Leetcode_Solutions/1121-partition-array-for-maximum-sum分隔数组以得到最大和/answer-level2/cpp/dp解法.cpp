![image.png](https://pic.leetcode-cn.com/88eb4f39792f7ea4a0490b5d26d0843346c247f46353539d4fed7dd5caaad5f7-image.png)

- 状态表示
dp[i]表示从A[0]~A[i-1]的解
- 状态转移
$dp[i] = max_{j=1}^{K} \{dp[i-j] + max(A[i-j+1],...,A[i-1]) * j\}$
```c++
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int>dp(n+1);
        for(int i=1;i<=n;i++){
            int t = A[i-1];
            for(int j=1;j<=K;j++){
                if(i-j>=0){
                    t = max(t,A[i-j]);
                    dp[i] = max(dp[i], dp[i-j] + t * j);
                }else break;
            }
        }
        return dp[n];
    }
};
```
