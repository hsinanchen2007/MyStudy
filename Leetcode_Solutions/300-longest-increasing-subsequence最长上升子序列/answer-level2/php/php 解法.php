定义：dp[i] 表示以 nums[i] 这个数***结尾***的最长递增子序列的长度。
例如：
nums=[1,4,3,4,2]
dp[3]的值是3;
dp[4]的值是2;
```
function lengthOfLIS($nums) {
    if(count($nums)==0) return 0;
    $dp = array_fill(0,count($nums),1);
    for($i=0;$i<count($nums);$i++){
        for($j=0;$j<$i;$j++){
            if($nums[$i] > $nums[$j])
                $dp[$i] = max($dp[$i],$dp[$j]+1);
        }
    }
    return max($dp);
}
```
