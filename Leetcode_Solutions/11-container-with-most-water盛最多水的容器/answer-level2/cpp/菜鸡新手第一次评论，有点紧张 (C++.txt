### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int lower_leg = 0;
        
        for (auto left = height.begin(); left != height.end(); ++left) {
            for (auto right = height.end() - 1; right != left; --right) {
                lower_leg = (*left > *right) ? *right : *left;
                if (lower_leg * (right - left) > max_area)
                    max_area = lower_leg * (right - left);
            }
        }
        return max_area;
    }
};
```