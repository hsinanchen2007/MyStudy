# 该方法只能2ms，超过50%。
# 递归方程推导
假设dp[i][j]表示机器人能否到达第i行第j列的方块，那么dp[i][j]的值由三个因素决定：
1. 坐标各位数之和和k的大小关系
2. 该方块的上一个方块即dp[i - 1][j]的可达状态
3. 该方块的右面一个方块即dp[i][j - 1]的可达状态
如果不明白为什么只需要判断上一个方块和右面一个方块的小伙伴请查看官方解题。在上面的三个条件中第一个必须满足，而第二和第三只需满足一个即可（相邻的一个可达，第一个条件满足，那我一定可达），因此递归方程就是
dp[i][j] = ((i % 10 + i / 10) + (j % 10 + j / 10)) <= k && (dp[i - 1][j] || dp[i][j - 1])
# 初始化
分别假设m = 0 和 n = 0，即只有一行或一列的情况，此时只需判断第一个条件是否满足即可，经过这一步后计算dp直接从1，1开始即可，在计算dp的时候还可以直接维护一个变量记录所有为true的个数，这样就不用在计算完成以后再次统计dp里为true的个数。
# 参考代码
```
class Solution {
    public static int movingCount(int m, int n, int k) {
        int ct = 0;
        boolean[][] dp = new boolean[m][n];
        // assuming the m = 0, initialize the first row
        for (int i = 0; i < n; i++) {
            if (checker(0, i, k)) {
                dp[0][i] = true;
                ct++;
            } else
                break;
        }

        // assuming the n = 0, initialize the first column.
        for (int i = 0; i < m; i++) {
            if (checker(i, 0, k)) {
                dp[i][0] = true;
                ct++;
            } else
                break;
        }

        // compute dp
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (checker(i, j, k) && (dp[i - 1][j] || dp[i][j - 1])) {
                    dp[i][j] = true;
                    ct++;
                }
            }
        }
        // The two initializations calculate the position of 0, 0 once more,
        // so the result is subtracted by 1.
        return ct - 1;
    }

    private static boolean checker(int m, int n, int max) {
        return (m % 10 + m / 10) + (n % 10 + n / 10) <= max;
    }
}
```
另外附上一张当m = 20, n = 15, k = 9时使用excel计算的dp数组的值
![QQ截图20200408190640.jpg](https://pic.leetcode-cn.com/518ce1cc2bea2842bbef35da7cd7fe3e69decfb7b45b1b5605e393d0bceae90a-QQ%E6%88%AA%E5%9B%BE20200408190640.jpg)


