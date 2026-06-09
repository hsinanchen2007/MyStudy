```
function rotate(&$matrix) {
    $n = count($matrix);
    for($i=0;$i<$n;$i++){
        for($j=$i;$j<$n;$j++){//注意这里！！！
            $tmp = $matrix[$i][$j];
            $matrix[$i][$j] = $matrix[$j][$i];
            $matrix[$j][$i] = $tmp;
        }
    }
    for($i=0;$i<$n;$i++){
        for($j=0;$j<floor($n/2);$j++){
            $tmp = $matrix[$i][$j];
            $matrix[$i][$j] = $matrix[$i][$n-$j-1];
            $matrix[$i][$n-$j-1] = $tmp;
        }
    }
    
}
```
