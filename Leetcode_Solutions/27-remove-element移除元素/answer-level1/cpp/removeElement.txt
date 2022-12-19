### 解题思路
4 ms, 在所有 C++ 提交中击败了79.48%的用户
双指针实现
### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j] != val)
                    {
                        nums[i] = nums[j];
                        nums[j] = val;
                        len = i;
                        break;
                    }
                }
            }
            else
            {
                len = i;
            }
        }
        return len + 1;
    }
};
```