```
function plusOne($digits) {
    $n = count($digits);
    if($digits[$n-1]<9){
        $digits[$n-1]++;
        return $digits;
    }
    $carry = true;
    for($i=$n-1;$i>=0;$i--){
        if($carry && $digits[$i]==9){
            $digits[$i] = 0;
            if($i==0) array_unshift($digits,1);
        }else if($carry && $digits[$i]!=9){
            $digits[$i]++;
            $carry = false;
        }else{
            $carry = false;
        }
    }
    return $digits;
}
```
解法二换了另一个思路
代码减少了一些
```
function plusOne($digits) {
    $n = count($digits);
    for($i=$n-1;$i>=0;$i--){
        $digits[$i]++;
        $digits[$i] = fmod($digits[$i],10);
        if($digits[$i]!=0) return $digits;
    }
    array_unshift($digits,1);
    return $digits;
}
```

