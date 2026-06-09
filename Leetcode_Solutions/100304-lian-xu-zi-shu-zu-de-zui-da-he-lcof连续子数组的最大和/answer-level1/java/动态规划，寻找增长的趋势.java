### 解题思路
遍历过程中，sum的值和i有直接关系：
1.若sum <= 0；sum[i] = nums[i];
    只能重新开始，才有可能得到比sum更大的值，需要保存之前的sum：
        当nums[i] > 0;必然;
        当nums[i] < 0；保留sum与max的较大值；
2.若sum > 0;sum[i] = sum[i-1] + nums[i];
    跟新max的同时，继续增长，因为nums[i]加上一个正数总有增长的趋势：
        当nums[i]+sum > 0;继续增长；
        当nums[i]+sum <= 0;回到1，重新开始。
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        //设置sum的初值为分解点；
        int sum = 0;
        //从nums[0]开始更新max;    
        int max = nums[0];
        for(int i=0; i < nums.length; i++){
            if(sum <= 0){
                sum = nums[i];
            }else{
                sum += nums[i];
            }
            if(sum > max){
                max = sum;
            }
        }
        return max;
    }
}
```