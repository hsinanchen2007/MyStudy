### 解题思路


### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int res = 1;
        int cnt = 1, pre = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == pre) {
                ++cnt;
                if (cnt <= 2) {
                    nums[res] = nums[i];
                    ++res;
                }
            } else {
                nums[res] = nums[i];
                cnt = 1;
                pre = nums[i];
                ++res;
            }
        }
        return res;
    }
};
```