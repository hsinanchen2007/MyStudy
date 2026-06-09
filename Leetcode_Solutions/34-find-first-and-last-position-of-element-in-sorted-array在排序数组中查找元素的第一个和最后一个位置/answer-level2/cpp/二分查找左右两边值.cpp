### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() == 1 && nums[0] == target) return vector<int>{0, 0};
        find_pos(result, 0, nums.size() - 1, -1, target, nums);
        find_pos(result, 0, nums.size() - 1, 1, target, nums);
        
        return result.size() < 2 ? vector<int>{-1, -1} : result;

    }

    void find_pos(vector<int>& result, int start, int end, 
            int dir, int target, vector<int>& nums) {
        while (start < end) {
            int mid = (start + end) / 2;
            if (mid + dir >= 0 &&
                nums[mid] == target 
                && nums[mid] == nums[mid + dir]) {
                dir == 1 ? start = mid + 1 : end = mid;
            } else if (nums[mid] == target) {
                result.push_back(mid);
                break;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        if (start == end && nums[start] == target) result.push_back(start);
    }
};
```