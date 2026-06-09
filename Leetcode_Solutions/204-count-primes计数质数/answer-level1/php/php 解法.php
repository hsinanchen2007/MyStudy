厄拉多塞筛法
```
function countPrimes($n) {
    $count = 0;
    $isPrim = array_fill(0,$n,true);
    for($i=2;$i<$n;$i++){
        if($isPrim[$i]){
            $count++;
            for($j=$i*$i;$j<$n;$j+=$i){
                $isPrim[$j] = false;
            }
        } 
    }
    return $count;
}
```
