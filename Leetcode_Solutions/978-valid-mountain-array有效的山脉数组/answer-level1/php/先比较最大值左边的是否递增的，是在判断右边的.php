![图片.png](https://pic.leetcode-cn.com/f32314cc5d2582949f693a8c58e5936e04947879e7c5a6144e8c6ea6b14ac935-%E5%9B%BE%E7%89%87.png)

思路：找到数组的最大值下标索引 $max_index，先检查最大值左边(0,$max_index)的数组是否有不满足递增的，有则返回false，结束循环；左边都是递增的，在判断最大值右边的从($max_index,$len-1)开始的数组是否满足条件，有不满足的则返回false，结束循环；
```
class Solution {

    /**
     * @param Integer[] $A
     * @return Boolean
     */
    function validMountainArray($A) {
        $len = count($A);
        if($len <3)  return false;
        $max_index = array_search(max($A), $A);
        if($max_index == 0 || $max_index == $len-1) return false;
        $i=0;
        while($i < $max_index){
             if($A[$i] >= $A[$i+1]) return false;
             $i++;
        }
        $j = $max_index;
        while($j < $len-1){
             if($A[$j] <= $A[$j+1]) return false;
             $j++;
        }
        return true;
    }
}
```
