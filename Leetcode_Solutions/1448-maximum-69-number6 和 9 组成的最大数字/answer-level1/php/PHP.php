时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function maximum69Number ($num) {
        $tmp = $num;
        $index = -1;
        $count = 0;

        while ($tmp) {
            if ($tmp % 10 == 6) {
                $index = $count;
            }
            $tmp = (int) ($tmp / 10);
            $count++;
        }

        if ($index >= 0) {
            $num += (3 * (10 ** $index));
        }

        return $num;
    }
}
```