时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String[] $A
     * @return String[]
     */
    function commonChars($A) {
        $hash = [];

        foreach ($A as $key => $value) {
            $hash[$key] = [];
            for ($i = 0, $length = strlen($value); $i < $length; $i++) {
                $hash[$key][$value[$i]] = ($hash[$key][$value[$i]] ?? 0) + 1;
            }
        }

        $tmp = $hash[0];

        unset($hash[0]);

        foreach ($tmp as $key => &$value) {
            foreach ($hash as $v) {
                if (!isset($v[$key])) {
                    unset($tmp[$key]);
                    break;
                }
                $value <= $v[$key] ?: $value = $v[$key];
            }
            unset($value);
        }

        $array = [];

        foreach ($tmp as $key => $value) {
            for (; $value > 0; $value--) {
                $array[] = $key;
            }
        }

        return $array;
    }
}
```