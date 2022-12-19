### 解题思路
判断j是关键

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] == val ) {
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    ++i;
                }
                --j;
            } else {
                if (nums[j] == val) {
                    --j;
                }
                ++i;
            }
        }
        if (nums[j] == val) {
            return j;
        }
        return j+1;
    }
};
```