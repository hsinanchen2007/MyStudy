```
function getModifiedArray($length, $updates) {
    $arr = array_fill(0,$length,0);
    foreach($updates as $update){
        $start = $update[0];
        $end = $update[1];
        $val = $update[2];
        $arr[$start] += $val;
        if($length>$end+1)$arr[$end+1] -= $val;
    }
    for($i=1;$i<$length;$i++){
        $arr[$i] += $arr[$i-1];
    }
    return $arr;
}
```
