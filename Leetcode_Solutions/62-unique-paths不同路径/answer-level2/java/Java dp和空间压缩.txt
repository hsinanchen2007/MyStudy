##### 其实这个题目比较简单，简单的二维数组的动态规划，我就不写了，也有很多人写过，现在写一下空间压缩算法的使用和思路。
##### 本解法时间复杂度O(M * N)
##### 空间复杂度O(min(M, N))

<br/>
代码如下
```
    public static int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        int less = Math.min(m, n);
        int more = Math.max(m, n);

        int[] dp = new int[less]; // 空间压缩，就是利用了dp暂存了上一轮的值，在这一次的赋值中循环利用
        // 默认第一行或者第一列的值都是1，因为第一行的路径只能从左侧走过来
        Arrays.fill(dp, 1);

        for (int i = 1; i < more; i++) {
            for (int j = 1; j < less; j++) {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[less - 1];
    }

```
<br/>
手拙，画了张图
![image.png](https://pic.leetcode-cn.com/5d51d27a874b66581a862949569a0a871538b597c24801851b0331bdc2aabdf3-image.png)

解释：二维数组很好理解，就是拿(i - 1, j) + (i, j - 1)的和来fill（i, j），那么换成一维数组的时候我们应该从dp[j - 1]的位置来取之前二维数组的（i - 1, j）再加当前的dp[j]即可
即dp[j] = dp[j - 1] + dp[j];
