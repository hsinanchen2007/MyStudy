通过键值对map构建映射关系，若发现一对多的情况则false
```
function isIsomorphic($s, $t) {
    if(strlen($s)!=strlen($t)) return false;
    $map_s = [];
    $map_t = [];
    for($i=0;$i<strlen($s);$i++){
        $map_s[$s[$i]] = $t[$i];
        $map_t[$t[$i]] = $s[$i];
    }
    for($i=0;$i<strlen($s);$i++){
        if($t[$i] !== $map_s[$s[$i]] || $s[$i] !== $map_t[$t[$i]]){
            return false;
        }
    }
    return true;
}
```
