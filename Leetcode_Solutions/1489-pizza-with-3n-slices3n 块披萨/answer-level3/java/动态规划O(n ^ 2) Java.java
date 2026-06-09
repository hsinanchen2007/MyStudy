# 思路
# 思路
本题其实可以转化为不相邻的子数列最大和问题。为什么可以这么转化，其实我在比赛时也考虑了很久很久，简单阐述一下为什么这样做是可以的：
首先，含有相邻元素的肯定不可以，这点毋庸置疑。
其次，我们要从`n`块中拿出 `n / 3`块，那么披萨间的平均间隙就是**2**，那么我们的策略就是每次挑间隙**大于等于2**的披萨拿，这样剩下的我们已选定的披萨仍然不是相邻的。此时披萨总数变为了`n - 3`, 在这个子问题上我们仍旧可以挑间隙**大于等于2**的披萨拿，以此得到最优解。

# 代码
```java
class Solution {
    public int maxSizeSlices(int[] slices) {
        int n = slices.length;
        int[][] dp = new int[n][n / 3 + 1];
        int res = 0;
        for(int i = 0; i < n - 1; i++){ // 不包含最后一个披萨
            for(int j = 0 ; j < n / 3; j++){
                dp[i][j + 1] = Math.max(i > 0 ? dp[i - 1][j+ 1]: 0, i - 2 >= 0 ? dp[i - 2][j] + slices[i] : slices[i]);
            }
            res = Math.max(res, dp[i][n / 3]);
        }
    
        dp = new int[n][n / 3 + 1];
        for(int i = 1; i < n; i++){ // 不包含第一个披萨
            for(int j = 0 ; j < n / 3; j++){
                dp[i][j + 1] = Math.max(dp[i - 1][j+ 1], i - 2 >= 0 ? dp[i - 2][j] + slices[i] : slices[i]);
            }
            res = Math.max(res, dp[i][n / 3]);
        }
        return res;
    }
}
```