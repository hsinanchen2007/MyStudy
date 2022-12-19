### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int len=nums.length;
        if(len==0||len==1){
            return len;
        }
        int[] dp=new int[len];//新建一个长度为nums.length的数组，每个位置上的值即为从0                               //开始到该位置的最长递增子序列（爬台阶）
        dp[0]=1;
        int res=0;
        for(int i=1;i<len;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){//与之前的值逐一比较
                if(nums[i]>nums[j]){
                    dp[i]=Math.max(dp[i],dp[j]+1);
                }
            }
            res=Math.max(res,dp[i]);//记录最大递增值，即返回值
        }
        return res;
    }
}
```