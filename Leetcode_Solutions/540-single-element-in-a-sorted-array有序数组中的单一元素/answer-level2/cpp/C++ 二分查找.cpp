```C++ []
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int N = nums.size() >> 1;
        int lo = 0;
        int hi = N;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid > 0 && nums[mid << 1] == nums[(mid << 1) - 1]) {
                hi = mid - 1;
            } else if (mid < N && nums[mid << 1] == nums[mid << 1 | 1]) {
                lo = mid + 1;
            } else {
                return nums[mid << 1];
            }
        }
        return 0;
    }
};
```

![image.png](https://pic.leetcode-cn.com/17eac52b65e445093a0928271e77a39464cfee5eb275f10743e2845ce3bc8b57-image.png)
