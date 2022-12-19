时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String[] $A
     * @return Integer
     */
    function minDeletionSize($A) {
        $num = 0;

        for ($i = 0, $length = strlen($A[0]); $i < $length; $i++) {
            for ($j = 0, $count = count($A) - 1; $j < $count; $j++) {
                if (isset($A[$j + 1][$i]) && $A[$j][$i] > $A[$j + 1][$i]) {
                    $num++;
                    break;
                }
            }
        }

        return $num;
    }
}
```