```
class Solution {

    /**
     * @param Integer $n
     * @return String
     */
    function countAndSay($n) {
        $arr = ["1"];
        for($i=1;$i<$n;$i++){
            $arr[$i] = $this->convert($arr[$i-1]);
        }
        return $arr[$n-1];
    }
    
    function convert($str){
        $ans = "";
        $count = 1;
        for($i=0;$i<strlen($str);$i++){
            if(isset($str[$i+1]) && $str[$i+1] == $str[$i]){
                $count++;
            }else{
                $ans = $ans.$count.$str[$i];
                $count = 1;
            }
        }
        return $ans;
    }
}
```
