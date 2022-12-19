```
function titleToNumber($s) {
    $n = strlen($s);
    $ans = 0;
    for($i=0;$i<$n;$i++){
        $ans += (ord($s[$i])-64)*pow(26,$n-$i-1);
    }
    return $ans;
}
```
