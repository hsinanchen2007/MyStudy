时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $hash = [];

        for ($i = 0, $count = count($nums), $num = $count / 2; $i < $count; $i++) {
            $hash[$nums[$i]] = ($hash[$nums[$i]] ?? 0) + 1;
            if ($hash[$nums[$i]] > $num) {
                return $nums[$i];
            }
        }
    }
}
```