### 解题思路
反正0都是在最后，把不是0的排列在前逐个交换。

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j++]);
            }
        }
    }
};
```