### 解题思路
1. 在笔记一的基础上使用2个vector来存储当前柱子的 左最大高度 和 右最大高度
2. 时间复杂度为O(n)

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        // 动态编程，用数组存储到下标i的 左最大高度 和 右最大高度
        int ans = 0;
        int size = height.size();
        vector<int> left_size(size), right_size(size);
        
        left_size[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_size[i] = max(left_size[i - 1], height[i]);
        }

        right_size[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_size[i] = max(right_size[i + 1], height[i]);
        }

        for (int i = 1; i < size - 1; i++) {
            ans += min(left_size[i], right_size[i]) - height[i];
        }

        return ans;
    }
};
```