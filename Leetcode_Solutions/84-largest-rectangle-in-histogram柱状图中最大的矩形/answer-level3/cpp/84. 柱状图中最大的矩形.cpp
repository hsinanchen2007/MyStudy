方法一 暴力
分别计算以每个柱为高度的最大矩形，即向左向右移动找到对应的最大宽度。所能勾勒出来的矩形的最大面积是以最低的柱形为高度，因此向左向右移动时找比当前柱高的柱形。
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0)  return 0;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            // 找左边最后 1 个大于等于 heights[i] 的下标
            int left = i;
            int curHeight = heights[i];
            while (left > 0 && heights[left - 1] >= curHeight) {
                left--;
            }
            // 找右边最后 1 个大于等于 heights[i] 的索引
            int right = i;
            while (right < heights.size() - 1 && heights[right + 1] >= curHeight) {
                right++;
            }
            int width = right - left + 1;
            res = max(res, width * curHeight);
        }
        return res;
    }
};
```
方法二 栈
记录下标，若知道下标则能知道高度。
从左向右遍历，若新柱形比前一个低，那么以前一个柱形为高度的最大矩形可以确定
在输入数组的两端加上两个高度为 0 的柱形。
确定当前柱形对应宽度的左边界时，若遇到与当前柱高度相等的柱形可以当做不存在，因为它们对应的最大矩形是一样的。
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len=heights.size();
        if (len == 0)  return 0;
        int res = 0;
        heights.insert(heights.begin(),0);
        heights.emplace_back(0);
        stack<int> sk;
        len += 2;
        for (int i = 0; i < len; i++) {
            while (!sk.empty() && heights[i] < heights[sk.top()]) {
                int curHeight = heights[sk.top()];
                sk.pop();
                while (!sk.empty() && heights[sk.top()] == curHeight) {
                    sk.pop();
                }//向左存在与当前柱形高度相同的情况
                int curWidth = i - sk.top() - 1;
                res = max(res, curHeight * curWidth);
            }
            sk.push(i);
        }
        return res;
    }
};
```
