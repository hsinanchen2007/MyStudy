时间复杂度： O(n log n)
空间复杂度： O(log n)

```php
class Solution {

    /**
     * @param Integer[] $heights
     * @return Integer
     */
    function heightChecker($heights) {
        $tmp = $heights;

        sort($tmp);

        $num = 0;

        for ($i = 0, $count = count($tmp); $i < $count; $i++) {
            if ($tmp[$i] != $heights[$i]) {
                $num++;
            }
        }

        return $num;
    }
}
```