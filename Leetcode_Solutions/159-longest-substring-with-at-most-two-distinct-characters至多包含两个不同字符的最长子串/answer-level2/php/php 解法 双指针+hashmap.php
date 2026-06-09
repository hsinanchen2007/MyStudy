```
function lengthOfLongestSubstringTwoDistinct($s) {
    $n = strlen($s);
    if($n<=2) return $n;
    $map = [];
    $len = 2;
    $j = 0;
    for($i=0;$i<$n;$i++){
        $map[$s[$i]] = isset($map[$s[$i]]) ? $map[$s[$i]]+1 : 1;
        while(count($map)>2){
            $map[$s[$j]]--;
            if($map[$s[$j]] == 0) unset($map[$s[$j]]);
            $j++;
        }
        if(count($map)<=2){
            $len = max($len,array_sum($map));
        }
    }
    return $len;
}
```
