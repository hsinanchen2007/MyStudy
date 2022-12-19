循环比较相邻两个数的大小，如果索引i的数大于索引i+1的数的话，交换两个数的位置，并且计数器加一，不断遍历直到一次遍历中计数器不在变化（即这次遍历中没有交换发生）。
```
class Solution {
    public void sortColors(int[] nums) {
        int ans = swap(nums);
        while(ans!=0)
        {
            ans = swap(nums);
        }
    }
    
    public int swap(int[] nums)
    {
        int ans = 0;
        for(int i = 0;i < nums.length-1;i++)
        {
            if(nums[i] > nums[i+1])
            {
                int temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
                ans++;
            }
        }
        return ans;
    }
}
```
