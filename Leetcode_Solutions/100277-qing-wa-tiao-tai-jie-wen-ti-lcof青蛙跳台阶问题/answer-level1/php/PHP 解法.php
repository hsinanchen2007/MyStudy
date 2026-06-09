### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function numWays($n) {
        if ($n <= 0) return 1;
        if ($n <= 2) return $n;
        $pre = 1;
        $cur = $res = 2;
        for ($i = 3; $i <= $n; ++$i) {
            $res = ($pre + $cur) % 1000000007;
            $pre = $cur;
            $cur = $res;
        }

        return $res;
    }
}
```