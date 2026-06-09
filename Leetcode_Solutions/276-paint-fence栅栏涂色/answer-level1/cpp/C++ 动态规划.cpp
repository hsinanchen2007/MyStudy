### 解题思路
1，`dp1`代表当前颜色与前一个栅栏颜色相同的情况数，`dp2`代表当前颜色与前一个栅栏颜色不同的情况数
2，状态转移方程
令前一个栅栏的情况为`prev_dp1, prev_dp2`，则
`dp1 = prev_dp2`
`dp2 = (k - 1) * (prev_dp1 + prev_dp2)`

### 代码

```cpp
class Solution {
public:
    int numWays(int n, int k) {
        if (k * n == 0) {
            return 0;
        }
        if (n < 3) {
            return pow(k, n);
        }
        int dp1 = k;
        int dp2 = k * (k - 1);
        for (int i = 3; i <= n; ++i) {
            int dp3 = (k - 1) * (dp1 + dp2);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp1 + dp2;
    }
};
```

![image.png](https://pic.leetcode-cn.com/af1027a2c49fc9039c5e84f614cca90db7ea82e37c5f428a6a6143af9e7d9989-image.png)
