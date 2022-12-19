找规律，n是数组长度，sum是数组和
F[i] = F[i-1] + sum - n*A[n-i]
```
function maxRotateFunction($A) {
    $n = count($A);
    $sum = array_sum($A);
    $F[0] = 0;
    for($i=0;$i<$n;$i++) $F[0] += $i*$A[$i];
    for($i=1;$i<$n;$i++) $F[$i] = $F[$i-1] + $sum - $n*$A[$n-$i];
    return max($F);
}
```
