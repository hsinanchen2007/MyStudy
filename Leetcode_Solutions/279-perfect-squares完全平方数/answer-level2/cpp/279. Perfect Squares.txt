### 解题思路
1. DP 有点类似于背包问题中的完全背包问题
2. 需要明确的是n值越大，最优解趋向于利用j中更大的平方数来划分出子问题
![image.png](https://pic.leetcode-cn.com/4ec9f63a36d5605f6cfffc57b9894acf85abed0a4c23fcca4dd2d9d0545fecef-image.png)


3. 应该需要优化一下时间效率
![image.png](https://pic.leetcode-cn.com/8ca82c5c50de15100d8f3d1d9862301095cb9320385463a44598d8fa71c3ce78-image.png)

### 代码

```cpp
class Solution {
public:
    //完全背包问题？
    //dp[i]和为i的时候，需要的最少的完全平方数的个数
    //dp[i] = dp[i-j*j] + 1(j是子问题削减掉的完全平方数)
    int numSquares(int n) {
    int dp[n + 1] = {0};
    //初始化, 用最差的情况来初始化，比如n==12, 那么最差的情况是12个1相加
    for(int i = 0; i <=n ; i++){
        dp[i] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
        cout << dp[i] <<endl;
    }
    return dp[n];
    }
};
```

### 解题思路
BFS

### 代码

```cpp

```