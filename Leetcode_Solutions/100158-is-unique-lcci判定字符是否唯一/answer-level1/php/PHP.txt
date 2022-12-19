时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $astr
     * @return Boolean
     */
    function isUnique($astr) {
        $hash = [];

        for ($i = 0, $length = strlen($astr); $i < $length; $i++) {
            if (isset($hash[$astr[$i]])) {
                return false;
            }
            $hash[$astr[$i]] = '';
        }

        return true;
    }
}
```