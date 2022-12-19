```
function integerBreak($n) {
    if($n==2) return 1;
    if($n==3) return 2;
    $a = 1;
    while($n>4){
        $n-=3;
        $a *=3;
    }
    return $a*$n;
}
```
