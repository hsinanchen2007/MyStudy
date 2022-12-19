### 解题思路
尾数为0 长度直接减1(右移一位)
尾数为1 模拟加1时考虑进位

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function numSteps($s) {
        $len = strlen($s) - 1;
        $count = 0;
        $k = $len;
        while ($len > 0) {
            if ($s[$len] == 0) {
                $len--;
            } else {
                $s[$k] = 0;
                if ($s[$k - 1] == 0) {
                    $s[$k - 1] = 1;
                } else {
                    while ($s[$k - 1] == 1) {
                        $s[$k - 1] = 0;
                        $k--;
                    }
                    if ($k == 0) {
                        $s = 1 . $s;
                        $len++;
                    } else {
                        $s[$k - 1] = 1;
                    }
                }
            }
            $k = $len;
            $count++;
        }
        return $count;
    }
}
```