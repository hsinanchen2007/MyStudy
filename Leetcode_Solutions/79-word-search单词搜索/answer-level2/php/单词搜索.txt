```php
class Solution {

    /**
     * @param String[][] $board
     * @param String $word
     * @return Boolean
     */
    function exist($board, $word)
    {
        $rows = count($board);
        $cols = count($board[0]);
        if ($rows == 0) {
            return false;
        }

        $len = strlen($word);


        for ($i = 0; $i < $rows; $i++) {
            for ($j = 0; $j < $cols; $j++) {
                if ($this->find($word, $board, $i, $j, 0, $len)) {
                    return true;
                }
            }
        }

        return false;
    }


    /**
     * @param $word
     * @param $board
     * @param $row
     * @param $col
     * @param $index
     * @param $len
     * @return bool
     */
    function find(&$word, &$board, $row, $col, $index, $len)
    {
        // 判断越界
        if ($row < 0 || $row >= count($board) || $col < 0 || $col >= count($board[0])) {
            return false;
        }

        // 当前位置不匹配 或者已访问(特殊字符表示已访问)
        if ($board[$row][$col] !== $word[$index]) {
            return false;
        }

        // 遍历到最后一个字符直接返回true
        if ($index == $len - 1) {
            return true;
        }

        // 标记当前位置已访问
        $temp = $board[$row][$col];
        $board[$row][$col] = '#';

        // right
        if ($this->find($word, $board, $row, $col + 1, $index + 1, $len)) {
            return true;
        }

        // left
        if ($this->find($word, $board, $row, $col - 1, $index + 1, $len)) {
            return true;
        }

        // up
        if ($this->find($word, $board, $row - 1, $col, $index + 1, $len)) {
            return true;
        }

        // down
        if ($this->find($word, $board, $row + 1, $col, $index + 1, $len)) {
            return true;
        }

        // 还原已访问标记
        $board[$row][$col] = $temp;

        return false;
    }

}
```