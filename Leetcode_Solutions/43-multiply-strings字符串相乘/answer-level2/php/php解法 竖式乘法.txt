```
function multiply($num1, $num2) {
    if($num1=='0' || $num2=='0') return '0';
    $len1 = strlen($num1);
    $len2 = strlen($num2);
    $res = array_fill(0,($len1+$len2),0);
    for($i=$len2-1;$i>=0;$i--){
        for($j=$len1-1;$j>=0;$j--){
            $tmp = $res[$i+$j+1]+$num1[$j]*$num2[$i];
            $res[$i+$j+1] = fmod($tmp,10);
            $res[$i+$j] += floor($tmp/10);
        }
    }
    $ans = '';
    for($i=0;$i<$len1+$len2;$i++){
        if($i==0 && $res[$i]=='0') continue;
        $ans .= (string) $res[$i];
    }
    return $ans;
}
```
