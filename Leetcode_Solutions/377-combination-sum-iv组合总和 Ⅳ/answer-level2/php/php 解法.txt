动态规划：
```
function combinationSum4($nums, $target){
    $n = count($nums);
    if($n<=0) return 0;
    $dp[0] = 1;
    for($i=1;$i<=$target;$i++)
        foreach($nums as $num)
            if($i-$num>=0) $dp[$i] += $dp[$i-$num];
    return isset($dp[$target])?$dp[$target]:0;
}
```
递归超时：
```
function combinationSum4($nums, $target){
    if($target == 0) return 1;
    $res = 0;
    for($i=0;$i<count($nums);$i++)
        if($target>=$nums[$i])
            $res += $this->combinationSum4($nums, $target-$nums[$i]);
    return $res;
}
```
