```
class Solution {
    public int rob(int[] nums) {
        
        int n = nums.length;
        int[] res = new int[n];
        int ans;
        if(n == 0) {
            ans = 0;
        }
        else if(n == 1) {
            ans = nums[0];
        }
        else {
            res[0] = nums[0];
            res[1] = Math.max(nums[0], nums[1]);
            for(int i = 2; i < n; i++) {
                res[i] = Math.max((nums[i] + res[i - 2]), res[i - 1]);
            }
            ans = res[n - 1];
        }
        return ans;
    }
}
```
