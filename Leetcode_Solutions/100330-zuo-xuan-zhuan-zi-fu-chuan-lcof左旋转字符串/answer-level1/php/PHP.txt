时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $n
     * @return String
     */
    function reverseLeftWords($s, $n) {
        $S = '';

        for ($i = $n, $length = strlen($s); $i < $length; $i++) {
            $S .= $s[$i];
        }

        for ($i = 0; $i < $n; $i++) {
            $S .= $s[$i];
        }

        return $S;
    }
}
```