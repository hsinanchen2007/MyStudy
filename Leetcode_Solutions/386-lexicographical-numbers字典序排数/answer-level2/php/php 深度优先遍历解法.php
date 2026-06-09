```
class Solution {

    /**
     * @param Integer $n
     * @return Integer[]
     */
    function lexicalOrder($n) {
        $res = [];
        $this->helper(0,$n,$res);
        return $res;
    }
    
    function helper($k,$n,&$res){
        if($k>$n) return ;
        if($k>0) $res[] = $k;
        for($i=0;$i<=9;$i++)
            if(10*$k+$i>0) $this->helper(10*$k+$i,$n,$res);
    }
}
```
