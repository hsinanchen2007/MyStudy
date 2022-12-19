### 解题思路
记忆化搜索
1. 构造dp数组用来存放每个pos的最大跳数
2. 计算pos位置的dp值时
    1. 如果dp[pos]不是初始值0，直接返回 （记忆化dfs搜索的加速原理）
    2. 递归终点：计算跳数为1的情况，比左右值都小时，或者首元素比后面元素小，或者尾元素比前面元素小（搜索终点写的比较繁琐，不知有没有更简洁的写法）
    3. 一般情况：对所有可达位置pos，递归调用本函数。

### 代码

```cpp
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        if (arr.size() == 1) return 1;
        vector<int> dp(arr.size(), 0);
        int result = 1;
        for (int i = 0; i < arr.size(); ++i) {
            result = max(result, maxJumps(arr, dp, d, i));
        }
        return result;
    }

    int maxJumps(vector<int>& arr, vector<int>& dp, int d, int pos) {
        if (dp[pos]) return dp[pos];
        if (pos-1 < 0 && arr[pos] <= arr[pos+1]) {
            dp[pos] = 1;
            return dp[pos];
        }
        if (pos+1 >= arr.size() && arr[pos] <= arr[pos-1]) {
            dp[pos] = 1;
            return dp[pos];
        };
        if (pos-1 >= 0 && pos+1 < arr.size() && arr[pos] <= arr[pos-1] && arr[pos] <= arr[pos+1]) {
            dp[pos] = 1;
            return dp[pos];
        }
        for (int i = 1; i <= d; ++i) {
            if (pos-i < 0 || arr[pos] <= arr[pos-i]) break;
            dp[pos] = max(dp[pos], maxJumps(arr, dp, d, pos - i) + 1);
        }
        for (int i = 1; i <= d; ++i) {
            if (pos+i >= arr.size() || arr[pos] <= arr[pos+i]) break;
            dp[pos] = max(dp[pos], maxJumps(arr, dp, d, pos + i) + 1);
        }
        return dp[pos];
    }
};
```