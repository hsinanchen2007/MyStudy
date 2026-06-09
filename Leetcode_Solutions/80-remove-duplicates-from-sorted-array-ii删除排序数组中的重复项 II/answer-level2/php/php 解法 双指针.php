```
function removeDuplicates(&$nums) {
    $m = 0;
    for($i=0;$i<count($nums);$i++){
        if($m<2 || $nums[$m-2]!=$nums[$i]){
            $nums[$m] = $nums[$i];
            $m++;
        }
    }
    return $m;
}
```
