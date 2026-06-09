全部转成负数防止溢出
```
function divide($dividend, $divisor) {
    $max = pow(2,31) - 1;
    $min = 0-pow(2,31);
    if($dividend==$min && $divisor==-1) return $max;
    $flag = 1;
    if($dividend > 0){
        $dividend = 0 - $dividend;
    }else{
        $flag = -$flag;
    }
    if($divisor > 0){
        $divisor = 0 - $divisor;
    }else{
        $flag = -$flag;
    }
    $s = 0;
    while($dividend <= $divisor){
        $k = 1;
        $tmp = $divisor;
        #本题中，如果除法结果溢出，则返回$max，在子while循环条件中得以利用
        while($dividend < $tmp+$tmp && $tmp+$tmp<0){
            $tmp += $tmp;
            $k += $k;
        }
        $s += $k;
        $dividend -= $tmp;
    }
    return ($flag>0)?$s:-$s;
}
```
