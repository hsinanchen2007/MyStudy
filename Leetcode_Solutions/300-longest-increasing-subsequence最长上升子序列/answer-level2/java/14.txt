### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] res=new int[nums.length];
        for(int i=0;i<nums.length;i++)
        {
            if(res[i]==0)
            {
                res[i]=1;
            }
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    res[i]=Math.max(res[j]+1,res[i]);
                }
            }
        }
        int max=0;
        for(int i=0;i<nums.length;i++)
        {
            max=max>res[i]?max:res[i];
        }
        return max;
    }
}
```