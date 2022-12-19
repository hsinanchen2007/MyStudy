### 解题思路
大致思路是将nums[i]和i建立联系，最后找到nums[i]不等于i的那一项就好了。
有些特殊情况需要处理。

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            int target = nums[i];
            if (target != i && target > 0 && target < nums.size() && target != nums[target]) {
                nums[i] = nums[target];
                nums[target] = target;
                i--;
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums[0] == nums.size() ? nums.size() + 1 : nums.size();
    }
};
```