```
class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        if (nums == null || nums.length < 3) {
            return 0;
        }
        int ans = 0;
        Arrays.sort(nums);
        int len = nums.length;
        for (int i = 0; i < len - 2; i++) {
            int l = i + 1, r = len - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < target) {
                    //r可取l+1 ~ r个值，均满足sum < target
                    ans += r - l;
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
}
```
