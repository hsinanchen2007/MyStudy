### 解题思路
感谢[@jyd](/u/jyd/)的提示和解法

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function lengthOfLIS($nums) {
        $lis = [];
        $l_len = 0;

        if(count($nums) < 2) return count($nums);

        foreach($nums as $num){
            //如果当前提取的数字比递增数组最后一个（也就是最大的）数大
            //直接添加到最尾部，并把结果加一
            if($l_len==0 || $lis[$l_len-1]<$num) $lis[$l_len++] = $num;
            else{
                //在递增数组中用二分法删除并插入新数字
                $left = 0;
                $right = $l_len;
                $mid = 0;
                while($left < $right){
                    $mid = floor(($left+$right)/2);//计算中间数index

                    //二分，如果比左边最大的大则舍去左边，否则舍去右边
                    if($lis[$mid] < $num) $left = $mid+1;
                    else $right = $mid;
                }
                $lis[$left] = $num;
            }
        }

        return $l_len;
        
    }
}
```