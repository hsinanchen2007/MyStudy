### 解题思路
如下所示，在纸上画一下很明显

### 代码

```php
class Solution {

    /**
     * @param Integer[] $rec1
     * @param Integer[] $rec2
     * @return Boolean
     */
    function isRectangleOverlap($rec1, $rec2) {
       //在纸上画一下很明显
        $a = $rec2[0]>=$rec1[2];//矩形2左下角大于矩形1右上角
        $b = $rec1[0]>=$rec2[2];//矩形1左下角大于矩形2右上角
        $c = $rec1[1]>=$rec2[3];//矩形2右上角小于矩形1左下角
        $d = $rec2[1]>=$rec1[3];//矩形2右上角大于矩形1左下角
        if($a || $b || $c || $d){
            return false;
        }else{
            return true;
        }
    }
}

```