### 解题思路

只求一个点的小方块的面积公式为 `grid[i][j] * 6 - (grid[i][j] - 1) * 2`，其中减去的是上下重合的面积，可以简写为 `grid[i][j] * 4 + 2`

考虑到方块之间有重合，所以是需要求自己的面积，然后减去与左侧及上侧小方块重合的面积。

其中特殊的位于临界位置的三个条件：
- `grid[0][0]` : 只需要求自己的面积
- `grid[0][j]` (j>0) : 只需要求自己的面积然后减去与左侧小方块重合的面积
- `grid[i][0]` (i>0) : 只需要求自己的面积然后减去与上侧小方块重合的面积


### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function surfaceArea($grid) {
        $area = 0;
        for ($i = 0; $i < count($grid); $i++){
            for ($j = 0; $j < count($grid[0]);$j ++){
                if ($grid[$i][$j] == 0){
                    continue;
                }
                if ($i == 0 && $j == 0){
                    $area += 4 * $grid[$i][$j] + 2;
                } else if ($i == 0 && $j != 0){
                    $area += 4 * $grid[$i][$j] + 2 - min($grid[$i][$j-1],$grid[$i][$j]) * 2;
                }else if ($j == 0 && $i != 0){
                    $area += 4 * $grid[$i][$j] + 2 - min($grid[$i-1][$j],$grid[$i][$j]) * 2;
                }else{
                    $area += 4 * $grid[$i][$j] + 2 - min($grid[$i-1][$j],$grid[$i][$j]) * 2 - min($grid[$i][$j-1],$grid[$i][$j]) * 2;
                }
            }
        }
        return $area;
    }
}
```