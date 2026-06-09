### 解题思路
动态规划

算法
- 状态：dp[i]表示组成i的完全平方数最小个数。
- 状态转移方程
[推导过程不太好理解，等通俗理解清楚了，在这里补充。]
```
dp[i] = min(dp[i], dp[i - j * j] + 1)
```
- 初始化
dp[0] = 0
dp[i] = i


### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function numSquares($n) {
        $dp = [];

        $dp[0] = 0;
        for ($i = 1; $i <= $n; $i++) {
            $dp[$i] = $i;
            for ($j = 1; $i - $j * $j >= 0; $j++) {
                $dp[$i] = min($dp[$i], $dp[$i - $j * $j] + 1);
            }
        }

        return $dp[$n];
    }
}
```

### 性能
执行用时 :1064 ms, 在所有 PHP 提交中击败了47.62%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了92.31%的用户

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/](https://leetcode-cn.com/problems/perfect-squares/solution/hua-jie-suan-fa-279-wan-quan-ping-fang-shu-by-guan/)