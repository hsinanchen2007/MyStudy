### 解题思路
解题思路通130题

### 性能
执行用时 :60 ms, 在所有 PHP 提交中击败了31.82%的用户
内存消耗 :22.7 MB, 在所有 PHP 提交中击败了39.66%的用户

### 代码

```php
class Solution {

    /**
     * @param String[][] $grid
     * @return Integer
     */
    function numIslands($grid) {
        $count = 0;
        if(empty($grid)) return $count;

        $row = count($grid);
        $col = count($grid[0]);

        for ($i = 0; $i < $row; $i++) {
            for ($j = 0; $j < $col; $j++) {
                if ($grid[$i][$j] == 1) {
                    $this->dfs($grid, $i, $j, $row - 1, $col - 1);
                    $count++;
                }
            }
        }

        return $count;
    }

    // 深度优先遍历，把当前位置联通的1都变为*
    public function dfs(&$board, $i, $j, $row, $col)
    {
        if ($i < 0 || $i > $row || $j < 0 || $j > $col || $board[$i][$j] != '1') return;

        $board[$i][$j] = '*';
        $this->dfs($board, $i - 1, $j, $row, $col);
        $this->dfs($board, $i + 1, $j, $row, $col);
        $this->dfs($board, $i, $j - 1, $row, $col);
        $this->dfs($board, $i, $j + 1, $row, $col);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2) [不准确]
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/number-of-islands/comments/42148](https://leetcode-cn.com/problems/number-of-islands/comments/42148)