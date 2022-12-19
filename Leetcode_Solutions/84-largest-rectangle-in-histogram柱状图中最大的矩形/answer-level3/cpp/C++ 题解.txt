思路和方法：
思路：取最大值的矩形的左右边界，如果不在边缘，那么边界两侧相邻柱子柱高一定小于边界的柱高
方法
1，从右往左遍历：
2，一单碰到右侧的柱高低于当前柱高，则从当前位置往左回溯，并更新结果
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        if (heights.size() == 1)
            return heights[0];
        int res = heights[0];
        int i = 1;
        while (i < heights.size()) {
            if (i < heights.size() - 1 && heights[i + 1] >= heights[i]) {
                ++i;
                continue;
            }
            int prev_height = heights[i];
            for (int j = i; j >= 0 && heights[j] > 0; --j) {
                if (heights[j] < prev_height)
                    prev_height = heights[j];
                if (prev_height * (i - j + 1) > res)
                    res = prev_height * (i - j + 1);
            }
            ++i;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d66eb88bfdc6aaba39c8dd635bab4fc2116f7b11ae395bfad32fc21b89a90fb7-image.png)
