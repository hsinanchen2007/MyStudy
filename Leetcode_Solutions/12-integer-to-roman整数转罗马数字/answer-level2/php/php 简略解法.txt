```
function intToRoman($num) {
    $value = [1000,900,500,400,100,90,50,40,10,9,5,4,1];
    $str = ['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I'];
    $roman = '';
    for($i=0;$i<count($value);$i++){
        $a = floor($num/$value[$i]);
        for($j=$a;$j>0;$j--) $roman .= $str[$i];
        $num -= ($a*$value[$i]);
    }
    return $roman;
}
```
