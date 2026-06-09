时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[][] $A
     * @return Integer[][]
     */
    function transpose($A) {
        $a = [];

        foreach ($A as $value) {
            foreach ($value as $k => $v) {
                $a[$k][] = $v;
            }
        }

        return $a;
    }
}
```