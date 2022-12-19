```
function findMin($nums) {
    $left = 0;
    $right = count($nums)-1;
    while($left<=$right){
        $mid = $left + floor(($right - $left)/2);
        if($nums[$mid] > $nums[$right]){
            $left = $mid + 1;
        }else if($nums[$mid] < $nums[$right]){
            $right = $mid;
        }else{
            $right = $right - 1;
        }
    }
    return $nums[$left];
}
```
