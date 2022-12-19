普通解法
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {
        $index = array_search($target,$nums);
        if($index !== false){
            return $index;
        }
        foreach($nums as $k => $v){
            if($v > $target){
                return $k;
            }          
        }
        return $k + 1;
    }
}
```

二分法，不知道为什么执行速度比上面循环还慢~
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {
        $index = array_search($target,$nums);
        if($index !== false){
            return $index;
        }
        
        $l = 0;$r = count($nums) - 1;
        while($l <= $r){
            $mid = floor(($l + $r)/2); 
           if($nums[$mid]<$target){
                $l = $mid + 1; 
            }else{
                $r = $mid - 1;
            }
        }
        return $l;
      
    }
}
```
