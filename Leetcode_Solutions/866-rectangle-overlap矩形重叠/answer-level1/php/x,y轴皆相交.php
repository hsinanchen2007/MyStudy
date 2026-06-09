### 解题思路
查看左下右上坐标的x,y是否同时有相交的区域

### 代码

```php
class Solution {

    /**
     * @param Integer[] $rec1
     * @param Integer[] $rec2
     * @return Boolean
     */
    function isRectangleOverlap($rec1, $rec2) {
        // return !($rec1[2] <= $rec2[0] || $rec2[2] <= $rec1[0] || $rec1[3] <= $rec2[1] || $rec2[3] <= $rec1[1]);

        $x1 = max($rec1[0],$rec2[0]);//更靠右矩形的左下角x坐标
        $x2 = min($rec1[2],$rec2[2]);//更靠左矩形的右上角x坐标
        $y1 = max($rec1[1],$rec2[1]);//更靠上矩形的左下角y坐标
        $y2 = min($rec1[3],$rec2[3]);//更靠下矩形的右上角y坐标

        $xx = $x2-$x1;//检查是否重叠
        $yy = $y2-$y1;

        if($xx>0 && $yy>0){
            return true;
        }else{
            return false;
        }
    }
}
```