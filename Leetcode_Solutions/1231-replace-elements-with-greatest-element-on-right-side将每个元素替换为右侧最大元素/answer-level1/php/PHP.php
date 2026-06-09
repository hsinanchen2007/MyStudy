时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @return Integer[]
     */
    function replaceElements($arr) {
        $max = -1;

        for ($i = count($arr) - 1; $i >= 0; $i--) {
            $tmp = $arr[$i];
            $arr[$i] = $max;
            if ($tmp > $max) {
                $max = $tmp;
            }
        }

        return $arr;
    }
}
```