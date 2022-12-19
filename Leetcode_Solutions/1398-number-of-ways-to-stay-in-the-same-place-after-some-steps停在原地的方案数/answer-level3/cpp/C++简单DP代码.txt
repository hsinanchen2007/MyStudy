
![捕获.PNG](https://pic.leetcode-cn.com/e4f4989f5ae1a47579e630951fd08107b9ea61de0c145300097d62de102ad533-%E6%8D%95%E8%8E%B7.PNG)

### 代码如下

```c++
class Solution {
public:
    int numWays(int steps, int arrLen) {
        long dp[502] = {1}, tmp;
        int gap = 1000000007, i, s;
        for(s = 1; s <= steps; s++)
            for(tmp = 0, i = 0; i < min(min(arrLen, s + 1), steps - s + 1); i++) {
                    swap(dp[i], tmp);
                    dp[i] = (tmp + dp[i] + dp[i + 1]) % gap;
            }
        return dp[0];
    }
};
```

### 思路

维护一个一维数组 $dp[i]$
记 $dp[i]$ 为走 $s$ 步后，走到数组 $i$ 位置的方法数，题目即求走 $steps$ 步后 $dp[0]$ 的大小
每一步只能走左右一步或者不动，那么 $s - 1$ 步走到 $i - 1, i, i + 1$ 位置的方法数之和，即为 $s$ 步走到 $i$ 位置的方法数，状态转移方程

$$dp[i] = dp[i - 1] + dp[i] + dp[i + 1]$$

初始态为 $dp[0] = 1$，其他均为$0$

但是，循环赋值的时候 $dp[i]$ 会被改变，那么就申请额外变量 $tmp$，记录之前 $dp[i]$ 的值

再加上循环的剪枝，不必要维护整一个数组，只需要维护固定长度的数组就行

### 时间复杂度

根据循环，就可得出时间复杂度为 $O(steps * min(steps, arrLen))$

