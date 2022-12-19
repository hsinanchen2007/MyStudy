### 解题思路
把边界及和边界联通的O先变为*, 然后遍历二位数组，把剩余的O变成X, 然后把*变回O。

算法：
- 以一个点为基准，递归处理，当前点上下左右的点，如果符合要求就替换为*
- 处理上下边界
- 处理左右边界
- 遍历替换

### 性能
执行用时 :36 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :21.3 MB, 在所有 PHP 提交中击败了87.50%的用户

### 代码

```php
class Solution {

    /**
     * @param String[][] $board
     * @return NULL
     */
    function solve(&$board) {
        if (empty($board)) return;

        $row = count($board) - 1;
        $col = count($board[0]) - 1;

        // 递归替换第一行和最后一行边界
        for ($j = 0; $j <= $col; $j++) {
            $this->dfs($board, 0, $j, $row, $col);
            $this->dfs($board, $row, $j, $row, $col);
        }

        // 递归处理第一列和最后一列边界
        for ($i = 0; $i <= $row; $i++) {
            $this->dfs($board, $i, 0, $row, $col);
            $this->dfs($board, $i, $col, $row, $col);
        }

        // 遍历，把O变X, *变O
        for ($x = 0; $x <= $row; $x++) {
            for ($y = 0; $y <= $col; $y++) {
                if ($board[$x][$y] == 'O') $board[$x][$y] = 'X';
                if ($board[$x][$y] == '*') $board[$x][$y] = 'O';
            }
        }

        return;
    }

    // 深度优先遍历，把当前位置联通的O都变为*
    public function dfs(&$board, $i, $j, $row, $col)
    {
        if ($i < 0 || $i > $row || $j < 0 || $j > $col || $board[$i][$j] != 'O') return;

        $board[$i][$j] = '*';
        $this->dfs($board, $i - 1, $j, $row, $col);
        $this->dfs($board, $i + 1, $j, $row, $col);
        $this->dfs($board, $i, $j - 1, $row, $col);
        $this->dfs($board, $i, $j + 1, $row, $col);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(N)

### 参考
[https://www.jianshu.com/p/51a845dabaea](https://www.jianshu.com/p/51a845dabaea)
[https://leetcode-cn.com/problems/surrounded-regions/comments/8717](https://leetcode-cn.com/problems/surrounded-regions/comments/8717)