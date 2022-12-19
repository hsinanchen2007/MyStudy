```
function convertToTitle($n) {
    if($n<=0) return "";
    $s = "";
    while($n > 0){
        $n --;
        $s = chr(fmod($n,26) + 65).$s;
        $n = floor($n/26);
    }
    return $s;
}
```
