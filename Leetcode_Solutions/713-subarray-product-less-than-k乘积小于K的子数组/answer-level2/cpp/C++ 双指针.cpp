```
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int N = nums.size();
        int left = 0;
        int res = 0;
        long mul = 1;
        for (int i = 0; i < N; ++i) {
            mul *= (long)nums[i];
            while (left <= i && mul >= k) {
                mul /= (long)nums[left];
                ++left;
            }
            res += i - left + 1;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/2468df58d0a8dc77e0d016eedce95750ea7999ea790549f218e1c7391031291f-image.png)

