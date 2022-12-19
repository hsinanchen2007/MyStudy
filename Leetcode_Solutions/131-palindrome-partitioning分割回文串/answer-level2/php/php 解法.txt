```
class Solution {

    /**
     * @param String $s
     * @return String[][]
     */
    function partition($s) {
        $arr = [];
        $res = [];
        $this->helper($s,$arr,$res);
        return $res;
    }
    
    function helper(&$s,&$arr,&$res){
        if($s == null || strlen($s) == 0){
            $res[] = $arr;
        }
        for($i=0;$i<strlen($s);$i++){
            $tmp = substr($s,0,$i+1);
            if($this->isPalidrome($tmp)){
                $arr[] = $tmp;
                $this->helper(substr($s,$i+1),$arr,$res);
                array_pop($arr);
            }
        }
    }
    
    private function isPalidrome($str) {
        $left = 0;
        $right = strlen($str) - 1;
        while ($left < $right) {
            if ($str[$left] != $str[$right]) return false;
            $left++;
            $right--;
        }
        return true;
    }
}
```
