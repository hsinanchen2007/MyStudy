### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int nums_length=nums.length;
        if(nums_length==0) return 1;
        for(int i=0;i<nums_length;i++)
        {
            if(nums[i]>0&&nums[i]<=nums_length)
            {
                
                if(nums[i]==i+1) continue;
                int temp=i;
                while(nums[temp]>0&&nums[temp]<=nums_length)
                {
                    if(nums[temp]==temp+1) break;
                    if(nums[nums[temp]-1]==nums[temp]) break;
                    int nums_value=nums[nums[temp]-1];
                    nums[nums[temp]-1]=nums[temp];
                    nums[temp]=nums_value;

                }
            }

        }

        for(int i=0;i<nums_length;i++)
        {
            if(nums[i]!=i+1) return i+1;
        }
        return nums_length+1;
    }
}
```