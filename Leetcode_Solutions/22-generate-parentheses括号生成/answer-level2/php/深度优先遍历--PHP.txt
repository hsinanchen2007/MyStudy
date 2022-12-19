### 解题思路
容易想到的思路就是枚举所以情况，然后验证是否符合规则。效率太低。

这里使用递归

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了97.30%的用户
内存消耗 :15.4 MB, 在所有 PHP 提交中击败了76.53%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return String[]
     */
    function generateParenthesis($n) {
        $res = [];
        $this->dfs('', $n, $n, $res);

        return $res;
    }

    /**
     * @param string $str 中间字符串
     * @param int $left 可以使用的左括号数量
     * @param int $right 可以使用的右括号数量
     * @param array $res 结果集
     * @return 
     */
    public function dfs($str, $left, $right, &$res)
    {
        if ($left == 0 && $right == 0) {
            $res[] = $str;
            return $res;
        }

        if ($left > $right) {
            return;
        }

        if ($left > 0) {
            $this->dfs($str . '(', $left - 1, $right, $res);
        }

        if ($right > 0) {
            $this->dfs($str . ')', $left, $right - 1, $res);
        }
    }
}
```

### 参考
[https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/](https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/)