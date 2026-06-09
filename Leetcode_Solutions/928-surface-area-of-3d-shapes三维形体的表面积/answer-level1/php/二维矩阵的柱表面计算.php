### 解题思路
这道题目一开始着实不理解，偷偷看了眼别人的理解，才明白这是个类似矩阵的计算，遍历累加所有柱的表面积然后减去重叠面积。

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function surfaceArea($grid) {
        $oneTotal = 0;
        $dec = 0;
        //拆解降维
        foreach($grid as $row => $cubt){
         //定义当前块的右侧块坐标   $grid[$row][$col+1]
         //定义当前块的下侧块坐标   $grid[$row+1][$col]
            foreach($cubt as $col => $cu){
                //如果当前块空，则跳过
                if(empty($cu)){
                    continue;
                }
                //累计当前块柱的总面积
                $oneT = 4 * $cu + 2;
                //求总面积
                $oneTotal += $oneT;
                $right =0;
                $bt =0;
                if(isset($grid[$row][$col+1]) && !empty($grid[$row][$col+1])){
                    //计算与右侧块重叠的块数
                    $right = $grid[$row][$col+1]<$cu?$grid[$row][$col+1]:$cu;
                }
                if(isset($grid[$row+1][$col]) && !empty($grid[$row+1][$col])){
                    //计算与下侧块重叠的块数
                    $bt = $grid[$row+1][$col]<$cu?$grid[$row+1][$col]:$cu;               
                }
                $redu = $right+$bt;
                $dec += $redu*2;
            }
        }
        return $oneTotal-$dec;
    }
}
```