```
class Solution {
    public int findMin(int[] nums) {
        int len = nums.length;
        int res = Math.min(nums[0],nums[len-1]); //考虑只有一个元素和升序的情况
        for (int i = 0; i < len - 1; i++)
        {
            if (nums[i] > nums[i+1])
            {
                res = nums[i+1];
                break;
            }
        }
        return res;
    }
}
```
