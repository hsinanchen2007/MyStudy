### 解题思路
动态规划

算法
- 状态： dp[i]表示第i个数字二进制中1的个数
- 状态转移方程
```
dp[i] = dp[i / 2] + i % 2
```
- 初始化
dp[0] = 0


### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer[]
     */
    function countBits($num) {
        $dp = [];

        $dp[0] = 0;
        for ($i = 1; $i <= $num; $i++) {
            $dp[$i] = $dp[intval($i / 2)] + intval($i % 2);
        }

        return $dp;
    }
}
```

### 性能
执行用时 :28 ms, 在所有 PHP 提交中击败了61.54%的用户
内存消耗 :22.9 MB, 在所有 PHP 提交中击败了60.61%的用户

### 参考
[https://leetcode-cn.com/problems/counting-bits/solution/shi-yong-dong-tai-gui-hua-by-waynetsecn/](https://leetcode-cn.com/problems/counting-bits/solution/shi-yong-dong-tai-gui-hua-by-waynetsecn/)