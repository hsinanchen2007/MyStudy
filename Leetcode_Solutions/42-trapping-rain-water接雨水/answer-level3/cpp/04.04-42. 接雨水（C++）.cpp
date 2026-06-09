### 解题思路
抄的

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {        
        int ans = 0;
        size_t size = height.size();
        if (size == 0) {
            return ans;
        }
        vector<int> left_max(size);
        vector<int> right_max(size);
        left_max[0] = height[0];
        for (size_t i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};
```