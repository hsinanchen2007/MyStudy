```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $lenstr = strlen($s);
        $str = '';
        $len = 0;
        for($i=0;$i<$lenstr;$i++){
            $t = substr($s,$i,1);
            $l = strpos($str,$t);
            if($l!==False){
                $str .= $t;
                $str = substr($str,$l+1);
            }else{
                $str .= $t;
            }
            $len = strlen($str)>$len?strlen($str):$len;
        }
        return $len;
    }
}
```
