### 解题思路
动态规划
状态：定义dp[i][j]表示到达[i, j]位置的路径总和。
状态转移方程：dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
初始化(第一行和第一列只有一条路可走)：dp[i][0] = 1; dp[0][j] = 1;

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了91.43%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了73.17%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $m
     * @param Integer $n
     * @return Integer
     */
    function uniquePaths($m, $n) {
        $dp = [];
        for ($i = 0; $i < $m; $i++) $dp[$i][0] = 1;
        for ($j = 0; $j < $n; $j++) $dp[0][$j] = 1; 

        for ($i = 1; $i < $m; $i++) {
            for ($j = 1; $j < $n; $j++) {
                $dp[$i][$j] = $dp[$i - 1][$j] + $dp[$i][$j - 1];
            }
        }

        return $dp[$m - 1][$n - 1];
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(N ^ 2)

### 参考
[https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/](https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/)