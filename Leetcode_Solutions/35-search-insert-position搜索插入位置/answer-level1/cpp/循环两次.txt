### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0]) return 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < target) {
                if (i != nums.size() - 1 && nums[i + 1] >= target) {
                    return i + 1;
                }
            }
        }
        return nums.size();
    }
};
```