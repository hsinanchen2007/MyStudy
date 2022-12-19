```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permute($nums) {
        $allList = [];
        $this->backtrack(0,count($nums),$nums,$allList);
        return $allList;
    }
    
    function backtrack($start,$count,$nums,&$allList){
        if($start==$count){
            $allList[] = $nums;
        }else{
            for($i=$start;$i<$count;$i++){
                $this->swap($nums,$start,$i);
                $this->backtrack($start+1,$count,$nums,$allList);
                $this->swap($nums,$start,$i);
            }
        }
    }
    
    function swap(&$arr,$i,$j){
        $temp = $arr[$i];
        $arr[$i] = $arr[$j];
        $arr[$j] = $temp;
    }
}
```
另一种解法，通过栈来解
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function permute($nums) {
        $allList = [];
        $this->backtrack($nums,0,[],$allList,[]);
        return $allList;
    }
    
    function backtrack($nums,$depth,$stack,&$allList,$used){
        if($depth==count($nums)){
            $allList[] = $stack;
        }else{
            for($i=0;$i<count($nums);$i++){
                if(1==$used[$i]) continue;
                $used[$i] = 1;
                array_push($stack,$nums[$i]);
                $this->backtrack($nums,$depth+1,$stack,$allList,$used);
                $used[$i] = 0;
                array_pop($stack);
            }
        }
    }
}
```

