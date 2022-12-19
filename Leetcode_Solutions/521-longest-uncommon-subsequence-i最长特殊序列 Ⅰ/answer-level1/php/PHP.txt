时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $a
     * @param String $b
     * @return Integer
     */
    function findLUSlength($a, $b) {
        if ($a == $b) {
            return -1;
        }

        $A = strlen($a);
        $B = strlen($b);

        return $A > $B ? $A : $B;
    }
}
```