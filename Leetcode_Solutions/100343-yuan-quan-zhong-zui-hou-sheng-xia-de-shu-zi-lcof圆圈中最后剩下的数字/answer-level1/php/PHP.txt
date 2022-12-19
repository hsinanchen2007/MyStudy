时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $n
     * @param Integer $m
     * @return Integer
     */
    function lastRemaining($n, $m) {
        $num = 0;

        for ($i = 2; $i != $n + 1; $i++) {
            $num = ($m + $num) % $i;
        }

        return $num;
    }
}
```