```
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        if (n == 0) return 1;
        boolean hasOne = false;
        for (int i=0; i<n; i++) {
            if (nums[i] == 1) hasOne = true;
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }
        if (!hasOne) return 1;
        for (int i=0; i<n; i++) {
            int pos = Math.abs(nums[i]) - 1;
            if (nums[pos] > 0) nums[pos] = -nums[pos];
        }
        int ans = n;
        for (int i=0; i<n; i++)
            if (nums[i] > 0) {
                ans = i; break;
            }
        return ans + 1;
    }
}
```
