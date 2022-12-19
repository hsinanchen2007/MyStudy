方法很简单，运行速度不太理想
```
class Solution {

    /**
     * @param Integer $n
     * @param Integer $k
     * @return Integer[][]
     */
    function combine($n, $k) {
        $this->n = $n;
        $this->k = $k;
        $this->backtrack(1,[]);
        return $this->ans;
    }
    
    private $n,$k,$ans;
    
    function backtrack($first,$comb){
        if($this->k == count($comb)){
            $this->ans[] = $comb;
        }
        for($i = $first;$i<$this->n+1;$i++){
            array_push($comb,$i);
            $this->backtrack($i+1,$comb);
            array_pop($comb);
        }
    }
}
```
