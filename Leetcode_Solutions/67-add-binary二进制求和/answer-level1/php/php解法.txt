```
function addBinary($a, $b) {
    $an = strlen($a);
    $bn = strlen($b);
    while($an>$bn){
        $b = "0".$b;
        $bn++;
    }
    while($an<$bn){
        $a = "0".$a;
        $an++;
    }
    for($i=$an-1;$i>0;$i--){
        $a[$i] = $a[$i] + $b[$i];
        if($a[$i]>=2){
            $a[$i] = fmod($a[$i],2);
            $a[$i-1] = $a[$i-1]+1;
        }
    }
    $a[0] = $a[0] + $b[0];
    if($a[0]>=2){
        $a[0] = fmod($a[0],2);
        $a = "1".$a;
    }
    return $a;
}
```
