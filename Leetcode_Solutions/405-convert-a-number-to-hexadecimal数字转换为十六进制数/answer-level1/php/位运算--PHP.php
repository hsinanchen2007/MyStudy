### 解题思路
使用位运算，把数字看成二进制字符串，二进制每4位对于一位16进制字符串，不断移动4位，转成16进制字符进行拼接。

算法：
1. 定义16进制字符序列。
2. 取出数字对应二进制字符的最后4位，$num & 15【15的二进制字符串是'1111', 所以按位与的结果就是取后4位】，并获取对应16进制的字符$hex[$num & 15]。
3. 然后把num右移4位，获取下一个字符，拼接在上一个字符前。$res = $hex[$num & 15] . $res;【>>算数位移，其中正数右移左边补0，负数右移左边补1。】
4. 直到num为0, 或者$res的长度 >= 8。位移运算并不能保证num==0，需要使用32位int保证（对应16进制小于等于8位）

### 性能
执行用时 :0 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return String
     */
    function toHex($num) {
        if ($num == 0) {
            return '0';
        }

        $hex = '0123456789abcdef';
        $res = '';
        while ($num != 0 && strlen($res) < 8) {
            $res = $hex[$num & 15] . $res;
            $num >>= 4;
        }

        return $res;
    }
}
```

### 参考
[bin2hex](https://www.php.net/manual/zh/function.bin2hex.php)
[@不瘦十斤不改名的评论](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/comments/8916)