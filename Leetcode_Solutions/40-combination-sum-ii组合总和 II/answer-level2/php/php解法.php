在39题的基础上，加上条件判断
遍历的时候，每次的start应该为i+1,并且在遍历时需要做一个判重
```
class Solution {
    
    private $ans = [];
    
    /**
     * @param Integer[] $candidates
     * @param Integer $target
     * @return Integer[][]
     */
    function combinationSum2($candidates, $target) {
        if(count($candidates)==0) return [];
        sort($candidates);
        $this->backtrack($candidates,$target,0,[]);
        return $this->ans;
    }
    
    function backtrack($candidates,$target,$start,$list){
        if($target < 0){
            return;
        }else if($target == 0){
            $this->ans[] = $list;
        }else{
            for($i=$start;$i<count($candidates) && ($target-$candidates[$i])>=0;$i++){
                if($i>$start && $candidates[$i] == $candidates[$i-1]){
                    continue;
                }
                array_push($list,$candidates[$i]);
                $this->backtrack($candidates,$target-$candidates[$i],$i+1,$list);
                array_pop($list);
            }
        }
    }
}
```
