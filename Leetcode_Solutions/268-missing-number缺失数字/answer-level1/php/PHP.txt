时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        for ($i = 0, $count = count($nums), $num = $count; $i < $count; $i++) {
            $num ^= $i ^ $nums[$i];
        }

        return $num;
    }
}
```