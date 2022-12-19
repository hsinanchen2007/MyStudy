时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        $hash = [];

        for ($i = 0, $count = count($nums); $i < $count; $i++) {
            if (isset($hash[$nums[$i]])) {
                return true;
            }
            $hash[$nums[$i]] = '';
        }

        return false;
    }
}
```