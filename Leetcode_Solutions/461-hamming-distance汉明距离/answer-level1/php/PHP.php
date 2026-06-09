时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $x
     * @param Integer $y
     * @return Integer
     */
    function hammingDistance($x, $y) {
        $n = $x ^ $y;
        $num = 0;

        while ($n) {
            if ($n & 1) {
                $num++;
            }
            $n >>= 1;
        }

        return $num;
    }
}
```