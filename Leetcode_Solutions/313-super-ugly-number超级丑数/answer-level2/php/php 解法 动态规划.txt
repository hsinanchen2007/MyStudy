```
function nthSuperUglyNumber($n, $primes) {
    $dp[0] = 1;
    $plen = count($primes);
    $idx = array_fill(0,$plen,0);
    for($i=1;$i<$n;$i++){
        $min = PHP_INT_MAX;
        for($j=0;$j<$plen;$j++){
            $min = min($min,$primes[$j]*$dp[$idx[$j]]);
        }
        $dp[$i] = $min;
        for($j=0;$j<$plen;$j++){
            if($primes[$j]*$dp[$idx[$j]] == $min){
                $idx[$j]++;
            }
        }
    }
    return $dp[$n-1];
}
```
