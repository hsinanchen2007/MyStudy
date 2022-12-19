时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $S
     * @param Integer $length
     * @return String
     */
    function replaceSpaces($S, $length) {
        $s = '';

        for ($i = 0; $i < $length; $i++) {
            $s .= $S[$i] == ' ' ? '%20' : $S[$i];
        }

        return $s;
    }
}
```