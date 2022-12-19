时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParity($A) {
        foreach ($A as $key => $value) {
            if ($value & 1) {
                $A[] = $value;
                unset($A[$key]);
            }
        }

        return $A;
    }
}
```