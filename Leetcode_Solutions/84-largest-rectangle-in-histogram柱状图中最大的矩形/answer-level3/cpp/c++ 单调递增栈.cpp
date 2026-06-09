
### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /* 矩形面积：找到 heights[i] 的左右边界 \_ heights[i] _/
        边界定义：
              2   1   5   6   2   3
           -1   0   1   2   3   4   5  
        单调递增栈：确保右边界为 i-1
        */
        stack<int> s;
        s.push(-1);
        int res = 0, n = heights.size();
        for (int i = 0; i < n; ++i)
        {
            while (s.top() != -1 && heights[s.top()] >= heights[i])
            {
                int Hindex = s.top();
                s.pop();
                res = max(res, heights[Hindex] * (i - 1 - s.top()));
            }
            s.push(i);
        }
        while (s.top() != -1)
        {
            int Hindex = s.top();
            s.pop();
            res = max(res, heights[Hindex] * (n - 1 - s.top()));
        }
        return res;
    }
};
```