### 解题思路
使用c表示重复元素个数
- 如果前后元素不相等，则更新新元组指针，然后重置c为1；
- 如果前后元素相等，且重复元素出现次数为1，则继续更新新元组指针，否则什么也不做。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i, j, c = 1;
        for (i = 0, j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
                c = 1;
            } else {
                if (c == 1) {
                    nums[++i] = nums[j];
                    ++c;
                }
            }
        }
        return i + 1;
    }
};
```