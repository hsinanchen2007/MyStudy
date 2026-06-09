### 解题思路

递归四件套
1. 递归终止条件，防止陷入死循环
2. 递归内部处理逻辑
3. 递归进下一层
4. 递归清除，比如清楚一些无用的变量，分情况是否需要

### 解法一

```php
class Solution {
    protected $result;
    
    function generateParenthesis($n)
    {
        $this->result = [];
        $this->generate(0, 0, $n, '');
        return $this->result;

    }

    /**
     * @comment 递归生成合法字符串
     * @author ZouZhipeng <zzpwestlife@gmail.com>
     * @date 2019/12/21
     * @time 22:07
     * @param $leftCount int 左括号数量
     * @param $rightCount int 右括号数量
     * @param $count int 括号对数量
     * @param $result array 结果集
     * @param $str string 当前处理的字符串
     * @return array
     */
    private function generate($leftCount, $rightCount, $count, $str)
    {
        // terminator 左右括号都与所需数量相等，递归结束
        if ($leftCount == $count && $rightCount == $count) {
            $this->result[] = $str;
            return;
        }

        // processor

        // drill down
        // 左括号数量仍不够，继续递归
        if ($leftCount < $count) {
            $this->generate($leftCount + 1, $rightCount, $count, $str . '(');
        }

        // 右括号数量小于左括号数量才能递归，此处做了剪枝，减少了递归数量
        if ($rightCount < $leftCount) {
            $this->generate($leftCount, $rightCount + 1, $count, $str . ')');
        }
        // clean
    }
}
```

### 解法二， 强行理解回溯

```php
class Solution {
    protected $result;
    /**
     * @param Integer $n
     * @return String[]
     */
    function generateParenthesis($n) {
        // 强行使用回溯法求解
        if ($n <= 0) return $this->result;
        $this->helper($n, '', 0, 0);
        return $this->result;
    }

    private function helper($n, $path, $leftCount, $rightCount)
    {
        if (strlen($path) == $n * 2) {
            $this->result[] = $path;
            return;
        }

        // 分治 & 剪枝
        if ($this->valid($n, $leftCount + 1, $rightCount)) {
            $tmp = $path;
            $path .= '(';
            $this->helper($n, $path, $leftCount + 1, $rightCount);
            // 回溯
            $path = $tmp;
        }

        if ($this->valid($n, $leftCount, $rightCount + 1)) {
            $tmp = $path;
            $path .= ')';
            $this->helper($n, $path, $leftCount, $rightCount + 1);
            // 回溯
            $path = $tmp;
        }
    }

    private function valid($n, $leftCount, $rightCount)
    {
        if ($leftCount > $n || $rightCount > $n) return false;
        if ($rightCount > $leftCount) return false;
        return true;
    }
}
```
