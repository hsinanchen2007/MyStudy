时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $num
     * @return Boolean
     */
    function isPowerOfFour($num) {
        return $num > 0 && ($num & ($num - 1)) == 0 && $num % 3 == 1;
    }
}
```