时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function repeatedNTimes($A) {
        $hash = [];

        for ($i = 0, $count = count($A), $num = $count / 2; $i < $count; $i++) {
            $hash[$A[$i]] = ($hash[$A[$i]] ?? 0) + 1;
            if ($hash[$A[$i]] == $num) {
                return $A[$i];
            }
        }
    }
}
```