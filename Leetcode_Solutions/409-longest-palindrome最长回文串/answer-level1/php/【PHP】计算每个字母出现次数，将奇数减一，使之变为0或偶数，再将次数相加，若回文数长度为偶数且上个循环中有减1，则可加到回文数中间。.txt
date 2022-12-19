### 解题思路
计算每个字母出现次数，将奇数减一，使之变为0或偶数，再将次数相加，若回文数长度为偶数且上个循环中有减1，则可加到回文数中间。

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $arr = str_split($s);
        // 计算每个元素出现个数
        $value = array_count_values($arr);
        $length = 0;
        $reduct = 0;
        foreach ($value as $k => $item) {
            // 将单数减一，使之变0或变偶数
            if ($value[$k] % 2 !== 0) {
                $value[$k] -= 1;
                $reduct++;
            }
            // 相加
            $length += $value[$k];
        }
        // 若回文数长度为偶数，且上个循环中有减1，则可加到回文数中间
        if ($reduct > 0 && $length % 2 === 0) {
            $length += 1;
        }
        return $length;
    }
}
```
![image.png](https://pic.leetcode-cn.com/816c45c1becd9084316861f3dad7a932441a88086453264bd3d04b542c1731cb-image.png)
