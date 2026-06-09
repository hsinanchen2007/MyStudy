```
function summaryRanges($nums) {
    if(empty($nums)) return [];
    $left = 0;
    $right = 0;
    $ans = [];
    for($right = 1;$right < count($nums); $right++){
        if($nums[$right]-$nums[$right-1]==1) continue;
        $ans[] = $right-1==$left?($nums[$left].""):($nums[$left]."->".$nums[$right-1]);
        $left = $right;
    }
    $ans[] = $right-1==$left?($nums[$left].""):($nums[$left]."->".$nums[$right-1]);
    return $ans;
}
```
