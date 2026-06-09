### 解题思路
O(n^2)用动态规划
O(nlogn)二分查找

### 代码

```java
class Solution {
    /*public int lengthOfLIS(int[] nums) {
        if(nums==null || nums.length==0)
        return 0;
        //dp[i]存储以Nums[i]为结尾的最长上升子序列
        int[] dp=new int[nums.length];
        Arrays.fill(dp,1);
        int max=0;
        for(int i=0;i<nums.length;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                dp[i]=Math.max(dp[i],dp[j]+1);
            }
            max=Math.max(max,dp[i]);
        }
        return max;
    }*/

    public int lengthOfLIS(int[] nums) {
        if(nums==null || nums.length==0)
        return 0;
        int[] tails=new int[nums.length];
        int res=0;
        for(int num:nums)
        {
            int l=0,r=res;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(tails[mid]<num)
                l=mid+1;
                else
                r=mid;
            }
            tails[l]=num;
            if(r==res)
            res++;
        }
        return res;
    }
}
```