# 解法一：
二维动态规划
**思路：**
1，`arr2`先做从小到大排序并去重
2，变量定义
1) `dp[i][0]`代表截止到`arr1`的下标`i`为止，`arr1[i]`不做替换操作的最小操作数
2) `dp[i][j] (j > 0)`代表截止到`arr1`的下标`i`为止，`arr1[i]`替换为`arr2[j - 1]`的最小操作数

3，状态转移方程分4种情况讨论：
1) 上一步和本步都进行替换的情况：
`dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1) (j >= 2)`
2) 上一步和本步都不进行替换的情况：
如果`arr[i] > arr[i - 1]`，则`dp[i][0] = min(dp[i][0], dp[i - 1][0])`
3) 上一步不进行替换，本步进行替换：
`dp[i][j] = min(dp[i][j], dp[i - 1][0] + 1) (arr1[i - 1] < arr2[j - 1])`
4) 上一步进行替换，本步不进行替换：
`dp[i][0] = min(dp[i][0], dp[i - 1][j]) (arr2[j - 1] < arr1[i])`

4，有一个优化点是，对于截止到任何一个`arr1`的下标`i`，如果都找不到满足条件的情况，则可以提前返回-1。

```C++ []
class Solution {
public:
    const int INF = 1e8;
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int N1 = arr1.size();
        int N2 = arr2.size();
        vector<vector<int> > dp(N1, vector<int>(N2 + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= N2; ++i) {
	         dp[0][i] = 1;
        }
        for (int i = 1; i < N1; ++i) {
            // 上一步和本步都进行替换的情况
        	for (int j = 2; j <= N2; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
            // 上一步和本步都不进行替换的情况
            if (arr1[i] > arr1[i - 1]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
            // 上一步不进行替换，本步进行替换
            int k = lower_bound(arr2.begin(), arr2.end(), arr1[i - 1] + 1) - arr2.begin();
            for (int j = k; j < N2; ++j) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][0] + 1);
            }
            // 上一步进行替换，本步不进行替换
            int l = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin() - 1;
            for (int j = 0; j <= l; ++j) {
                 dp[i][0] = min(dp[i][0], dp[i - 1][j + 1]);
            }
            if (*min_element(dp[i].begin(), dp[i].end()) == INF) return -1;
        }
        return *min_element(dp[N1 - 1].begin(), dp[N1 - 1].end());
    }
};
```

![image.png](https://pic.leetcode-cn.com/4dcccc9871b69c1e9ef26fa0d69a97b07ef16276918f3fba9664fa9043fd4049-image.png)


# 解法二：
状态压缩动态规划，思路与方法与解法一相同，但空间复杂度降为O(len(arr2))
```C++ []
class Solution {
public:
    const int INF = 1e8;
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int N1 = arr1.size();
        int N2 = arr2.size();
        vector<int> dp(N2 + 1, 1);
        dp[0] = 0;
        for (int i = 1; i < N1; ++i) {
            auto dp1 = vector<int>(N2 + 1, INF);
            // 上一步和本步都进行替换的情况
            for (int j = 2; j <= N2; ++j) {
                dp1[j] = min(dp1[j], dp[j - 1] + 1);
            }
            // 上一步和本步都不进行替换的情况
            if (arr1[i] > arr1[i - 1]) {
                dp1[0] = min(dp1[0], dp[0]);
            }
            // 上一步不进行替换，本步进行替换
            int k = lower_bound(arr2.begin(), arr2.end(), arr1[i - 1] + 1) - arr2.begin();
            for (int j = k; j < N2; ++j) {
                dp1[j + 1] = min(dp1[j + 1], dp[0] + 1);
            }
            // 上一步进行替换，本步不进行替换
            int l = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin() - 1;
            for (int j = 0; j <= l; ++j) {
                dp1[0] = min(dp1[0], dp[j + 1]);
            }
            swap(dp1, dp);
            if (*min_element(dp.begin(), dp.end()) == INF) return -1;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
```

![image.png](https://pic.leetcode-cn.com/e3d41a33483fa64669ada887ab972ef26b1e3f8955cc7c820a1c59ac980a2b92-image.png)
