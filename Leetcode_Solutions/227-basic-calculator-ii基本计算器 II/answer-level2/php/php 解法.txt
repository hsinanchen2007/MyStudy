单栈+sign标记
```
function calculate($s) {
    $s = trim($s);
    $stack = [];
    $num = '';
    $sign = '+';
    for($i=0;$i<strlen($s);$i++){
        if($s[$i] ===' '){
            continue;
        }else if($s[$i]>='0' && $s[$i]<='9'){
            $num .= $s[$i];
        }
        if($s[$i] === '-' || $s[$i] === '+' || $s[$i] === '*' || $s[$i] === '/' || $i === strlen($s)-1){
            if($sign === '+'){
                array_push($stack,$num*1);
            }else if($sign === '-'){
                array_push($stack,$num*-1);
            }else if($sign === '*'){
                array_push($stack,array_pop($stack)*$num);
            }else{
                array_push($stack,(int) (array_pop($stack)/$num));
            }
            $sign = $s[$i];
            $num = '';
        }
    }
    $ans = 0;
    foreach($stack as $st){
        $ans += $st;
    }
    return $ans;
}
```
