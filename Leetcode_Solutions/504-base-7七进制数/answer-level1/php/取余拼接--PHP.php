### 解题思路
每次对7取余，对应7进制字符串的低位。

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了85.71%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
    function convertToBase7($num) {
        if ($num == 0) return '0';
         
        $tmp = abs($num);
        $res = '';

        // $tmp > 0 比 $tmp != 0 快yi
        while ($tmp > 0) {
            $res = ($tmp % 7) . $res;
            $tmp = intval($tmp / 7);
        }

        if ($num < 0) {
            $res = '-' . $res;
        }

        return $res;
    }
}
```