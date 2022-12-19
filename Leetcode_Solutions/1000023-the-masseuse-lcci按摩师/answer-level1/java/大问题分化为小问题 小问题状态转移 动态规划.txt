### 解题思路
将大问题分化为小问题 小问题的结果状态转移累加结果 直到解决大问题
if(null==nums||nums.length==0) return 0; 
if(nums.length==1) return nums[0];
if(nums.length==2) return Math.max(nums[0],nums[1]);
划分子问题状态：
dp0=nums[0],dp1=num[1];
dp0=max(dp1,dp0),dp1=dp0+num[i];
                
dp[i]=max(dp[i-2]+num[i],num[i-1])
### 代码

```java
class Solution {
    /**
    ** 将大问题分化为小问题 小问题的结果状态转移累加结果 直到解决大问题
    ** 
    **比较 i-1 选取 和i-2选取加上当前i选取的值 如：i=2 dp0=num[0]=num[i-2], dp1=max(num[1],dp0)
    **相邻不能选取 所以隔一个,当前是i 所以选i 不能选 i-1 或者选i-1时 比较dp0+num[i] 
    **      dp0=tdp0;
    **      dp1=tdp1;  保留上一个状态 用于下一次计算
    *1态->dp0=num[0]=2 dp1=num[1]=7 接num[1] 
    *2态->tdp0=max(dp1,dp0)=7 ,tdp1=dp0+num[2]=2+9=11,dp0=tdp0 dp1=tdp1 num0+num2和dp0比 转移到dp0
    *3态->tdp0=max(dp1,dp0)=11,tdp1=dp0+num[3]=7+3=10,dp0=tdp0 dp1=tdp1 num1+num3和dp0比 转移到dp0
    *4态->tdp0=max(dp1,dp0)=11 ,tdp1=dp0+num[4]=11+1=12  dp0=tdp0 dp1=tdp1
    * return max(dp0,dp1)
    **/
    public int massage(int[] nums) {
        if(null==nums||nums.length==0) return 0;
        if(nums.length==1) return nums[0];
        if(nums.length==2) return Math.max(nums[0],nums[1]);
        int dp0=nums[0];
        int dp1=nums[1];
        int len=nums.length;
        
        for(int i=2;i<len;i++){
            int tdp0=Math.max(dp1,dp0);
            int tdp1=dp0+nums[i];
            dp0=tdp0;
            dp1=tdp1;
        }
        return Math.max(dp0,dp1);
    }
}
```