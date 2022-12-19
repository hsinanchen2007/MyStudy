```
function hIndex($citations) {
    sort($citations);
    $n = count($citations);
    for($i=0;$i<$n;$i++){
        $h = $n-$i;
        if($citations[$i]>=$h) return $h;
    }
    return 0;
}
```
