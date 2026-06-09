时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function findComplement($num) {
        $tmp = $num;
        $int = 0;

        while ($tmp) {
            $int = ($int << 1) + 1;
            $tmp >>= 1;
        }

        return $int ^ $num;
    }
}
```