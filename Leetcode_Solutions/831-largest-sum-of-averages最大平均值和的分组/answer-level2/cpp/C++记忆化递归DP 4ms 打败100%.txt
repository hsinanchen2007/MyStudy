给定数组A分成K个相邻的非空子数组的最大分数：
1、选定 1 ~ N(N与数组长度与K有关) 个连续数字作为第一组
2、剩余的连续数字组成数组B获取其分成K - 1个相邻的非空子数组的最大分数
3、取选择 1 ~ N 中的最大分数为DP(A, K)的结果
```
class Solution {
public:
    double dp[101][101];
    double dfs(vector<int> & A, int K, int index) {
        // 该结果已计算过
        if (dp[index][K] != -1) {
            return dp[index][K];
        }
        double res = 0;
        // 该层次为最后一组，直接累加返回结果
        if (K == 1) {
            for (int i = index; i < A.size(); i++) {
                res += A[i];
            }
            return dp[index][K] = res / (A.size() - index);
        }
        int sum = 0;
        // 该层次选择 1 ~ n个连续数字
        for (int i = index; i <= A.size() - K; i++) {
            sum += A[i];
            double temp = 1.0 * sum / (i - index + 1);
            temp += dfs(A, K - 1, i + 1);
            if (temp > res) {
                res = temp;
            }
        }
        return dp[index][K] = res;
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        // 初始化记忆表
        for (int i = 0; i < A.size(); i++) {
            for (int j = 1; j <= K; j++) {
                dp[i][j] = -1;
            }
        }
        return dfs(A, K, 0);
    }
};

```
![image.png](https://pic.leetcode-cn.com/26f8444e7cc2c3c2af3a19d772e67e27aadc6c88334859a79a96788f30db0590-image.png)
