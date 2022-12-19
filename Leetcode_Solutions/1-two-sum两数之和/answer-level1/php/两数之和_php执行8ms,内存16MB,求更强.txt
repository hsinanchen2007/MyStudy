代码简单易懂
执行用时8 ms,内存消耗16MB
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $lt = array();
        foreach($nums as $k=>$v){
            $ft = $target - $v;
            if(isset($list[$ft])){
                return [$list[$ft],$k];
            }
            $list[$v] = $k;
        }
        return [];
    }
}
```
