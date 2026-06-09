### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    //每个柱子的位置雨水量，是他左右两侧最高的柱子的较小值与自己的差；不能为负，所以找左右两侧最高的柱子时范围包含自己；
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int wide = height.size();
        vector<int> left_max(wide), right_max(wide);
        int ans = 0;
        left_max[0] = height[0];
        for (int i = 1; i < wide; i++) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[wide - 1] = height[wide - 1];
        for (int i = wide - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        //0 和wide-1 其实不用累加，两侧柱子肯定没有雨水
        for (int i = 0; i < wide; i++) {
            ans += min(right_max[i], left_max[i]) - height[i];
        }
        return ans;
    }
};

```