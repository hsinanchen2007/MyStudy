```
function numSquares($n) {
    $dp = [];
    for($i=0;$i<=$n;$i++){
        $dp[$i] = $i;
        for($j=1;$j*$j<=$i;$j++){
            $dp[$i] = min($dp[$i],$dp[$i-$j*$j]+1);
        }
    }
    return $dp[$n];
}
```
