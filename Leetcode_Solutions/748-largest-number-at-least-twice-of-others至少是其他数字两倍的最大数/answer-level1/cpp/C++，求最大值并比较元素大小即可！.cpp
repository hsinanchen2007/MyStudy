### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_i = 0;

        // 1. 求最大值索引
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[max_i])
                max_i = i;
        }

        // 2. 判断是否存在 nums_max < 2 * n 的元素 n，如果存在则返回 -1
        for (int i = 0; i < nums.size(); i++) {
            if (i != max_i && nums[max_i] < 2 * nums[i])
                return -1;
        }

        return max_i;
    }
};
```