时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function hasAlternatingBits($n) {
        $tmp = $n ^ ($n >> 1);

        return ($tmp & ($tmp + 1)) == 0;
    }
}
```