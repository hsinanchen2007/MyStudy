```
function rob($nums) {
    if(empty($nums)) return 0;
    $dp[0] = $nums[0];
    $dp[1] = max($nums[0],$nums[1]);
    for($i=2;$i<count($nums);$i++){
        $dp[$i] = max($nums[$i]+$dp[$i-2],$dp[$i-1]);
    }
    return $dp[count($nums)-1];
}
```
