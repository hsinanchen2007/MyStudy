### 解题思路
转成二进制遍历

### 性能
执行用时 :0 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了80.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function hasAlternatingBits($n) {
        $bin = decbin($n);
        for ($i = 0; $i < strlen($bin) - 1; $i++) {
            if ($bin[$i] == $bin[$i + 1]) return false;
        }

        return true;
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度: O(1)

### 参考