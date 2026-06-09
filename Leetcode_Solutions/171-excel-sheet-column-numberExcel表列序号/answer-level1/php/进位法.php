### 解题思路
这里是26进制，每遍历一位，把之前的总数乘以26就相当于左移一位，然后加上当前的数（当前的数需要把字母转换为数字）


### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function titleToNumber($s) {
        $total = 0;
        for ($i = 0; $i < strlen($s); $i++) {
            $num = ord($s[$i]) - ord('A') + 1;
            $total = $total * 26 + $num;
        }

        return $total;
    }
}
```

### 参考
https://leetcode-cn.com/problems/excel-sheet-column-number/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-4-3/