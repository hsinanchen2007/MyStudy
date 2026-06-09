### 解题思路

算法：
1. 通过右移1位来遍历二进制数位数。
2. 遍历的同时，定义一个二进制数$res，每位赋值1。
3. 按位异或，$res ^ $num就有取反的效果。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了53.85%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function findComplement($num) {
        $tmp = $num;
        $res = 0;
        while ($tmp != 0) {
            $res = ($res << 1) + 1;
            $tmp >>= 1;
        }

        return $num ^ $res;
    }
}
```