```C++ []
class Solution {
public:
    int minK(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int m = l + r >> 1;
        swap(nums[m], nums[r]);
        int i = l;
        int j = l;
        for (int j = l; j < r; ++j) {
            if (nums[j] < nums[r]) {
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i], nums[r]);
        if (i == k) return nums[i];
        if (i > k) return minK(nums, l, i - 1, k);
        return minK(nums, i + 1, r, k);
    }
    int minMoves2(vector<int>& nums) {
        int N = nums.size();
        int m = minK(nums, 0, N - 1, N >> 1);
        long res = 0;
        for (auto x : nums) {
            res += abs(x - m);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/5477f1a073e9e43c49fdd3db631db52e98eb38c83dec3c26a269281c976ce28d-image.png)
