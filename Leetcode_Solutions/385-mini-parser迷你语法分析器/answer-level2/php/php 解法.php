```
class Solution {
    /**
     * @param String $s
     * @return NestedInteger
     */
    function deserialize($s) {
        if($s[0]!=="[") return new NestedInteger($s);
        $stack = [];
        $num = '';
        for($i=0;$i<strlen($s);$i++){
            if($s[$i]==="["){
                array_push($stack,$s[$i]);
            }else if($s[$i]>='0' && $s[$i]<='9' || $s[$i]=='-'){
                $num .= $s[$i];
            }else if($s[$i]===","){
                if($num!=='') array_push($stack,new NestedInteger($num));
                $num = '';
            }else if($s[$i]==="]"){
                if($num!=='') array_push($stack,new NestedInteger($num));
                $num = '';
                $arr = [];
                while(end($stack)!=='['){
                    $arr[] = array_pop($stack);
                }
                array_pop($stack);
                array_push($stack,$this->helper($arr));
            }
        }
        return $stack[0];
    }

    function helper($arr){
        $obj = new NestedInteger();
        for($i=count($arr)-1;$i>=0;$i--){
            $obj->add($arr[$i]);
        }
        return $obj;
    }
}
```
