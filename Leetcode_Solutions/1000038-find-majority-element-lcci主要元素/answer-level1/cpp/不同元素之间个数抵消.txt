### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, pre = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                pre = nums[i];
                count = 1;
                continue;
            }

            count += pre == nums[i] ? 1 : -1;
        }

        if (count == 0) {
            return -1;
        }

        // 再次验证，避免[1,2,3]这类情况
        count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == pre) ++count;
        }
        
        return count >= (nums.size() / 2 + 1) ? pre : -1;
    }
};
```