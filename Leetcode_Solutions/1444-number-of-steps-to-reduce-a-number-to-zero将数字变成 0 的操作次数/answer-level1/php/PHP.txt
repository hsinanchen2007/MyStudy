时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function numberOfSteps ($num) {
        $count = 0;

        while ($num) {
            $num = $num & 1 ? --$num : $num / 2;
            $count++;
        }

        return $count;
    }
}
```