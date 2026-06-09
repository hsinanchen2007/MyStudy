时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $J
     * @param String $S
     * @return Integer
     */
    function numJewelsInStones($J, $S) {
        $hash = [];

        for ($i = 0, $length = strlen($J); $i < $length; $i++) {
            $hash[$J[$i]] = '';
        }

        $num = 0;

        for ($i = 0, $length = strlen($S); $i < $length; $i++) {
            if (isset($hash[$S[$i]])) {
                $num++;
            }
        }

        return $num;
    }
}
```