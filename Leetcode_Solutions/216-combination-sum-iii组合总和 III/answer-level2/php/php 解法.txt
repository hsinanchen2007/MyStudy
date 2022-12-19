```
class Solution {

    /**
     * @param Integer $k
     * @param Integer $n
     * @return Integer[][]
     */
    function combinationSum3($k, $n) {
        $list = [];
        $this->helper($k,$n,1,$list);
        return $this->ans;
    }
    
    private $ans=[];
    
    function helper($k,$n,$start,$list){
        if($k==0){
            if($n==0) $this->ans[] = $list;
            return ;
        }
        for($i=$start;$i<=9;$i++){
            array_push($list,$i);
            $this->helper($k-1,$n-$i,$i+1,$list);
            array_pop($list);
        }
    }
}
```
