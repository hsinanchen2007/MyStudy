### 解题思路
此处撰写解题思路
首先我们要明白这是一个求最大不连续递增子序列的问题，注意是可以不连续，因为最近在学dp，所以就直接
拿dp做了，第一步我们要定义dp数组，我们要求的是最大的递增子序列问题，那我们就这dp[i]为数组i位的最
大递增子序列，然后我们开始找规律，dp[0]也就是10的最大递增子序列为1，dp[1]的递增子序列为1，可以如
下列出
dp[0]   10  1
dp[1]   9   1
dp[2]   2   1
dp[3]   2,5 2
从这里就可以看出一些规律了，5是大于2的，所以我们要求5的最大上升子序列，就等同于dp[i] = max(dp[k]+1)
得上升子序列，这里得k为arr[k]<arr[i]而且k<i得范围，状态转移方程就可以梳理出来了，然后看边界问题，dp[i]肯定默认是自己一个递增序列得第一位，所以默认肯定为1
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function lengthOfLIS($nums) {
        $dp = array();
        $len = 0;
        for($i=0;$i<count($nums);$i++){
            $dp[$i] = 1;
            for($k=0;$k<$i;$k++){
                if($nums[$i]>$nums[$k]){
                    $dp[$i] = max($dp[$i],$dp[$k]+1);
                }
            }
            $len = max($len,$dp[$i]);
        }
        return $len;
        
    }
}
```