```
function maxSubArray($nums) {
    for($i=1;$i<count($nums);$i++)
        $nums[$i] = max($nums[$i],$nums[$i]+$nums[$i-1]);
    return max($nums);
}
```
