```
function isOneEditDistance($s, $t) {
    $sn = strlen($s);
    $tn = strlen($t);
    if(abs($sn-$tn)>1) return false;
    $i = $j = 0;
    $dis = 0;
    while($i<$sn || $j<$tn){
        if($s[$i] != $t[$j]){
            $dis++;
            if($dis>=2) return false;
            if($sn < $tn){
                $j++;
                continue;
            }else if($sn > $tn){
                $i++;
                continue;
            }
        }
        $i++;
        $j++;
    }
    return $dis == 1;
}
```
