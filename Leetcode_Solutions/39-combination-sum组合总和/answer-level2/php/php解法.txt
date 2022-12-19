```
class Solution {
    
    private $ans = [];
    
    /**
     * @param Integer[] $candidates
     * @param Integer $target
     * @return Integer[][]
     */
    function combinationSum($candidates, $target) {
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
                array_push($list,$candidates[$i]);
                $this->backtrack($candidates,$target-$candidates[$i],$i,$list);
                array_pop($list);
            }
        }
    }
}
```
