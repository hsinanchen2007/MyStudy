### 解题思路
直接使用快速排序的写法就好

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = -1, j = 0;
        while (j < nums.size()) {
            if (nums[j] != 0)
                nums[++i] = nums[j];
            j++;
        }
        for (j = i + 1; j < nums.size(); j++)
            nums[j] = 0;
    }
};
```