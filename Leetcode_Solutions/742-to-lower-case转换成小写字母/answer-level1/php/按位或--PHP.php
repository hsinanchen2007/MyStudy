### 解题思路
很容易想到的思路，遍历检查如果是大写字符，加32即可。位运算更高效

位运算大写变小写、小写变小写 : 字符 |= 32;

ASCII码表中大写的A是65，小写的a是97，它们的差是32
65 | 32 转为二进制（按8位来算）可以得到 0100 0001 | 0010 0000 = 0110 0001 = 97 = a

注意：PHP按位或不支持字符串，所以需要收到转为ASCII进行运算。

### 性能
执行用时 :0 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了5.36%的用户

### 代码

```php
class Solution {

    /**
     * @param String $str
     * @return String
     */
    function toLowerCase($str) {
        for ($i = 0; $i < strlen($str); $i++) {
            $str[$i] = chr(ord($str[$i]) | 32);
        }

        return $str;
    }
}
```

### 参考
[Alfeim的评论](https://leetcode-cn.com/problems/to-lower-case/comments/159427)