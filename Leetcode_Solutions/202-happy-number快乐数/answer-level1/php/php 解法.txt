所有不快乐数的数位平方和计算，最後都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中。
```
function isHappy($n) {
    $sum = 0;
    while($n>0){
        $a = $n%10;
        $sum += $a*$a;
        $n = floor($n/10);
    }
    if($sum == 4) return false;
    if($sum == 1) return true;
    return $this->isHappy($sum);
}
```
