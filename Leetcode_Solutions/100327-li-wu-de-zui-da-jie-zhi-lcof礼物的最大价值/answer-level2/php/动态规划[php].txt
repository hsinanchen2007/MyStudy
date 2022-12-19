### 解题思路
状态转移方程 $dp[$i][$j] = max($dp[$i-1][$j],$dp[$i][$j-1])+$grid[$i][$j]
初始化第1行、第1列的$dp值，而后根据状态转移方程依次计算就OK

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxValue($grid) {
        $column=count($grid[0]);
        $row = count($grid);

        //初始化值
        $dp[0][0] = $grid[0][0];
        //初始化第1列的值
        for($i=1;$i<$row;$i++){
            $dp[$i][0] = $dp[$i-1][0]+$grid[$i][0];
        }

        //初始化第1行的值
        for($j=1;$j<$column;$j++){
            $dp[0][$j] = $dp[0][$j-1]+$grid[0][$j];
        }

        //根据状态转移方程得出数据
        for($i=1;$i<$row;$i++){
            for($j=1;$j<$column;$j++){
                $dp[$i][$j] = max($dp[$i-1][$j],$dp[$i][$j-1])+$grid[$i][$j];
            }
        }

        return $dp[$row-1][$column-1];
    }
}
```