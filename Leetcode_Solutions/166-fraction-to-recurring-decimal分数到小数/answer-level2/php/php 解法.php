```
function fractionToDecimal($numerator, $denominator) {
    if($denominator == 0) return "0";
    $ans = "";
    if(($numerator<0 && $denominator>0) || ($numerator>0 && $denominator<0)){
        $ans = "-";
    }
    $n = abs($numerator);
    $d = abs($denominator);
    $ans .= floor($n/$d);
    $mod = $n % $d;
    if($mod == 0) return $ans;
    $ans .= ".";
    $map = [];
    while($mod != 0){
        if(isset($map[$mod])){
            $ans = substr_replace($ans,"(",$map[$mod],0);
            $ans .= ")";
            break;
        }
        $map[$mod] = strlen($ans);
        $mod *= 10;
        $ans .= floor($mod/$d);
        $mod %= $d;
    }
    return $ans;
}
```
