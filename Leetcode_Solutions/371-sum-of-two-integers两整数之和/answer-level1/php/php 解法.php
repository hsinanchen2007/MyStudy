```
function getSum($a, $b) {
    $sum = $a ^ $b;
    $carry = ($a & $b)<<1;
    if($carry != 0) return $this->getSum($sum, $carry);
    return $sum ;
}
```
