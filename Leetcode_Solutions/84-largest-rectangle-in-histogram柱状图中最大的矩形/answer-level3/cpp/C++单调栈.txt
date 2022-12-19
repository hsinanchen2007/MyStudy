### 解题思路
单调栈

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        stack<int> monoStack;
        int m = heights[0];
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!monoStack.empty() && (heights[monoStack.top()] >= heights[i])) {
                int h = heights[monoStack.top()];
                monoStack.pop();
                int t = (i - (monoStack.empty() ? -1 : monoStack.top()) - 1) * h;
                m = m > t ? m : t;
            }
            monoStack.push(i);
        }
        return m;
    }
};
```