### 解题思路
深度优先搜索

### 代码

```php
class Solution
{

    /**
     * @param String[][] $board
     * @param String $word
     * @return Boolean
     */

    function exist($board, $word)
    {
        $x_count = count($board[0]);
        $y_count = count($board);

        for ($i = 0; $i < $x_count; $i++) {
            for ($j = 0; $j < $y_count; $j++) {
                $flag = $this->dfs($j, $i, 0, $board, $word, []);
                // 注意，只有选对路径才会返回 true，因此 false 的结果最后才输出
                // 这里可以统计符合要求的路径数
                if($flag == true) {
                    return $flag;
                }
            }
        }

        return false;

    }

    function dfs($i, $j, $k, $board, $word, $selected)
    {

        // 超出边界 || 与预期不符 || 字母已经被选用
        if (!isset($board[$i][$j]) || $board[$i][$j] != $word[$k] || isset($selected[$i][$j]) && $selected[$i][$j] == true) {
            return false;
        }

        if ($board[$i][$j] == $word[$k]) {

            // 搜索到最后一个字母了 -> OK
            if ($k == strlen($word) -1) {
                return true;
            };

            // 记录选过的字母
            $selected[$i][$j] = true;

            // 向四个方向搜索
            return $this->dfs($i + 1, $j, $k + 1, $board, $word, $selected)
                || $this->dfs($i - 1, $j, $k + 1, $board, $word, $selected)
                || $this->dfs($i, $j + 1, $k + 1, $board, $word, $selected)
                || $this->dfs($i, $j - 1, $k + 1, $board, $word, $selected);
        }

    }
}
```