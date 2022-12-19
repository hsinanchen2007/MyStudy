转ASCII值计算
```
function findTheDifference($s, $t) {
    $sum = 0;
    for($i=0;$i<strlen($t);$i++) $sum += ord($t[$i]);
    for($i=0;$i<strlen($s);$i++) $sum -= ord($s[$i]);
    return chr($sum);
}
```
