时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    function reverseString(&$s) {
        for ($i = 0, $count = count($s), $j = $count - 1; $i < $j; $i++, $j--) {
            $tmp = $s[$i];
            $s[$i] = $s[$j];
            $s[$j] = $tmp;
        }

        return $s;
    }
}
```