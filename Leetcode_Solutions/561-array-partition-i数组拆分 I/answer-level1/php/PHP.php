时间复杂度： O(n log n)
空间复杂度： O(log n)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function arrayPairSum($nums) {
        sort($nums);

        $num = 0;

        for ($i = 0, $count = count($nums); $i < $count; $i += 2) {
            $num += $nums[$i];
        }

        return $num;
    }
}
```