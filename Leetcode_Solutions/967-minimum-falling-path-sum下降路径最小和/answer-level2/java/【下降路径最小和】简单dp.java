### 题目描述
给定一个**方形**整数数组 A，我们想要得到通过 A 的下降路径的**最小**和。

下降路径可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列。

### 示例
```
输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：12
解释：
可能的下降路径有：
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
和最小的下降路径是 [1,4,7]，所以答案是 12。
```
##### 提示:
```
1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100
```
### 解题思路
矩阵中的动态规划基本上都比较容易入手。这道题也算是入门题，我们可以设`dp[i][j]`表示到`(i, j)`位置的最小和，通过题目描述和手动模拟我们很容易得出状态转移方程：
> $dp[i][j]=min(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+A[i][j]$

最后取`dp`最后一行的最小值即可

![image.png](https://pic.leetcode-cn.com/61feb37cb720ee274056c5408ebe3212d880ccfd11d59eb50bf69e944411955f-image.png)

对于这种需要考虑边界的情况，我习惯在原数组的基础上套一层"**壳**"，这样状态转移的时候就不用特判边界了。
![image.png](https://pic.leetcode-cn.com/b789f420bb3b768532045632118b3bbcfc483fee7e1aa3642ef8f6f727e33778-image.png)


### 代码

```java
class Solution {
    public int minFallingPathSum(int[][] A) {
        // 设dp[i][j]为到i, j位置的最小路径和
        int len = A.length;
        int[][] dp = new int[len + 1][len + 2];

        // 套壳处理
        for (int i = 0; i < len + 1; i++) {
            dp[i][0] = Integer.MAX_VALUE;
            dp[i][len + 1] = Integer.MAX_VALUE;
        }
        for (int j = 0; j < len + 2; j++) {
            dp[0][j] = 0;
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < len + 1; i++) {
            for (int j = 1; j < len + 1; j++) {
                dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + A[i - 1][j - 1];
            }
        }
        for (int i = 1; i < len + 1; i++) {
            ans = Math.min(ans, dp[len][i]);
        }
        return ans;
    }
}
```