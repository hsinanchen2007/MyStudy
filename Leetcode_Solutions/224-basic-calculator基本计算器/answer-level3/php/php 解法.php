```
class Solution {
    function calculate($s) {
        $ans = 0;
        $num = '';
        $stack = [];
        $sign = 1;
        for($i=0;$i<strlen($s);$i++){
            if($s[$i]==' '){
                continue;
            }else if($s[$i]>='0' && $s[$i]<='9'){
                $num .= $s[$i];
            }else{
                if($num!=''){
                    array_push($stack,$num);
                    $num = '';
                }
                if($s[$i]==')'){
                    $arr = [];
                    while(end($stack) !== '('){ // 注意之前这里用的!=,应该用!==
                        array_push($arr,array_pop($stack));
                    }
                    array_pop($stack);
                    array_push($stack,$this->helper($arr,'desc'));
                }else{
                    array_push($stack,$s[$i]);
                }
            }
        }
        if($num!=''){
            array_push($stack,$num);
            $num = '';
        }
        
        return $this->helper($stack);
    }

    function helper($arr, $order='asc'){
        $ans = 0;
        $sign = 1;
        if($order=='asc'){
            for($j=0;$j<count($arr);$j++){
                if($arr[$j]=='-'){
                    $sign = -1;
                }else if($arr[$j]=='+'){
                    $sign = 1;
                }else{
                    $ans += $sign*$arr[$j];
                }
            }
        }else if($order=='desc'){
            for($j=count($arr)-1;$j>=0;$j--){
                if($arr[$j]=='-'){
                    $sign = -1;
                }else if($arr[$j]=='+'){
                    $sign = 1;
                }else{
                    $ans += $sign*$arr[$j];
                }
            }
        }
        return $ans;
    }
}   
```
