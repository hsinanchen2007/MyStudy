### 解题思路
思路很容易想到，计算字符成对出现的次数。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了27.27%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了50.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $map = [];
        $len = 0;
        for ($i = 0; $i < strlen($s); $i++) {
            if (in_array($s[$i], $map)) {
                $len += 2;
                unset($map[array_search($s[$i], $map)]);
            } else {
                $map[] = $s[$i];
            }
        }
        
        return count($map) > 0 ? $len + 1 : $len;
    }
}
```

### 参考
评论区的[JS实现](https://leetcode-cn.com/problems/longest-palindrome/comments/48925)，很巧妙