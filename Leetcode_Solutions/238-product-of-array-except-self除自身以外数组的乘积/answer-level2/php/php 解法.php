```
function productExceptSelf($nums) {
    $k = 1;
    $n = count($nums);
    $res = array_fill(0,$n,1);
    for($i=0;$i<$n;$i++){
        $res[$i] *= $k;
        $k *= $nums[$i];
    }
    $k = 1;
    for($i=$n-1;$i>=0;$i--){
        $res[$i] *= $k;
        $k *= $nums[$i];
    }
    return $res;
}
```
