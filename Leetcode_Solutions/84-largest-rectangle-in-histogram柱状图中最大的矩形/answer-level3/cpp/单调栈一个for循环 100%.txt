在heights中放入一个0，这样就可以将之前的单调序列都pop出来
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> sk;
        int area = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i ++) {
            while (!sk.empty() && heights[i] < heights[sk.top()]) {
                int top = sk.top();
                sk.pop();
                int w = sk.empty() ? i : i - sk.top() - 1;
                area = max(area, w * heights[top]);
            }
            sk.push(i);
        }
        return area;     
    }
};

```