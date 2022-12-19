第一种解法：
1,如果所有元素都不为0， 那么一定可以跳到最后；
2,从后往前遍历，如果遇到nums[i] = 0，就找i前面的元素j，使得nums[j] > i - j。如果找不到，则不可能跳跃到num[i+1]，返回false
```
function canJump($nums) {
    if(count($nums)>1 && $nums[0]==0) return false;
    for($i=count($nums)-2;$i>=0;$i--){
        if($i>0 && $nums[$i]==0){
            $ans = false;
            for($j=$i-1;$j>=0;$j--){
                if($nums[$j]>$i-$j){
                    $ans = true;
                }
            }
            if($ans == false) return false;
        }
    }
    return true;
}
```
第二种解法：贪心算法
```

function canJump($nums) {
    $lastPos = count($nums)-1;
    for($i=count($nums)-1;$i>=0;$i--){
            if($i+$nums[$i]>=$lastPos){
                    $lastPos = $i;
            }
    }
    return $lastPos == 0;
}
```
