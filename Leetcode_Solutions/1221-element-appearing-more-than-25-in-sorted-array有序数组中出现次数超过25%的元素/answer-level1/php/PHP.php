时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function findSpecialInteger($arr) {
        $hash = [];

        for ($i = 0, $count = count($arr), $num = .25 * $count; $i < $count; $i++) {
            $hash[$arr[$i]] = ($hash[$arr[$i]] ?? 0) + 1;
            if ($hash[$arr[$i]] > $num) {
                return $arr[$i];
            }
        }
    }
}
```