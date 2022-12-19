```
function findPeakElement($nums) {
    for($i=0;$i<count($nums);$i++){
        if($nums[$i]>$nums[$i+1]) return $i;
    }
    return count($nums)-1;
}
```
