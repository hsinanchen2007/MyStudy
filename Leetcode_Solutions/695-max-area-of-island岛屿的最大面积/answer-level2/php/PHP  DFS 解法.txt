参考了点赞较多的题解，根本上还是沉岛法。

```php
class Solution {
    protected $grid = [];
    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxAreaOfIsland($grid)
    {
        $row = count($grid);
        if ($row == 0) return 0;
        $col = count(reset($grid));
        $res = 0;
        $this->grid = $grid;
        for ($i = 0; $i < $row; ++$i) {
            for ($j = 0; $j < $col; ++$j) {
                $res = max($res, $this->dfs($i, $j, $row, $col));
            }
        }
        return $res;
    }

    private function dfs($i, $j, $row, $col)
    {
        if ($i < 0 || $i >= $row || $j < 0 || $j >= $col) return 0;
        if ($this->grid[$i][$j] == 0) return 0;
        $this->grid[$i][$j] = 0;
        $res = 1;
        $res += $this->dfs($i - 1, $j, $row, $col);
        $res += $this->dfs($i, $j - 1, $row, $col);
        $res += $this->dfs($i + 1, $j, $row, $col);
        $res += $this->dfs($i, $j + 1, $row, $col);
        return $res;
    }
}
```