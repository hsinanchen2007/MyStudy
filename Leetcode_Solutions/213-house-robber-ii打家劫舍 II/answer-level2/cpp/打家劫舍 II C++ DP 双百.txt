### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int size = nums.size();
        if (size < 2) {
            return nums[0];
        }

        int res1 = 0, res2 = 0;
        int ppre1 = 0, pre1 = nums[0];
        int ppre2 = 0, pre2 = 0;
        for (int i = 1; i < size; i++) {
            int tmp;
            if (i < size - 1) {
                tmp = pre1;
                pre1 = max(pre1, ppre1 + nums[i]);
                ppre1 = tmp;
            }
            tmp = pre2;
            pre2 = max(pre2, ppre2 +nums[i]);
            ppre2 = tmp;
        }
        return max(max(pre1, ppre1), max(pre2, ppre2));
    }
};
```