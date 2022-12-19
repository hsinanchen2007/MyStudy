娱乐模式：
```
function reverseWords($s) {
    return implode(" ",array_reverse(array_filter(explode(" ",trim($s)))));
}
```
正常解法：
```
function reverseWords($s) {
    $s = trim($s);
    $s2 = "";
    $j = strlen($s);
    for($i=strlen($s)-1;$i>0;$i--){
        if($s[$i]===' '){
            $s2 .= substr($s,$i+1,$j-$i-1)." ";
            while($s[$i-1]===' ') $i--;
            $j = $i;
        }
    }
    $s2 .= substr($s,0,$j);
    return $s2;
}
```
