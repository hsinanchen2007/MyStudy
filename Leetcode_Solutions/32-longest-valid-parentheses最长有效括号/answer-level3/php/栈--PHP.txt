### 解题思路
使用栈，存储括号下标。很巧妙。以前难度是中等，现在是困难了。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了73.47%的用户
内存消耗 :15.6 MB, 在所有 PHP 提交中击败了71.43%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestValidParentheses($s) {
        $len = 0;
        if (empty($s)) return $len;

        $stack = [-1];
        for ($i = 0; $i < strlen($s); $i++) {
            if ($s[$i] == '(') {
                $stack[] = $i;
            } else {
                array_pop($stack);
                if (empty($stack)) {
                    $stack[] = $i;
                } else {
                    $len = max($len, $i - end($stack));
                }
            }
        }

        return $len;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/