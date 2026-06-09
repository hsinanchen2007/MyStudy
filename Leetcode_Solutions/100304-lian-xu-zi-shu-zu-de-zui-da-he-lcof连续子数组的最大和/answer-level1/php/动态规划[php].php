### 解题思路
动态规划，状态转移方程为：
$dp[$i-1]<0 则 $dp[$i]=$nums[$i]
$dp[$i-1]>0 则 $dp[$i]=$nums[$i]+$dp[$i-1]

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxSubArray($nums) {
        $dp[0] = $nums[0];
        $max = $nums[0];
        for($i=1;$i<count($nums);$i++){
            if($dp[$i-1]<0){
                $dp[$i]=$nums[$i];
            }else{
                $dp[$i]=$nums[$i]+$dp[$i-1];
            }
            if($dp[$i]>$max){
                $max=$dp[$i];
            }
        }
        return $max;
    }
}
```