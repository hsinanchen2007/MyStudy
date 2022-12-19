### 解题思路
动态规划，从后往前遍历，可以减少判断。

- 状态：dp[i]表示从第i个字符到结尾的解码方法
- 状态转移方程：
当s[i] + s[i + 1] > 26
dp[i] = dp[i + 1]
当s[i] + s[i + 1] <= 26
dp[i] = dp[i + 1] + dp[i + 2]
- 初始化
dp[len] = 1, 表示多增加一位，方便计算。其他状态全部为0

注意：PHP的数组不会初始化为0，所以需要检查isset($dp[0])，不存在就是0。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了31.43%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了88.46%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function numDecodings($s) {
        $len = strlen($s);
        $dp = [];

        $dp[$len] = 1;
        if ($s[$len - 1] != 0) $dp[$len - 1] = 1;

        for ($i = $len - 2; $i >= 0; $i--) {
            if ($s[$i] == 0) continue;

            if ($s[$i] * 10 + $s[$i + 1] <= 26) {
                $dp[$i] = $dp[$i + 1] + $dp[$i + 2];
            } else {
                $dp[$i] = $dp[$i + 1];
            }
        }

        return !isset($dp[0]) ? 0 : $dp[0];
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/decode-ways/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-3/](https://leetcode-cn.com/problems/decode-ways/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-2-3/)