时间复杂度： O(log n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function subtractProductAndSum($n) {
        $a = 1;
        $b = 0;

        while ($n) {
            $mod = $n % 10;
            $a *= $mod;
            $b += $mod;
            $n = (int) ($n / 10);
        }

        return $a - $b;
    }
}
```