时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer[]
     */
    function sumZero($n) {
        if ($n == 1) {
            return [0];
        }

        $array = [];

        for ($i = (int) ($n / 2); $i > 0; $i--) {
            $array[] = $i;
            $array[] = -$i;
        }

        if ($n & 1) {
            $array[] = 0;
        }

        return $array;
    }
}
```