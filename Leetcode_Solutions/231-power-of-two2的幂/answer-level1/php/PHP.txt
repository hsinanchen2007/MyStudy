时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function isPowerOfTwo($n) {
        return $n > 0 && ($n & ($n - 1)) == 0;
    }
}
```