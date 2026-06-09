### 解题思路
1. 简单拆分+合并
2. 高效答案：把两个数组按从大到小的顺序，逐个插入长数组尾部，最后如果短数组还有剩余的话就把剩余元素全部插入

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer $m
     * @param Integer[] $B
     * @param Integer $n
     * @return NULL
     */
    function merge(&$A, $m, $B, $n) {
        //懒省事答案
        // if(!empty($B)){
        //     $new_A = array_slice($A, 0, -$n);//把长数组从尾部切掉短数组数量的元素
        //     $A = array_merge($new_A,$B);//合并两个数组
        //     sort($A);//排序
        // }

        //高效答案
        $ele_left = $m + $n - 1;//总共剩余元素数量
        $ele_long = $m - 1;//长数组的剩余元素数量
        $ele_short = $n - 1;//短数组的剩余元素数量
        while ($ele_long >= 0 && $ele_short >= 0) {//如果两个数组都没有叠加进答案数组
            $A[$ele_left--] = $A[$ele_long] > $B[$ele_short] ? $A[$ele_long--] : $B[$ele_short--]; 
            /*---- 以上一行等同于 ----
            if($A[$ele_long] > $B[$ele_short]){
                $A[$ele_left] = $A[$ele_long];
                $ele_long--;
            }
            else{
                $A[$ele_left] = $B[$ele_short];
                $ele_short--;
            }
            $ele_left--;
            */
        } 

        //如果被合并短数组还有剩余，则全部按顺序叠加至答案
        while ($ele_short >= 0) {
            $A[$ele_left--] = $B[$ele_short--]; 
            /*---- 以上一行等同于 ----
            $A[$ele_left] = $B[$ele_short];
            $ele_left--;
            $ele_short--;
            */
        } 
        
    }
}
```