### 解题思路 动态规划
学习来自与大佬[【n个骰子的点数】：详解动态规划及其优化方式](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/)

    /*
     * 动态规划
     *
     * 动态规划解决问题的三个步骤：
     * 1. 表示状态；
     * 2. 状态转移方程；
     * 3. 边界处理
     *
     * 1. 表示状态
     * 一共投掷n枚骰子，要求当投掷完n枚骰子后，各个点数出现的次数。
     * 定义状态数组dp[i][j]，表示投掷完i枚骰子后，点数j出现的次数。
     * 该状态数组第一维表示投掷完了几枚骰子，第二维表示投掷完骰子后，可能出现的点数。
     *
     * 2. 状态转移方程
     * 第n枚骰子，投掷完可能的点数为1,2,3,4,5,6，因此投掷完n枚骰子后点数j出现的次数，
     * 由投掷完n-1枚骰子，再加上第n枚投掷完出现的点数确定：
     * dp[n][j] = dp[n-1][j-1] + dp[n-1][j-2] + dp[n-1][j-3] + dp[n-1][j-4] + dp[n-1][j-5] + dp[n-1][j-6]
     *
     * 3. 边界处理
     * 初始化初始状态的值，即投掷完1枚骰子后，他的可能点数为1,2,3,4,5,6，每个点数出现的次数为1：
     * dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = dp[1][6] = 1
     * */
### 代码

```cpp
std::vector<double> twoSum(int n) {
    if (n < 0) {
        return {};
    }

    // 定义状态数组
    std::vector<std::vector<int>> dp(12, std::vector<int>(67, 0));

    // 初始化第1枚骰子投掷完后每个点数出现的次数
    for (int i = 1; i <= 6; i++) {
        dp[1][i] = 1;
    }

    // 从第2枚骰子开始，计算n枚骰子投掷完后，
    // 每个点数出现的次数
    for (int i = 2; i <= n; i++) {
        // j = i是因为，j的次数肯定不会小于投掷的骰子的数目
        // 骰子的最小点数为1，所以每枚骰子最少1点
        for (int j = i; j <= 6 * i; j++) {
            // 相较于上一枚骰子
            for (int k = 1; k <= 6; k++) {
                if (j - k <= 0) {
                    break;
                }
                // 状态转移方程
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    // 计算n枚骰子的总点数
    int total = std::pow(6, n);
    std::vector<double> ans;

    // 计算n枚骰子投掷完后，点数和出现的概率
    for (int i = n; i <= 6 * n; i++) {
        ans.push_back(dp[n][i] * 1.0 / total);
    }

    return ans;
}
```

### 空间优化
    // 空间优化
    // 每个阶段的状态都只和它迁移阶段的状态有关，因此可以使用一维数组保存状态。
    // 用一维数组保存一个阶段的状态，在对下一阶段可能出现的点数j从大到小遍历，
    // 实现一个阶段到下一个阶段的状态转移。

### 代码
```cpp
std::vector<double> twoSum2(int n) {
    if (n < 0) {
        return {};
    }

    // 保存状态的一维数组
    std::vector<double> dp(n * 6 + 1, 0.0);
    // 对一维数组初始化
    for (int i = 1; i <= 6; i++) {
        dp[i] = 1.0 / 6.0;
    }

    // 从第2枚骰子开始计算点数和s出现的概率
    for (int i = 2; i <= n; i++) {
        for (int j = i * 6; j >= i; j--) {
            // 每次更新dp[j]的值为0
            dp[j] = 0;
            // k = j - 1，，并且k--
            // 实现j-1,j-2,...,j-6
            // 同时要保证j是要大于等于i的，所以
            // k = j - 1 >= i - 1
            for (int k = j - 1; k >= i - 1 && k >= j - 6; k--) {
                // 计算点数和出现的概率
                dp[j] += dp[k] * 1.0 / 6.0;
            }
        }
    }

    std::vector<double> ans(dp.begin() + n, dp.end());

    return ans;
}
```