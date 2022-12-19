时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function firstUniqChar($s) {
        $hash = [];

        for ($i = 0, $length = strlen($s); $i < $length; $i++) {
            $hash[$s[$i]] = ($hash[$s[$i]] ?? 0) + 1;
        }

        foreach ($hash as $key => $value) {
            if ($value == 1) {
                return $key;
            }
        }

        return ' ';
    }
}
```