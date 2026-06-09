```
class Solution {

    private $data = [];
    
    /**
     * @param Integer $n
     * @return String[]
     */
    function generateParenthesis($n) {
        
        if($n == 0)
            return $this->data;
        
        self::dfs('', $n, $n);
        
        return $this->data;
    }
    
    
    function dfs($str, $left, $right)
    {
        // 因为是递归函数，所以先写递归终止条件
        if ($left == 0 && $right == 0) {
            $this->data[] = $str;
            return $this->data;
        }
        
        if ($left > 0) {
            self::dfs($str . "(", $left - 1, $right);
        }

        if ($right > 0 && $left < $right) {
            self::dfs($str . ")", $left, $right - 1);
        }

    }
}
```

解法可以参考：https://leetcode-cn.com/problems/generate-parentheses/solution/hui-su-suan-fa-by-liweiwei1419/
