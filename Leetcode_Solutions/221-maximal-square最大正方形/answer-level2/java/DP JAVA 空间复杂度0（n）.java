观察动态规划的递推式可以发现，每个位置的计算仅仅使用到了dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]) 也就是本行以及上一行的数据，再具体一些就是用到了本行的的前一个数据,以及上一行的数据
```
class Solution {
    public int maximalSquare(char[][] matrix) {
        /**
        dp[i][j]表示以matrix[i][j]为右下角所能构成的最大正方形边长, 则递推式为:
        dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        **/
        int m = matrix.length;
        if(m < 1) return 0;
        int n = matrix[0].length;
        int max = 0;
        int[]pre = new int[n+1];
        int[]cur = new int[n+1];
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(matrix[i-1][j-1] == '1') {
                    cur[j] = 1 + Math.min(pre[j-1], Math.min(pre[j], cur[j-1]));
                    max = Math.max(max, cur[j]);
                }
                pre[j - 1] = cur[j - 1];// 上一行的j-1位置用不到了，此时就可以替换为本行的结果，为下一行的运算做准备。
                cur[j - 1] = 0;// 本行用不到的结果置0，为下一行做准备。
            }
            pre[n] = cur[n];
            cur[n] = 0;
        }
        return max*max;
    }
}

```
近一步优化
```
class Solution {
    public int maximalSquare(char[][] matrix) {
        /**
        dp[i][j]表示以matrix[i][j]为右下角所能构成的最大正方形边长, 则递推式为:
        dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
        **/
        int m = matrix.length;
        if(m < 1) return 0;
        int n = matrix[0].length;
        int max = 0;
        int[]cur = new int[n+1];
        int pre = 0; //相当于上一行的前一列的元素。
        for(int i = 1; i <= m; ++i) {
            pre = 0;
            for(int j = 1; j <= n; ++j) {
                int tmp = cur[j]; // 上一行的运算结果；
                if(matrix[i-1][j-1] == '1') {
                    cur[j] = 1 + Math.min(pre, Math.min(cur[j], cur[j-1]));
                    max = Math.max(max, cur[j]);
                }else
                    cur[j] = 0;
                pre = tmp;
            }
        }
        return max*max;
    }
}
```