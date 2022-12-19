```
function coinChange($coins, $amount) {
    $dp = array_fill(1,$amount+1,$amount+1);
    $dp[0] = 0;
    for($i = 1;$i <= $amount;$i++){
        //$dp[$i] = PHP_INT_MAX;
        foreach($coins as $coin){
            if($i >= $coin){
                $dp[$i] = min($dp[$i],$dp[$i-$coin]+1);
            }
        }
    }
    return $dp[$amount]>$amount?-1:$dp[$amount];
}
```
