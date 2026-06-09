时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParityII($A) {
        $tmp = [];

        for ($i = 0, $odd = 1, $even = 0, $count = count($A); $i < $count; $i++) {
            if ($A[$i] & 1) {
                $tmp[$odd] = $A[$i];
                $odd += 2;
            } else {
                $tmp[$even] = $A[$i];
                $even += 2;
            }
        }

        $A = [];

        for ($i = 0, $count = count($tmp); $i < $count; $i++) {
            $A[] = $tmp[$i];
        }

        return $A;
    }
}
```