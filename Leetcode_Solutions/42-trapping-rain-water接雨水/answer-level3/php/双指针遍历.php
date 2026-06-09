### 解题思路
看代码注释

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        $rs = 0;//初始化结果值
        $l  = 0;//初始化左指针
        $r  = count($height) - 1;//初始化右指针
        $l_max = $r_max = 0; //初始化左右最大值
        while($l < $r){ //循环条件 当左指针小于右指针时循环
            if($height[$l] < $height[$r]){  //当左指针值小于右指针值时 进行左指针遍历
                if($height[$l] >= $l_max){  //当左指针的值大于等于左最大值时 
                    $l_max = $height[$l]; //将其赋值给左最大值
                }else{ //当左指针的值小于左最大值时 
                    $rs += $l_max - $height[$l];//结果值累加上左侧最大值减掉当前指针的值
                }
                $l++;
            }else{ //当左指针值大于等于右指针值时 进行右指针遍历
                if($height[$r] >= $r_max){ //当右指针的值大于等于右最大值时 
                    $r_max = $height[$r];//将其赋值给右最大值
                }else{//当右指针的值小于右最大值时 
                    $rs += $r_max -$height[$r];//结果值累加上右侧最大值减掉当前指针的值
                }
                $r --;
            }
        }
        return $rs;
    }
}
```