直接上代码

```php
class Solution
{
    protected $count = 0;
    /**
     * @param Integer $n
     * @return Integer
     */
    function totalNQueens($n)
    {
        if ($n <= 0) return $this->count;
        $board = array_fill(0, $n, array_fill(0, $n, 0));
        $this->helper($n, $board, 0);
        return $this->count;
    }

    private function helper($n, $board, $row)
    {
        if ($row == $n) {
            $this->count++;
            return;
        }

        // 在当前行遍历每一列
        for ($col = 0; $col < $n; ++$col) {
            if (!$this->valid($n, $board, $row, $col)) continue;
            $board[$row][$col] = 1;
            $this->helper($n, $board, $row + 1);
            $board[$row][$col] = 0;
        }
    }

    private function valid($n, $board, $row, $col)
    {
        // 同一列
        for ($i = 0; $i < $n; ++$i) {
            if ($board[$i][$col] == 1) return false;
        }

        $i = $row - 1;
        $j = $col - 1;
        for (; $i >= 0 && $j >= 0; --$i, --$j) {
            if ($board[$i][$j] == 1) return false;
        }

        $i = $row - 1;
        $j = $col + 1;
        for (; $i >= 0 && $j < $n; --$i, ++$j) {
            if ($board[$i][$j] == 1) return false;
        }

        return true;
    }
}
```