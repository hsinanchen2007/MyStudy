时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortedSquares($A) {
        $count = count($A);
        $r = 0;

        while ($r < $count && $A[$r] < 0) {
            $r++;
        }

        $l = $r - 1;
        $array = [];
        $i = 0;

        while ($r < $count && $l >= 0) {
            $tmp1 = $A[$l] ** 2;
            $tmp2 = $A[$r] ** 2;
            if ($tmp1 < $tmp2) {
                $array[$i] = $tmp1;
                $l--;
            } else {
                $array[$i] = $tmp2;
                $r++;
            }
            $i++;
        }

        while ($l >= 0) {
            $array[$i] = $A[$l] ** 2;
            $i++;
            $l--;
        }

        while ($r < $count) {
            $array[$i] = $A[$r] ** 2;
            $i++;
            $r++;
        }

        return $array;
    }
}
```