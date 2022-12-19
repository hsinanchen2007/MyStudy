```
function minSubArrayLen($s, $nums) {
    $ans = PHP_INT_MAX;
    $left = 0;
    $sum = 0;
    for($i=0;$i<count($nums);$i++){
        $sum += $nums[$i];
        while($sum>=$s){
            $ans = min($ans,$i+1-$left);
            $sum -= $nums[$left++];
        }
    }
    return $ans==PHP_INT_MAX?0:$ans;
}
```
