其实就是一个桶排序问题，每一个嵌套就是一次桶排序调整的过程，记录每次调整过程中交换的最大值，这个值加一就是最后的答案。
```
class Solution {
    public int arrayNesting(int[] nums) {
        int ans = 0;
        for(int i = 0;i < nums.length;i++)
        {
            int count = 1;
            while(nums[i]!=nums[nums[i]])
            {
                swap(nums,i,nums[i]);
                count++;
            }
            ans = Math.max(ans,count);
        }
        return ans;
    }
    
    private void swap(int[] nums,int i,int j)
    {
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }
}
```
