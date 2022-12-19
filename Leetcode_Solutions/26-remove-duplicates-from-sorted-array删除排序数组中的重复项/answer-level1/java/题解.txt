数组遍历

```
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length < 1) {
            return 0;
        }
        int preValue = nums[0];
        int distinctCount = 1; 
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] == preValue) {
                continue;
            } else { 
                nums[distinctCount++] = nums[i];
                preValue = nums[i];
            }

        }
        return distinctCount;
    }
}
```
