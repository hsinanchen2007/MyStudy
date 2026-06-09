等价于最大化半个背包的重量
代码如下：
```
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int S = sum / 2;
        int N = stones.size();
        vector<vector<int> > dp(S + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= S; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = max(dp[i][j - 1],
                    (i >= stones[j - 1]) ? dp[i - stones[j - 1]][j - 1] + stones[j - 1] : 0); 
            }
        }
        return sum - 2 * dp[S][N];
    }
};

// 也可以使用状态压缩后的dp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int S = sum / 2;
        int N = stones.size();
        vector<int> dp(S + 1, 0);
        for (int i = 0; i < N; ++i) {
            int w = stones[i];
            for (int j = S; j >= w; --j) {
                dp[j] = max(dp[j], dp[j - w] + w);
            }
        }
        return sum - 2 * dp[S];
    }
};
```
![image.png](https://pic.leetcode-cn.com/837e7550f42e0884763fc6818c54d54178e090be890e51d103d15bd4b73a935e-image.png)
