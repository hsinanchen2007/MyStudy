时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $chips
     * @return Integer
     */
    function minCostToMoveChips($chips) {
        $odd = 0;
        $even = 0;

        foreach ($chips as $value) {
            $value & 1 ? $odd++ : $even++;
        }

        return $odd < $even ? $odd : $even;
    }
}
```