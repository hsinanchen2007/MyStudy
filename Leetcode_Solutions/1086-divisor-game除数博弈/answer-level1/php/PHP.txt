时间复杂度： O(1)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $N
     * @return Boolean
     */
    function divisorGame($N) {
        return !($N & 1);
    }
}
```