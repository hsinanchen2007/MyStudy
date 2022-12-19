### 解题思路
感谢[@mark-42](/u/mark-42/)的方法

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */

    function maxAreaOfIsland($grid) {
        $max_area = 0;
        for ($i = 0; $i < count($grid); $i++) {
            for ($j = 0; $j < count($grid[$i]); $j++) {
                //如果当前的点为土地点（值为1)，则进入搜寻模式
                if ($grid[$i][$j] == 1) {
                    // echo "Cur dot: [$i, $j] \n";
                    $max_area = max($max_area, $this->search_for_land($i, $j, $grid));
                }
            }
        } 
        return $max_area;
    }

    //这里注意grid要加&，by reference，否则主方程不会随之更新
    private function search_for_land($x, $y, &$grid){
        //如果坐标x,y出界或者为0，则返回
        if ($x < 0 || $y < 0 || $x >= count($grid) || $y >= count($grid[$x]) || $grid[$x][$y] == 0) { 
            return 0;
        } 

        $grid[$x][$y] = 0;//当前坐标点值归零，否则会陷入无限循环
        $area = 1;//当前点面积为1

        $area += $this->search_for_land($x + 1, $y, $grid);//东边坐标点
        $area += $this->search_for_land($x - 1, $y, $grid);//西边坐标点
        $area += $this->search_for_land($x, $y + 1, $grid);//南边坐标点
        $area += $this->search_for_land($x, $y - 1, $grid);//北边坐标点

        return $area;
    }


}
```