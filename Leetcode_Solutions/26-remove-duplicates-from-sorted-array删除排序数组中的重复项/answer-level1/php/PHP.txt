时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $count = count($nums);

        if ($count <= 1) {
            return $count;
        }

        $num = $nums[0];
        $length = 1;

        for ($i = 1; $i < $count; $i++) {
            if ($nums[$i] == $num) {
                unset($nums[$i]);
            } else {
                $num = $nums[$i];
                $length++;
            }
        }

        return $length;
    }
}
```