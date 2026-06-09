### 解题思路
此处撰写解题思路
本题的解题思路是比较清晰的，此类问题最直接的方法就是使用回溯来试探边界，回溯法的核心就是循环，回溯以及终止条件。
在本题中，我的循环其实是分为两步，第一步，直接二维数组的遍历，找到value等于1的值，然后从该点开始试探统计；第二步，是在回溯函数中，向上下左右四个方向进行试探，其实也可以认为是一种遍历。
回溯过程：其实就隐藏在上下左右四个方向试探的过程，当某个方向失败后，回到最初的七点，然后向下一个方向试探
终止条件：也即当四个方向都不存在是1且未统计的时候
剪枝：本题中可以利用剪枝方式来减少回溯过程和统计，即使用数组arrUsed来存储已经统计过的节点位置信息，避免多次统计和遍历
### 代码

```php
class Solution {
    public $max = 0;
    public $arrUsed = [];
    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxAreaOfIsland($grid) {
        $maxLoop = 0;
        foreach ($grid as $row => $arrRow) {
            foreach ($arrRow as $col => $value) {
                if ($value && !isset($this->arrUsed[$row][$col])) {
                    $this->max = max($this->max,$this->backtracking($grid, $row, $col, 1));
                }
            }
        }
        return $this->max;
    }

    function backtracking($grid, $row, $col, $maxLoop) {
        $this->arrUsed[$row][$col] = 1;
        $rowCount = count($grid);
        $colCount = count($grid[0]);

        if ($row > 0 && $grid[$row - 1][$col] && !isset($this->arrUsed[$row - 1][$col])) {
            $maxLoop ++;
            $maxLoop = $this->backtracking($grid, $row - 1, $col , $maxLoop);
        }
        if ($row < $rowCount - 1 && $grid[$row + 1][$col] && !isset($this->arrUsed[$row + 1][$col])) {
            $maxLoop ++;
            $maxLoop = $this->backtracking($grid, $row + 1, $col , $maxLoop);
        }
        if ($col > 0 && $grid[$row][$col - 1] && !isset($this->arrUsed[$row][$col - 1])) {
            $maxLoop ++;
            $maxLoop = $this->backtracking($grid, $row, $col - 1 , $maxLoop);
        }
        if ($col < $colCount - 1 && $grid[$row][$col + 1] && !isset($this->arrUsed[$row][$col + 1])) {
            $maxLoop ++;
            $maxLoop = $this->backtracking($grid, $row, $col + 1 , $maxLoop);
        }
        return $maxLoop;
    }
}
```