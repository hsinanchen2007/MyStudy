### 解题思路
本题是常见的DFS求解，寻找二维数组中符合题目给定字符串的数组路径，思路是遍历数组，然后将符合条件的对象放到栈中
注意需要将当前条件下的board也一并保存，当找到了长度大于等于所需字符串长度时，便返回true即可

### 代码

```php
class Solution {

    /**
     * @param String[][] $board
     * @param String $word
     * @return Boolean
     */
    function exist($board, $word) {
        $rows = count($board);
        $cols = count($board[0]);
        $firstStr = $word[0];
        $strLength = strlen($word);

        for ($i = 0; $i <= $rows -1; $i++) {
            for ($j = 0; $j <= $cols - 1; $j++) {
                if ($firstStr !== $board[$i][$j]) continue;

                $stack = [];
                array_push($stack , [$i, $j, 0, $board]);
                while ($stack) {
                    list($row, $col, $wordIndex, $copyBoard) = array_pop($stack);
                    $copyBoard[$row][$col] = 0;
                    $wordIndex++;
                    if ($wordIndex >= $strLength) return true;

                    foreach([[$row - 1, $col], [$row + 1, $col], [$row, $col - 1], [$row, $col + 1]] as list($nextRow, $nextCol)) {
                        if (
                            $nextRow >= 0
                            && $nextCol >= 0
                            && $nextRow < $rows
                            && $nextCol < $cols
                            && $copyBoard[$nextRow][$nextCol] !== 0
                            && $copyBoard[$nextRow][$nextCol] === $word[$wordIndex]
                        ) {
                            array_push($stack, [$nextRow, $nextCol, $wordIndex, $copyBoard]);
                        }
                    }

                }
            }
        }

        return false;
    }
}
```