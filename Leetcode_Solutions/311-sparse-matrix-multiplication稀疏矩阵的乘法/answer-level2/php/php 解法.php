```
function multiply($A, $B) {
    $ans = [];
    for($i=0;$i<count($A);$i++){
        for($j=0;$j<count($B[0]);$j++){
            $ans[$i][$j] = 0;
            for($k=0;$k<count($B);$k++) {
                $ans[$i][$j] += $A[$i][$k]*$B[$k][$j];
            }
        }
    }
    return $ans;
}
```
