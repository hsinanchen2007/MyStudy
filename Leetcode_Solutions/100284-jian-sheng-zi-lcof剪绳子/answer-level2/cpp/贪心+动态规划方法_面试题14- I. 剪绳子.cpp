### 解题思路一 贪心算法
该方法偏向于数学题法，需要多组计算后进行规律总结。个人觉得该博主讲的最好，非常容易理解：[整数拆分](https://leetcode-cn.com/problems/integer-break/solution/343-zheng-shu-chai-fen-tan-xin-by-jyd/)。思路的核心是发现必须以3为除数，即乘积必须以3为底数，得到乘积公式：x^a*b，下面讨论余数即可：
- 当余数为0：正好为3的倍数，返回3^a
- 当余数为1：由于1乘积后无作用，需要拿出一个3，将3+1转换为4，此时返回3^(a-1)*4
- 当余数为2：直接返回3^a*2
### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
        // 当n小于4时返回n-1
        if (n <= 3) {
            return n - 1;
        }

        // 计算整数部分和余数部分
        int a = n / 3, b = n % 3;

        // 如果余数为0，则正好为3的整数倍
        if (b == 0) {
            return pow(3, a);
        }

        // 如果余数为1，则3+1可以合并为4
        if (b == 1) {
            return pow(3, a - 1) * 4;
        }

        // 如果余数为2，则直接计算
        return pow(3, a) * 2;
    }
};
```

### 解题思路二 动态规划算法
这道题动态规划的理解是，我们要知道某个数，比如5拆分为哪几个整数的和，并且整数的乘积最大，那么我们只要知道4,3,2拆分后的乘积，并从中选出最大值即可，以此类推。这样使用递归方法：`dp=max(dp,i*(n-i),i*cuttingRope(n-i))`可解决。而动态规划方法里面常使用的记忆数组可以简化递归，将每次比较的最优结果存储在记忆数组中，参与下一轮的比较，最终得到全局最优的结果。
### 代码
```cpp
int cuttingRope2(int n) {
    // 当n小于4时返回n-1
    if (n <= 3) {
        return n - 1;
    }

    // 记忆数组
    // 存储上一轮的最优结果
    std::vector<int> dp(n + 1, 0);
    //初始化为1
    dp[1]=1;

    int i, j;
    for (i = 4; i <= n; i++) {
        // i为界限减少重复计算，
        // 因为 j*(i-j) == (i-j)*j
        for (j = 1; j < i; j++) {
            // dp[i]为上一轮最优结果
            // 里面实际上是比较: dp[i-j]*j 和 (i-j)*j 的大小
            // 即比较 dp[i-j] 和 i-j 的大小
            dp[i] = std::max(dp[i], std::max(dp[i-j],i-j)*j);
        }
    }

    return dp[n];
}
```
