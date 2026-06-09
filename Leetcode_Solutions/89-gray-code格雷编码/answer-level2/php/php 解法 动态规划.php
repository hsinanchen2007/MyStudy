```
function grayCode($n) {
    if($n == 0) return [0];
    $dp[1] = [0,1];
    $head = 2;
    for($i = 2; $i <= $n; $i++){
        $dp[$i] = $dp[$i-1];
        for($j=count($dp[$i-1])-1;$j>=0;$j--){
            array_push($dp[$i],$dp[$i-1][$j]+$head);
        }
        $head <<= 1;
    }
    return $dp[$n];
}
```
