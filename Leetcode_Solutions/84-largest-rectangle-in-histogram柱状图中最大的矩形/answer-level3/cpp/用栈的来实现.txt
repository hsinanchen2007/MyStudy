### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int sum = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); ++ i) {

            if (s.empty() || heights[i] > heights[s.top()]) s.push(i);

            else {
                int tmp = s.top();
                s.pop();
                sum = max(sum, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
                -- i;
            }
        }

        return sum;
    }
};
```

