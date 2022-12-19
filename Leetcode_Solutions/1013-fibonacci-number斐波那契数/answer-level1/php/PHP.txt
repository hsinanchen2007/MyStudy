时间复杂度： O(2^n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function fib($N) {
        if ($N <= 1) {
            return $N;
        }

        return $this->fib($N - 1) + $this->fib($N - 2);
    }
}
```