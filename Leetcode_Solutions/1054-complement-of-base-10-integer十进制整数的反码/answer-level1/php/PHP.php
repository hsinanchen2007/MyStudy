时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function bitwiseComplement($N) {
        if ($N == 0) {
            return 1;
        }

        $num = 0;
        $i = 0;

        while ($N) {
            $num += (($N & 1 ^ 1) * (2 ** $i));
            $N >>= 1;
            $i++;
        }

        return $num;
    }
}
```