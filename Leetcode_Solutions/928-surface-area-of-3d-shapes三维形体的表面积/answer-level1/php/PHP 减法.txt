### 解题思路
此处撰写解题思路
本题纯数学解题，我是利用减法进行操作。
1. 首先，遍历数组，每个正方体的表面积是6，所以统计所有个数求个，即value*6
2. 然后，根据表面积重叠，统计重叠部分，每一个网格上，重复的个数-1*2，和上面网格重叠部分*2,和左边网格重叠部分*2
3. 第一步统计的总和减去第二步统计的重叠部分，即为最终表面积
### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function surfaceArea($grid) {
        //首先统计所有的个数*6
        //做减法，将每一个的上的重叠数，以及左边和上边相邻的个数统计
        //将第一步减去第二步
        $count = 0;
        $des = 0;
        foreach ($grid as $row => $arrRow) {
            foreach ($arrRow as $col => $value) {
                if (!$value) {
                    continue;
                }
                $count += 6 * $value;
                $des += ($value - 1) * 2;
                if ($col > 0) {
                    $des += min($value , $grid[$row][$col - 1]) * 2;
                }
                if ($row > 0) {
                    $des += min($value , $grid[$row - 1][$col]) * 2;
                }
                
            }
        }
        return $count - $des;
    }
}
```