temp用来计数当前最大递增；
当当前最大递增中断时，判断是否需要用temp覆盖result，判断后temp重置；
若连续递增，在循环外判断一次result是否需要更新

```
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int length = nums.length;
        int result = 1;
        int temp   = 1;
        
        if(length==0){return 0;}
        
        for(int i=0; i<length-1; i++)
        {
            if(nums[i+1]>nums[i])
            {
                temp++;
            }
            else
            {
                if(temp > result)
                {
                    result = temp;
                }
                temp = 1;
            }
        }
        
        if(temp > result)
            {
                result = temp;
            }
        
        return result;
        
    }
}
```
