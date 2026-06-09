```
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        int n = nums.length;
        if (n < 3) return 0;
        int ans = 0;
        Arrays.sort(nums);
        for (int i=n-1; i>=0; i--) {
            int k = target - nums[i];
            ans += find(nums, i-1, k);
        }
        return ans;
    }

    private int find(int[] nums, int ed, int k) {
        int l = 0, r = ed, ans = 0;
        while (l < r) {
            if (nums[l] + nums[r] >= k)
                r--;
            else {
                ans += r - l;
                l++;
            }
        }
        return ans;
    }
}
```