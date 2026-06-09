### 解题思路
初看题目，我没太理解他的意思说实话，后来研究出来了；可以看做一列一列的每一排的v个正方体的表面积和；比如[[1,0],[0,2]]这个就是有两列（count([[1,0],[0,2]])）,第一列是[1,0],然后第一列有两排，第一排的位置放1个立方体，第二排的位置放0个立方体，这样推算的。  
看懂题目后，思路其实就是遍历每一排的每一列，会有v值，也就是多少个立方体，看成一个整体来算，这个整体的上下重叠，每列左右重叠，每排前后重叠即可


### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function surfaceArea($grid) {
        $mianji = 0;
        $allCount = 0;
        $delCount = 0;
        //循环每一列，每一行
        foreach ($grid as $colIndex => $colVal) {
            foreach ($colVal as $cowIndex => $cowVal) {
                //如果这个位置没有立方体，直接跳过
                if ($cowVal == 0) {
                    continue;
                }
                //全部立方体数量面累加
                $allCount += (6*$cowVal);
                //1.第一列的情况
                if ($colIndex == 0) {
                    //1.第一排
                    if ($cowIndex == 0) {
                        //第一列第一排只需要注意上下重叠的情况
                        $delCount += ($cowVal-1) * 2;
                    }else{
                        //第一列非第一排需要注意上下重叠 + 当前列前一排的重叠
                        $delCount += (($cowVal-1) + min($grid[$colIndex][$cowIndex - 1] , $cowVal)) * 2;
                    }
                }else{
                //2.非第一列
                //    第一排 
                    if ($cowIndex == 0) {
                        //非第一列第一排需要注意 上下重叠 + 前一列当前排的 立柱重叠情况
                        $delCount += (($cowVal-1) + min($grid[$colIndex -1][$cowIndex] , $cowVal)) * 2;
                    }else{
                        //非第一列第一排需要注意 上下重叠 + 前一列当前排的 + 当前列前一排的 立柱重叠情况
                        $delCount += (($cowVal-1) 
                            + min($grid[$colIndex -1][$cowIndex] , $cowVal) 
                            + min($grid[$colIndex][$cowIndex - 1] , $cowVal)) * 2;
                    }
                }

            }
        }
        return $allCount - $delCount;
    }
}
```