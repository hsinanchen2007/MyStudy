### 解题思路

直接上代码

### 代码

```php
class Solution {
    protected $result = [];
    /**
     * @param Integer $n
     * @return String[][]
     */
    function solveNQueens($n) {
        if ($n <= 0) return [];
        $board = array_fill(0, $n, array_fill(0, $n, '.'));
        $this->helper($n, $board, 0);
        return $this->result;
    }

    private function helper($n, $board, $row)
    {
        if ($row == $n) {
            $tmp = [];
            foreach($board as $item) $tmp[] = implode('', $item);
            $this->result[] = $tmp;
            return;
        }

        // 当前行 遍历每一列
        for ($col = 0; $col < $n; ++$col) {
            if (!$this->valid($n, $board, $row, $col)) continue;
            $board[$row][$col] = 'Q';
            $this->helper($n, $board, $row + 1);
            $board[$row][$col] = '.';
        }
    }

    private function valid($n, $board, $row, $col)
    {
        // 同一行，无需考虑
        // 左下和右下，遍历到这里时还是空的，无需考虑
        // 同一列
        for ($i = 0; $i < $n; ++$i) {
            if ($board[$i][$col] == 'Q') return false;
        }

        // 左上
        $i = $row - 1;
        $j = $col - 1;
        for (; $i >= 0 && $j >= 0; --$i, --$j) {
            if ($board[$i][$j] == 'Q') return false;
        }

        // 右上
        $i = $row - 1;
        $j = $col + 1;
        for (; $i >=0 && $j < $n; --$i, ++$j) {
            if ($board[$i][$j] == 'Q') return false;
        }

        return true;
    }
}
```