# 代码
```java
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int len = nums.length;
        int res = Integer.MAX_VALUE, count = 0;
        int[] copy_nums = Arrays.copyOf(nums, len);
        for (int i = 0; i < len; i += 2) {
            int cur_num = copy_nums[i];
            if (i > 0 && copy_nums[i - 1] >= cur_num) {
                count += copy_nums[i - 1] - cur_num + 1;
                copy_nums[i - 1] = cur_num - 1;
            }
            if (i + 1 < len && copy_nums[i + 1] >= cur_num) {
                count += copy_nums[i + 1] - cur_num + 1;
                copy_nums[i + 1] = cur_num - 1;
            }
        }
        res = Math.min(count, res);
        count = 0;
        for (int i = 1; i < len; i += 2) {
            int cur_num = nums[i];
            if (i > 0 && nums[i - 1] >= cur_num) {
                count += nums[i - 1] - cur_num + 1;
                nums[i - 1] = cur_num - 1;
            }
            if (i + 1 < len && nums[i + 1] >= cur_num) {
                count += nums[i + 1] - cur_num + 1;
                nums[i + 1] = cur_num - 1;
            }
        }
        return Math.min(res, count);
    }
}
```
