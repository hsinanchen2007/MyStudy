```
function plusOne($digits) {
    for($i = count($digits) - 1 ; $i >= 0 ; $i --){
        $digits[$i] = $digits[$i] + 1;
        $digits[$i] = $digits[$i] % 10;
        if($digits[$i] !== 0) return $digits;
    }
    array_unshift($digits, 1);
    return $digits;
}
```
