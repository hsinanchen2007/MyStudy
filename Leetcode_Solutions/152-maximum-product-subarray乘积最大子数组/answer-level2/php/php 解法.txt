```
function maxProduct($nums) {
    $max = PHP_INT_MIN;
    $imax = 1;
    $imin = 1;
    foreach($nums as $num){
        if($num<0){
            $tmp = $imax;
            $imax = $imin;
            $imin = $tmp;
        }
        $imax = max($num,$imax*$num);
        $imin = min($num,$imin*$num);
        $max = max($max, $imax);
    }
    return $max;
}
```
