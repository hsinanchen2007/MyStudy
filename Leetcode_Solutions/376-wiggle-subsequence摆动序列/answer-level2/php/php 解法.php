```
function wiggleMaxLength($nums) {
    if(count($nums)<2) return count($nums);
    $down = 1;
    $up = 1;
    for($i = 1;$i<count($nums); $i++){
        if($nums[$i]>$nums[$i-1]) $up = $down + 1;
        if($nums[$i]<$nums[$i-1]) $down = $up + 1;
    }
    return max($up,$down);
}
```
