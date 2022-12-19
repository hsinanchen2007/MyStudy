### 解题思路
分析一下：

* 状态有：

    * 房子
    * 颜色

* dp数组含义：

    所以设一个二维dp数组dp\[i][j]，代表0~i号房子且第i号房子粉刷为j颜色的最小成本其中j取值为0，1，2(粉刷房子II是k个取值)

    所以也可以看做dp\[i][1,2,3]

* 状态转移方程：

    容易想到：

    $dp[i][j] = min\{dp[i - 1][r] | r\in[0,k]\&r\neq j\}$

    当然可以写的更加简单一点对于这一题，但是这个方程更有普遍性，对于它的变种题（粉刷房子II）也可以使用。

* base case:

    显而易见：$dp[0][j] = costs[0][j](j\in [0,k])$

### 代码

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        if(size == 0) return 0;  //trick
        vector<vector<int>> dp(size, vector<int>(3)) ;
        //边界
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        //方程
        for(int i = 1; i < size; i++) {
            //第二维只有三个，直接写出来即可，不用循环遍历
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return min(min(dp[size - 1][0], dp[size - 1][1]), dp[size - 1][2]);
    }
};
```