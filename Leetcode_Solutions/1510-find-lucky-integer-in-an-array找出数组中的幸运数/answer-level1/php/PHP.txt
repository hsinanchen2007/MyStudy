时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function findLucky($arr) {
        $hash = [];

        for ($i = 0, $count = count($arr); $i < $count; $i++) {
            $hash[$arr[$i]] = ($hash[$arr[$i]] ?? 0) + 1;
        }

        $max = null;

        foreach ($hash as $key => $value) {
            if ($key == $value) {
                isset($max) ? ($max > $value ?: $max = $value) : $max = $value;
            }
        }

        return $max ?? -1;
    }
}
```