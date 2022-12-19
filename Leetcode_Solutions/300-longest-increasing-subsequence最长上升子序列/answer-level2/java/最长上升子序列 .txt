### 解题思路
1.dp动态规划，nums的长度是可变的，可找出不同长度下的最长子序列的依赖关系，dp[i]是i位置的最长子序     列数。
2.dp[i]是以I位置元素作为结尾，求其最大子序列数，以此判断i前边是否有小于nums[i]的数字，如果都没有，   则dp[i]=1;
3.然后求dp数组中的最大值即可。

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len=nums.length;
        if(nums==null||len<2) return len;
        int[] dp=new int[len];
        Arrays.fill(dp,1);
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=Math.max(dp[j]+1,dp[i]);
                }
                
            } 
              
        }
        int res=dp[0];
        for(int i=1;i<len;i++){
            res=Math.max(res,dp[i]);
        }
        return res;
    }
}
```