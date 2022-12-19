### 解题思路

代码有点复杂，所有情况考虑一遍即可

### 代码

```php
class Solution {

    /**
     * @param Integer $A
     * @param Integer $B
     * @return String
     */
    function strWithout3a3b($A, $B) {
        // 贪心算法
        $str = '';
        while ($A > 0 || $B > 0) {
            if ($A > $B) {
                if ($A > 1) {
                    $str .= 'aa';
                    $A -= 2;
                } else {
                    $str .= 'a';
                    $A--;
                }
                if ($B > 0) {
                    $str .= 'b';
                    $B--;
                }
            } elseif ($A < $B) {
                if ($B > 1) {
                    $str .= 'bb';
                    $B -= 2;
                } else {
                    $str .= 'b';
                    $B--;
                }

                if ($A > 0) {
                    $str .= 'a';
                    $A--;
                }
            } else {
                $str .= 'ab';
                $A--;
                $B--;
            }
        }

        return $str;
    }
}
```