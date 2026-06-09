### 解题思路
由于数组中的元素是有序的，所以采用首尾相加的方式来查找。
1.当两元素和大于`$target`时则需要将尾部指针向前移动一位，使用较小的元素相加后再进行比较
2.反之，当两元素和小于`$target`时，则需要将头部元素的指针向后移动一位，使用较大的元素相加后再进行比较
3.时间复杂度为 O(n)
### 代码

```php
class Solution {

    /**
     * @param Integer[] $numbers
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $l = 0;
        $r = count($nums)-1;
        
        while($l<$r){
            $sum = $nums[$l] + $nums[$r];
            if($sum == $target){
                return [$l+1,$r+1];
            }
            if($sum < $target){
                $l++;
            }
            if($sum > $target){
                $r--;
            }    
        }
    }
}
```