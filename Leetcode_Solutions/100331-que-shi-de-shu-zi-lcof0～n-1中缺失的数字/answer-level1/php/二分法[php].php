### 解题思路
见代码

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        $left=0;
        $right=count($nums)-1;
        while($left<$right){
            $mid = floor(($left+$right)/2);
            //如果中间的key与value相等，说明左边连续，右边不连续。从右边开始查找
            if($nums[$mid] == $mid){
                $left = $mid+1;
            }else{
                //如果key与value不相等，说明左边不连续，从左边开始查找
                $right = $mid-1;
            }
        }
        //左右两个指针，相等后就相当于找到了缺失值的附近
        if($nums[$left] == $left){
            return $nums[$left]+1;
        }
        return $nums[$left]-1;
    }
}
```