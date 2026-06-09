
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $count = strlen($s);
        $ans = 0;
        $arr = array();
        for($i=0,$j=0; $j < $count; $j++){
            $chart = $s[$j];
            if(array_key_exists($chart,$arr)){
                $i = max($arr[$chart],$i);
            }
            $ans = max($ans,$j - $i + 1);
            $arr[$chart] = $j+1;
        }
        return $ans;
    } 
}
```
