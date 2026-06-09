### 解题思路

想多了，本想用贪心去解，结果特殊情况无穷无尽。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return String
     */
    function largestTimeFromDigits($A) {
        sort($A);
        $return = '';
        // 暴力解法
        for ($i = 0; $i < 4; ++$i) {
            for ($j = 0; $j < 4; ++$j) {
                if ($j != $i) {
                    for ($k = 0; $k < 4; ++$k) {
                        if ($k != $i && $k != $j) {
                            // 四个数字下标之和为 6
                            $l = 6 - $i - $j - $k;
                            if ($A[$i] * 10 + $A[$j] <= 23 && $A[$k] * 10 + $A[$l] <= 59) {
                                $return = max($return, sprintf('%d%d:%d%d', $A[$i], $A[$j], $A[$k], $A[$l]));
                            }
                        }
                    }
                }
            }
        }

        return $return;
    }
}
```