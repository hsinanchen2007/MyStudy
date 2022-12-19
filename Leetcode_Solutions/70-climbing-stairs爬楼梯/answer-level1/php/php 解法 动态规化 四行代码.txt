```
function climbStairs($n) {
    $dp = [1=>1,2=>2];
    for($i=3;$i<$n+1;$i++)
        $dp[$i] = $dp[$i-1]+$dp[$i-2];
    return $dp[$n];
}
```
