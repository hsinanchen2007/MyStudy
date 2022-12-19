### 解题思路
如果两个字符串内容相等，那么他们独有的最长子序列不存在，返回-1
如果两个字符串长度不一样，则较长的字符串本身不可能是短字符串的子序列，直接返回其长度即可

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了81.82%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了50.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $a
     * @param String $b
     * @return Integer
     */
    function findLUSlength($a, $b) {
        if ($a == $b) return -1;

        return strlen($a) > strlen($b) ? strlen($a) : strlen($b);
    }
}
```

### 参考
[七夕算法](https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/solution/qi-xi-suan-fa-521-zui-chang-te-shu-xu-lie-i-by-gua/)