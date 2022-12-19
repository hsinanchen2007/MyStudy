时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $num = $nums[0];

        for ($i = 1, $count = count($nums); $i < $count; $i++) {
            $num ^= $nums[$i];
        }

        return $num;
    }
}
```