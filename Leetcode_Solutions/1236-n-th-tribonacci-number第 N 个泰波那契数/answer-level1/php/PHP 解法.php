### 解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function tribonacci($n) {
        $dp = [0, 1, 1];
        if ($n <= 2) {
            return $dp[$n];
        }    

        for ($i = 3; $i <= $n; ++$i) {
            $sum = array_sum($dp);
            $dp[0] = $dp[1];
            $dp[1] = $dp[2];
            $dp[2] = $sum;
        }

        return $dp[2];
    }
}
```