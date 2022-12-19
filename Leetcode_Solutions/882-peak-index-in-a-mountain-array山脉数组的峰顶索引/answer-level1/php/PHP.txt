时间复杂度： O(log n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function peakIndexInMountainArray($A) {
        $l = 0;
        $r = count($A) - 1;

        while ($l < $r) {
            $c = (int) (($l + $r) / 2);
            $A[$c] < $A[$c + 1] ? $l = $c + 1 : $r = $c;
        }

        return $l;
    }
}
```