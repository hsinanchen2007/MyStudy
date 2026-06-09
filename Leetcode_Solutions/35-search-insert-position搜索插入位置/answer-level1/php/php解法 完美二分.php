```
function searchInsert($nums, $target) {
    $start = 0;
    $end = count($nums) - 1;
    while($start<=$end){
        $mid = floor($start - ($start - $end)/2);
        if($nums[$mid]==$target){
            return $mid;
        }else if($nums[$mid]<$target){
            $start = $mid +1;
        }else if($nums[$mid]>$target){
            $end = $mid - 1;
        }
    }
    return $start;
}
```
