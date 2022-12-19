### 解题思路
定义好边界，不断的使用中间值与目标值作比较；
1 当目标值小于中间值时，说明目标值分布在左半边，此时则将右边界移动至 `$mid` 处
2 当目标值大于中间值时，说明目标值分布在右半边，此时则将左边界移动至 `$mid` 处
3 左右边界不停靠拢，直至中间值等于目标值
4 注意 `$mid` 的取值算法，防止 数据越界

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        
        /**
        这个方法的时间复杂度为 O(n)
        for($i=0;$i<count($nums);$i++){
            if($nums[$i] == $target){
                return $i;
            }
        }*/

       // 因为是有序数组，所以使用 二分查找法，时间复杂度为 O(logn)
        $l = 0; // 左边界
        $r = count($nums); // 右边界,为开区间
        while($l < $r){
            // $mid = (int)(($l+$r)/2);  但是若 low+high > Interger.MAX_VALUE 时，此时会导致数据溢出，则导致mid错误，所以 mid 应该改为 low +（high - low）/ 2;

            $mid = (int)($l+($r-$l)/2);
            if($target == $nums[$mid]){
                return $mid;
            }
            if($target < $nums[$mid]){
                $r = $mid;
            }
            if($target > $nums[$mid]){
                $l = $mid+1;
            }
        }
        return -1;
    }
}
```