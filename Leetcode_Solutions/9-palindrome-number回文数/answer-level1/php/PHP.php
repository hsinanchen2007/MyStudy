时间复杂度： O(log n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if ($x < 0 || $x % 10 == 0 && $x != 0) {
            return false;
        }

        $num = 0;

        while ($x > $num) {
            $num = $num * 10 + $x % 10;
            $x = (int) ($x / 10);
        }

        return $x == $num || $x == (int) ($num / 10);
    }
}
```