### 解题思路
1,关键是转换问题，找到和为（sum-S）/2的所有方法数。
2.分析数组中为零的情况，而再找动态规划dp值的依赖关系时，dp[i][j]=dp[i-1][j]+[i-1]dp[j-nums[i]]
    只与上一层有关系，nums[i]要么加上去，要么不加。
3.java中幂函数求解：(int)Math.pow(2,count)；
### 代码

```java
class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int sum=0,count=0;
        for(int num:nums){
            if(num==0){
                count++;
            }
            sum+=num;
        }
        if(nums.length==0||sum<S) return 0;
        if(sum==S){
            return (int)Math.pow(2,count);
        }
        if(((sum-S)&1)==1) return 0;
        int target=(sum-S)/2;
        int[] dp=new int[target+1];
        
        dp[0]=1;
        for(int i=0;i<nums.length;i++){
            
            for(int j=target;j>=nums[i];j--){
                dp[j]=dp[j]+dp[j-nums[i]];
            }
        }
        return dp[target];
    }
}
```