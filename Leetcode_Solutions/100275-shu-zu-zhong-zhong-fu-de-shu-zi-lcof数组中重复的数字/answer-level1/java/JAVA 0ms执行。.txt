对于直接将对应的i值放到对应的nums[i]的位置。如果nums[i]==i，说明重复，直接返回i

代码：
```
class Solution {
    public int findRepeatNumber(int[] nums) {
        int sum = nums.length;
        int temp = 0;
        int j = 0;
       for (; j < sum; j++) {
            while (nums[j] != j) {
                if (nums[j] == nums[nums[j]]) {
                    return nums[j];
                }
                temp = nums[j];
                nums[j] = nums[temp];
                nums[temp] = temp;
            }
        }
        return 1;
    }
}
```
