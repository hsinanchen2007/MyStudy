### 解题思路
如果一个字符串s是由子串cs组成，那么s一定包含在s + s组合的字符串去掉首位字符中。

### 性能
执行用时 :20 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :15.1 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function repeatedSubstringPattern($s) {
        return strpos(substr($s . $s, 1, -1), $s) !== false;
    }
}
```