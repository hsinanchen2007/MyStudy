### 解题思路
优化：将连续相等的去掉

### 代码

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        if (nums.size() < 2) {
            return nums.size();
        }
        vector<int> vecHelp(nums.size(), 0);
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                vecHelp[i] = 1;
            } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                vecHelp[i] = -1;
            } else {
                continue;
            }
        }
        if (nums[0] > nums[1]) {
            vecHelp[0] = 1;
        } else {
            vecHelp[0] = -1;
        }
        if (nums[nums.size() -1] < nums[nums.size() - 2]) {
            vecHelp[nums.size() - 1] = -1;
        } else {
            vecHelp[nums.size() - 1] = 1;
        }
        int count = 0;
        int preValue = 0;
        for (int i : vecHelp) {
            if (i != 0 && preValue != i) {
                count++;
                preValue = i;
            }
        }
        return count;
    }
};
```