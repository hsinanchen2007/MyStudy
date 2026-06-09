### 解题思路
递归

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了61.29%的用户
内存消耗 :16.2 MB, 在所有 PHP 提交中击败了90.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String[]
     */
    function letterCasePermutation($S) {
        $res = [];
        $this->dfs($S, strlen($S), 0, '', $res);

        return $res;
    }

    /**
     * @param String $S
     * @param int $len 字符串长度
     * @param int $start 开始下标
     * @param String $temp 中间结果字符串
     * @param array $res 结果

     * @return boolean
     */
    public function dfs($S, $len, $start, $temp, &$res)
    {
        if ($start >= $len || strlen($temp) == $len) {
            $res[] = $temp;
            return;
        }
        if (is_numeric($S[$start])) {
            $this->dfs($S, $len, $start + 1, $temp . $S[$start], $res);
        } elseif ($S[$start] == strtolower($S[$start])) {
            $this->dfs($S, $len, $start + 1, $temp . $S[$start], $res);
            $this->dfs($S, $len, $start + 1, $temp . strtoupper($S[$start]), $res);
        } else {
            $this->dfs($S, $len, $start + 1, $temp . $S[$start], $res);
            $this->dfs($S, $len, $start + 1, $temp . strtolower($S[$start]), $res);
        }
    }
}
```

### 算法复杂度
- 时间复杂度：
- 空间复杂度:

### 参考
[https://leetcode-cn.com/problems/letter-case-permutation/comments/51169](https://leetcode-cn.com/problems/letter-case-permutation/comments/51169)