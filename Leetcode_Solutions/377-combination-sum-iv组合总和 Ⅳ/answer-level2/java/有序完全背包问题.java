### 解题思路
此处撰写解题思路
这种问题把nums摆在内轮，V摆在外轮，都是正序
### 代码

```java
class Solution {
    public int combinationSum4(int[] nums, int target) {
     int[] dp=new int[target+1];
        dp[0]=1;
        Arrays.sort(nums);
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.length&&i-nums[j]>=0;j++){
                dp[i]+=dp[i-nums[j]];
            }
        }
        return dp[target];
        
        
    }
}
```