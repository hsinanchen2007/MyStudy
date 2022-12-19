预处理一下使得满足 invariant f(l) >= nums[0] 满足即可
```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        while (n > 0 && nums[n - 1] == nums[0]) {
            --n;
        }
        int l = -1, r = n, m;
        while (r - l > 1) {
            m = (r + l) / 2;
            if (nums[m] >= nums[0]) {
                l = m;
            } else {
                r = m;
            }
        }
        return r == n ? nums[0] : nums[r];
    }
};
```