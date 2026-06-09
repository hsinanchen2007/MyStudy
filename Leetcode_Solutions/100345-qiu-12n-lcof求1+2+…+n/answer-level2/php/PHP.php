时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function sumNums($n) {
        $n > 0 && $n += $this->sumNums($n - 1);
        return $n;
    }
}
```