### 解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int len = 1;
        int i = 1;
        while(i < nums.size())
        {
            if(nums[i] == nums[len - 1])
            {
                ++i;
                continue;
            }
            nums[len++] = nums[i];
        }
        return len;
    }
};
```