### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        vector<int> res{-1,-1};
        if(!nums.size()) return res;
        while(right >= left) {
            int mid = (left + right) / 2;
            // 注意判断边界
            if(nums[mid] == target && (mid <=0 || nums[mid-1] != target)) res[0] = mid;
            // nums[mid] == target 时也向前搜索
            if(nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(res[0] == -1) return res;

        left = 0, right = nums.size()-1;
        while(right >= left) {
            int mid = (left + right) / 2;
            if(nums[mid] == target && (mid >= nums.size() - 1 || nums[mid+1] != target)) res[1] = mid;
            // nums[mid] == target 时也向后搜索
            if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};
```