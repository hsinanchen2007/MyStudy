### 解题思路
得到左右边界即可做

### 代码

```cpp
class Solution {
public:
    int left_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right){
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
    int right_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while(left <= right){
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
    bool isMajorityElement(vector<int>& nums, int target) {
        int l = left_bound(nums, target);
        int r = right_bound(nums, target);
        if(l == -1) return false;
        if(r - l + 1 > nums.size() / 2) return true;
        return false;
    }
};
```