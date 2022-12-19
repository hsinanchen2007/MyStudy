```
function isStrobogrammatic($num) {
    $map['6'] = '9';
    $map['9'] = '6';
    $map['8'] = '8';
    $map['1'] = '1';
    $map['0'] = '0';
    $n = strlen($num);
    for($i=0;$i<$n;$i++){
        if(!isset($map[$num[$i]])) return false;
        if($map[$num[$i]] != $num[$n-1-$i]) return false;
    }
    return true;
}
```
