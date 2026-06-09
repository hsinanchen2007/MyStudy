时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $ransomNote
     * @param String $magazine
     * @return Boolean
     */
    function canConstruct($ransomNote, $magazine) {
        $hash = [];

        for ($i = 0, $length = strlen($magazine); $i < $length; $i++) {
            $hash[$magazine[$i]] = ($hash[$magazine[$i]] ?? 0) + 1;
        }

        for ($i = 0, $length = strlen($ransomNote); $i < $length; $i++) {
            if (!isset($hash[$ransomNote[$i]]) || --$hash[$ransomNote[$i]] < 0) {
                return false;
            }
        }

        return true;
    }
}
```