假设我们的数组只有两个及以下的数字，那么先手必赢。
如果我们在此基础上在数组末尾添加一个数字，那么会有什么结果呢？
这时候先手（A）有两种选择：
1. 第一种是选择新添加的数字，先手A在获得这个数字后，剩余的最优解就是获得前面`n-1`个数字中的后手最优解。相当于A先获得末尾数字，然后和后手（B）交换顺序进行前面n-1个数字的选择博弈。
2. 不选择新添加的数字，那么A先获得数组开头的数字`nums[i]`,然后剩余最优解就是剩余数字的后手最优解。
我们得出状态方程：
`dp[i, j] = max(sum[i, j-1] - dp[i, j-1] + nums[j], nums[i] + sum[i+1, j] - dp[i+1, j])`
我们用dp表示先手最优解，`sum[i, j] - dp[i, j]`表示后手的最优解。
```
class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        if(n <= 2) return true;
        
        int[][] dp = new int[n][n];
        int[][] cnt = new int[n][n];
         
        for(int i = 0; i < n; i ++){
            dp[i][i] = nums[i];
            cnt[i][i] = nums[i];
            for(int j = i + 1; j < n; j ++)
                cnt[i][j] = cnt[i][j - 1] + nums[j];
        }
        
        for(int i = 1; i < n; i ++){
            for(int row = 0; row < n - i; row ++){
                int col = row + i;
                dp[row][col] = Math.max(cnt[row][col - 1] - dp[row][col - 1] + nums[col],
                                       nums[row] + cnt[row + 1][col] - dp[row + 1][col]);
            }
        }
            
        return dp[0][n - 1] * 2 >= cnt[0][n - 1];
    }
}
```
