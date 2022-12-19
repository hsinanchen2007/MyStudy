时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function removeOuterParentheses($S) {
        $num = 0;
        $s = '';

        for ($i = 0, $length = strlen($S); $i < $length; $i++) {
            if ($S[$i] == '(' && ++$num > 1) {
                $s .= '(';
            }
            if ($S[$i] == ')' && --$num > 0) {
                $s .= ')';
            }
        }

        return $s;
    }
}
```