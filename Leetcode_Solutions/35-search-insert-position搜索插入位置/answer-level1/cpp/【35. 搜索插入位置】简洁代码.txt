### 思路

### 代码

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] == target) {
                return i;
            } 
            if (target < nums[i]) {
                return i;
            }
        }
        return size;
    }
};
```