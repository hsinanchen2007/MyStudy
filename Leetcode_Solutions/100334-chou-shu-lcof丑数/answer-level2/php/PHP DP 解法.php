直接上代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function nthUglyNumber($n) {
        // 三指针 dp
        $p2 = $p3 = $p5 = 0;
        $dp = array_fill(0, $n, null);
        $dp[0] = 1;
        for ($i = 1; $i < $n; ++$i) {
            $dp[$i] = min($dp[$p2] * 2, $dp[$p3] * 3, $dp[$p5] * 5);
            // 不可以使用 if else，会漏掉一些情况
            if ($dp[$i] == $dp[$p2] * 2) $p2++;
            if ($dp[$i] == $dp[$p3] * 3) $p3++;
            if ($dp[$i] == $dp[$p5] * 5) $p5++;
        }
        return $dp[$n - 1];
    }
}
```