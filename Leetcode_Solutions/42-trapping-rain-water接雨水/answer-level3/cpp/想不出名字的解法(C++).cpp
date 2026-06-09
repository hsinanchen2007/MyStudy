### 解题思路
- 用两个数组记录位置i左右侧的最高高度
- 若两侧最高高度的最小值大于height[i]，那么该位置可以装水(且可以装```min(left[i], right[i]) - height[i]```这么多水)
- 用时4ms，空间7.1MB

### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        // 两个数组记录位置i左右侧的最高高度
        vector<int> left_highest(height.size()), right_hightest(height.size());
        int max_height = 0;
        // 左侧最高高度
        for(int i = 0; i < height.size(); i++) {
            if(i == 0) left_highest[i] = 0, max_height = height[i];
            else {
                left_highest[i] = max_height;
                max_height = max(max_height, height[i]);
            }
        }
        // 右侧最高高度
        for(int i = height.size() - 1; i >= 0; i--) {
            if(i == height.size() - 1) right_hightest[i] = 0, max_height = height[i];
            else {
                right_hightest[i] = max_height;
                max_height = max(max_height, height[i]);
            }
        }
        // 遍历数组height, 看位置i是否可以装水，装多少水
        for(int i = 0; i < height.size(); i++) {
            int temp = min(left_highest[i], right_hightest[i]);
            if(temp > height[i]) ans += temp - height[i]; 
        }
        return ans;
    }
};
```