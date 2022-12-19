### 解题思路
定义dp数组,如果存在j<i,并且nums[j]<nums[i] 那么dp[i]=Math.max(dp[i],dp[j]+1);  dp[j]+1是因为把从nums[i]是nums[j]的下一个递增所以加1

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
       if(nums.length<=0){
           return 0;
       }
       int[]dp=new int[nums.length];
       for (int i = 1; i < nums.length; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }
       Arrays.sort(dp);
        //因为dp数组是每一个元素初始值是0,没有计算自己本身,所以最后需要加1
       return dp[dp.length-1]+1;
    }
}
```