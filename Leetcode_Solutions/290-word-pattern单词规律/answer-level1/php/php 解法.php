```
function wordPattern($pattern, $str) {
    $n = strlen($pattern);
    $arr = explode(" ",$str);
    $count = count($arr);
    if($n != $count) return false;
    $map_p = [];
    $map_s = [];
    for($i=0;$i<$n;$i++){
        $map_p[$pattern[$i]] = $arr[$i];
        $map_s[$arr[$i]] = $pattern[$i];
    }
    for($i=0;$i<$n;$i++){
        if($map_p[$pattern[$i]] !== $arr[$i] || $map_s[$arr[$i]] !== $pattern[$i]){
            return false;
        }
    }
    return true;
}
```
