### 解题思路
利用内置函数统计各个元素的重复次数；
遍历结果数组，遇到次数大于1的就返回；

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findRepeatNumber($nums) {
        $count = array_count_values($nums);
        foreach($count as $k=>$v){
            if($v > 1){
                return $k;
            }
        }
        return 0;
/*
        $count = count($nums);
        sort($nums);
        for($i=1; $i<$count; $i+=2){
            if($nums[$i] == $nums[$i-1] || $nums[$i] == $nums[$i+1]){
                return $nums[$i];
            }
        }
        return 0;
        */
    }
}
```