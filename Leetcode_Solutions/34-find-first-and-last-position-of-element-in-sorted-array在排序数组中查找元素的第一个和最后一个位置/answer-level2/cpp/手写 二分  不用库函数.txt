### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        if (nums.size() == 1) {
            if (nums[0] == target) return {0,0};
        }
        int l = 0,r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        int a = l;
        if(nums[l]!=target)return {-1,-1};
        l = 0,r =nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        int b = l;
        return {a,b};
    }
};
```