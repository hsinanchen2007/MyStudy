时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $L
     * @param Integer $R
     * @return Integer
     */
    function countPrimeSetBits($L, $R) {
        $count = 0;

        for (; $L <= $R; $L++) {
            $tmp = $L;
            $num = 0;
            while ($tmp) {
                if ($tmp & 1) {
                    $num++;
                }
                $tmp >>= 1;
            }
            if ($num == 2 || $num == 3 || $num == 5 || $num == 7 || $num == 11 || $num == 13 || $num == 17 || $num == 19) {
                $count++;
            }
        }

        return $count;
    }
}
```