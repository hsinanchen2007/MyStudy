### 解题思路
题目有点绕，重点在于弄清题意；
首先找到车所在的行和列；然后根据所在的行和列匹配车所能捕获的卒数；每一行只需要检查上一个或下一个是否是卒，是就+1

注意：通过这题指定了[array_column](https://www.php.net/manual/zh/function.array-column.php)原来可以通过索引取列，工作好几年并没用过；这大概也是刷题的意义吧。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了80.00%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了50.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String[][] $board
     * @return Integer
     */
    function numRookCaptures($board) {
        $row_r = $col_r = 0;
        for ($i = 0; $i < count($board); $i++) {
            for ($j = 0; $j < count($board[0]); $j++) {
                if ($board[$i][$j] == 'R') {
                    $row_r = $i;
                    $col_r = $j;
                }
            }
        }

        $row = str_replace('.', '', implode('', $board[$row_r]));
        $col = str_replace('.', '', implode('', array_column($board, $col_r)));

        $count = 0;
        if (strpos($row, 'Rp') !== false) $count++;
        if (strpos($row, 'pR') !== false) $count++;
        if (strpos($col, 'Rp') !== false) $count++;
        if (strpos($col, 'pR') !== false) $count++;

        return $count;
    }
}
```

### 算法复杂度
- 时间复杂度: O(N ^ 2)
- 空间复杂度：O(N)

### 参考
[https://leetcode-cn.com/problems/available-captures-for-rook/comments/34621](https://leetcode-cn.com/problems/available-captures-for-rook/comments/34621)