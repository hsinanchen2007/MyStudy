时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function generateTheString($n) {
        $s = '';

        for ($i = 0; $i < $n; $i++) {
            $s .= 'a';
        }

        if (!($n & 1)) {
            $s[$n - 1] = 'b';
        }

        return $s;
    }
}
```