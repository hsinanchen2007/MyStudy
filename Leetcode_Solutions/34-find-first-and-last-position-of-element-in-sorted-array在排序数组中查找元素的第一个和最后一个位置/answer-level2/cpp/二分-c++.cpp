### 解题思路
不说多了，感谢东哥，[实力题解](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/)！
### 代码

```cpp
class Solution {
public:
    //左边界
    int left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        if(left >= nums.size() || nums[left] != target) return -1;
        return left;
    }
    //右边界
    int right_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                left = mid + 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        if(right < 0 || nums[right] != target) return -1;
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) { 
        vector<int> ans(2, -1);
        if(nums.size() == 0) return ans;
        ans[0] = left_bound(nums, target);
        ans[1] = right_bound(nums, target);
        return ans;
    }
};
```