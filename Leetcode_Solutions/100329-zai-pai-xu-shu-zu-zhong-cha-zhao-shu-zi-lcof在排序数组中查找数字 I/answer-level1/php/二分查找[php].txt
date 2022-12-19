### 解题思路
二分查找

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        $index = $this->binary_search($nums,$target);
        $tmp = $index;
        if(is_null($index)) return 0;
        $count=1;
        while($nums[$index+1]===$target){
            $count++;
            $index = $index+1;
        }
        $index = $tmp;
        while($nums[$index-1]===$target){
            $count++;
            $index = $index-1;
        }
        return $count;
    }

    function binary_search($nums,$target){
        $left = 0;
        $right = count($nums)-1;
        while($left<=$right){
            $mid = floor(($left+$right)/2);
            if($nums[$mid]==$target) return $mid;
            if($nums[$mid]>$target) $right = $mid-1;
            if($nums[$mid]<$target) $left = $mid+1;
        }
        return null;
    }
}
```