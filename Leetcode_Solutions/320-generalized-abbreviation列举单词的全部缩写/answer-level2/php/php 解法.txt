```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function generateAbbreviations($word) {
        $ans = [];
        $this->helper($word,0,0,"",$ans);
        return $ans;
    }
    
    function helper($word,$i,$k,$str,&$ans){
        if($i == strlen($word)){
            if($k != 0) $str .= $k;
            $ans[] = $str;
            return ;
        }
        $this->helper($word,$i+1,$k+1,$str,$ans);
        $str = $str.($k==0?"":$k).$word[$i];
        $this->helper($word,$i+1,0,$str,$ans);
    }
}
```
