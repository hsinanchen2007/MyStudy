逻辑简单，代码如下：
```
class Solution {
public:
    int helper(vector<int>& nums, int l, int r, int k) {
        swap(nums[r], nums[l + (r - l) / 2]);
        int s = l;
        for (int f = l; f < r; ++f) {
            if (nums[f] > nums[r]) {
                swap(nums[s++], nums[f]);
            }
        }
        swap(nums[s], nums[r]);
        if (s + 1 == k) return nums[s];
        if (s + 1 > k) return helper(nums, l, s - 1, k);
        return helper(nums, s + 1, r, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size() - 1, k);
    }
};
```
![image.png](https://pic.leetcode-cn.com/d4cb41e5ccbb074b540de683cd4485cd5de8bb2a32310bc721401119baf19ff5-image.png)
