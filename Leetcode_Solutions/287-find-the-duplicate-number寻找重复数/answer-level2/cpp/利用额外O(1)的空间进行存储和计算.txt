### 解题思路

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> helpVec(nums.size(), 0);
        for (int n : nums) {
            if (helpVec[n] == 1) {
                return n;
            }
            helpVec[n] = 1;
        }
        return 0;
    }
};
```