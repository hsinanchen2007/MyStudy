
```
function strStr($haystack, $needle) {
    $i=0;
    $j=0;
    while(isset($haystack[$i]) && isset($needle[$j])){
        if($haystack[$i] == $needle[$j]){
            $i++;
            $j++;
        }else{
            $i = $i - $j + 1;
            $j = 0;
        }
    }
    if($j==strlen($needle)){
        return $i-$j;
    }
    return -1;
}
```
