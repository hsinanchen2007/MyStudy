```
function nthUglyNumber($n) {
    $idx2 = 0;
    $idx3 = 0;
    $idx5 = 0;
    $dp[0] = 1;
    for($i=1;$i<$n;$i++){
        $min = min($dp[$idx2]*2, $dp[$idx3]*3, $dp[$idx5]*5);
        // 这里使用三个if而不是if esle if，是因为都是需要判断的，去重的。
        if($min == $dp[$idx2]*2) $idx2++;
        if($min == $dp[$idx3]*3) $idx3++;
        if($min == $dp[$idx5]*5) $idx5++;
        $dp[$i] = $min;
    }
    return $dp[$n-1];
}
```

