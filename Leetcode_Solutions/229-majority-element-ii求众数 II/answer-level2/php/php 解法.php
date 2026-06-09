解法一：暴力法
```
function majorityElement($nums) {
    sort($nums);
    $e = $nums[0];
    $count = 1;
    $majorityCount = floor(count($nums)/3);
    $ans = [];
    for($i=1;$i<count($nums);$i++){
        if($nums[$i]==$e){
            $count++;
        }else{
            if($count>$majorityCount){
                $ans[] = $e;
            }
            $count = 1;
            $e = $nums[$i];
        }
    }
    if($count>$majorityCount){
        $ans[] = $e;
    }
    return $ans;
}
```
