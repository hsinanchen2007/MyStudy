### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int massage(int[] nums) {
if(nums.length==0)
{
return 0;
}
int []dp = new int[nums.length];
for(int i = 0;i < nums.length;i++)
{
if(i==0){dp[i] = nums[i];}
else if(i==1)
{
dp[i] = Math.max(nums[0],nums[1]);
}
else
{
    dp[i] = Math.max(dp[i-1],nums[i] + dp[i-2]);
}
}
return dp[nums.length-1];
    }
}
```