### 解题思路
动态规划

- 状态dp[i][j]表示word1的前i个字符，和word2的前j个字符替换最小操作数
- 状态转移方程：dp[i][j] = 1 + 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
- 初始化，word1为空，那么替换操作数j, 及dp[i][0] = i, 同理， dp[0][j] = j;

### 性能
执行用时 :56 ms, 在所有 PHP 提交中击败了48.00%的用户
内存消耗 :22.8 MB, 在所有 PHP 提交中击败了68.42%的用户

### 代码

```php
class Solution {

    /**
     * @param String $word1
     * @param String $word2
     * @return Integer
     */
    function minDistance($word1, $word2) {
        $m = strlen($word1);
        $n = strlen($word2);

        $dp = [];
        for ($i = 0; $i <= $m; $i++) $dp[$i][0] = $i;
        for ($j = 0; $j <= $n; $j++) $dp[0][$j] = $j;

        for ($i = 1; $i <= $m; $i++) {
            for ($j = 1; $j <= $n; $j++) {
                if ($word1[$i - 1] == $word2[$j - 1]) {
                    $dp[$i][$j] = $dp[$i - 1][$j - 1];
                } else {
                    $dp[$i][$j] = 1 + min($dp[$i - 1][$j - 1], min($dp[$i - 1][$j], $dp[$i][$j - 1]));
                }
            }
        }

        return $dp[$m][$n];
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/edit-distance/comments/65607](https://leetcode-cn.com/problems/edit-distance/comments/65607)