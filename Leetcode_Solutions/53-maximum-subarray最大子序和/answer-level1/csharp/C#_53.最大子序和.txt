```
public class Solution {
    public int MaxSubArray(int[] nums) {
        int length = nums.Length;
        int sum = 0, ans = int.MinValue;
        for (int i = 0; i < length; i++) {
            // 以前累加是否有效
            sum = Math.Max(sum, 0);
            // 当前最大的累加值
            sum += nums[i];
            // 与answer进行比较，注意数据均为负数时比较（初始值设为最小值）
            ans = Math.Max(sum, ans);
        }
        return ans;
    }
}
```
