### 解题思路
给任意一个nxn的矩阵A，旋转九十度后得到矩阵B，

那么可知
A[x , y] = B[ y,n-1-x];

因为要求是要在原矩阵上操作，那就需要一次交换四个点的坐标值

左上的值给右上
右上的值给右下
右下的值给左下
左下的值给左上

假设左上点坐标为 [x,y],  w =  n-1
则：
左上：[x,y]  
右上：[y,w-x]  
右下：[w-x,w-y]  
左下：[w-y,x]

可以替换数据
box = value [x,y]  

set  [x,y]  =value [w-y,x]
set  [w-y,x]  =value [w-x,w-y]
set [w-x,w-y]  =value [y,w-x]
set [y,w-x] = box

同时，要记录下已经转换好的坐标，避免它再次被转换

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function rotate(&$matrix) {
        $n = count($matrix)-1;
        $check_tag = [];
         foreach($matrix as  $x=>$y_info)
        {
            foreach($y_info as  $y=>$value)
            {
                if(  $check_tag[$x][$y] ) continue;

                $matrix[$x][$y]= $matrix[$n-$y][$x];
                $matrix[$n-$y][$x]= $matrix[$n-$x][$n-$y];
                $matrix[$n-$x][$n-$y] = $matrix[$y][$n-$x];
                $matrix[$y][$n-$x]=$value;
                 //
                 $check_tag[$x][$y] = 1;
                $check_tag[$y][$n-$x]=1;
                $check_tag[$n-$x][$n-$y]=1;
                $check_tag[$n-$y][$x]=1;
            }
        }
    }
}
```