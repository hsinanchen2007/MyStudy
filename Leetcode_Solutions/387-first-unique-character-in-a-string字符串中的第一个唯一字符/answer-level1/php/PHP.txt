时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function firstUniqChar($s) {
        $hash = [];

        for ($i = 0, $length = strlen($s); $i < $length; $i++) {
            $hash[$s[$i]] = ($hash[$s[$i]] ?? 0) + 1;
        }

        for ($i = 0; $i < $length; $i++) {
            if ($hash[$s[$i]] == 1) {
                return $i;
            }
        }

        return -1;
    }
}
```