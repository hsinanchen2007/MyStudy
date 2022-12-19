### 解题思路
动态规划

算法
- 状态: dp[i][j]表示以第i行第j列为右下角所有构成正方形的最大边长。
- 状态转移方程:
当前区域，上方，左方，前方最小值，加上当前区域( + 1)
```
dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
```
- 初始化
第一行和第一列只能是自身
dp[0][j] = matrix[0][j]
dp[i][0] = matrixp[i][0]


### 代码

```php
class Solution {

    /**
     * @param String[][] $matrix
     * @return Integer
     */
    function maximalSquare($matrix) {
        if (empty($matrix)) return 0;

        $dp = [];
        $row = count($matrix);
        $col = count($matrix[0]);
        $max = 0;
        for ($i = 1; $i <= $row; $i++) {
            for ($j = 1; $j <= $col; $j++) {
                // 初始化，注意不是$dp[$i][$j] = $matrix[$i][$j]
                if ($i == 1 || $j == 1) $dp[$i][$j] = $matrix[$i - 1][$j - 1];

                if ($matrix[$i - 1][$j - 1] == '1') {
                    $dp[$i][$j] = min($dp[$i - 1][$j], $dp[$i][$j - 1], $dp[$i - 1][$j - 1]) + 1;
                    $max = max($max, $dp[$i][$j]);
                }
            }
        }

        return $max * $max;
    }
}
```

### 性能
执行用时 :104 ms, 在所有 PHP 提交中击败了11.76%的用户
内存消耗 :25.5 MB, 在所有 PHP 提交中击败了81.25%的用户

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/maximal-square/comments/10296](https://leetcode-cn.com/problems/maximal-square/comments/10296)
[https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode/](https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode/)
