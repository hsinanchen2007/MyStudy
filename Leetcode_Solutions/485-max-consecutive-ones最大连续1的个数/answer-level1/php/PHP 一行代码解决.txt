```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findMaxConsecutiveOnes($nums) {
        return strlen(max(explode('0', implode('', $nums))));
    }
}
```
