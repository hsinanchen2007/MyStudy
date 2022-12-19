```
function findMissingRanges($nums, $lower, $upper) {
    $lastlower = $lower;
    $ans = [];
    for($i=0;$i<count($nums);$i++){
        if($nums[$i] - $lastlower == 1){
            $ans[] = $lastlower."";
        }else if($nums[$i] - $lastlower > 1){
            $ans[] = $lastlower."->".($nums[$i]-1);
        }
        $lastlower = $nums[$i]+1;
    }
    if($upper>$lastlower){
        $ans[] = $lastlower."->".$upper;
    }else if($upper == $lastlower){
        $ans[] = $upper."";
    }
    return $ans;
}
```
