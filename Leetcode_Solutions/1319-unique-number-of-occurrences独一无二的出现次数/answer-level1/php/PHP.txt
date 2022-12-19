时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @return Boolean
     */
    function uniqueOccurrences($arr) {
        $hash = [];

        foreach ($arr as $value) {
            $hash[$value] = ($hash[$value] ?? 0) + 1;
        }

        $count = [];

        foreach ($hash as $value) {
            if (isset($count[$value])) {
                return false;
            }
            $count[$value] = '';
        }

        return true;
    }
}
```