### 解题思路
直接递归即可。

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }
        return dfs(heights, 0, heights.size() - 1);
    }
    int dfs(vector<int>& heights, int begin, int end) {
        if (begin == end) {
            return heights[begin];
        }
        if (begin > end) {
            return 0;
        }
        int minHeight = INT_MAX;
        int minIndex = 0;
        for (int i = begin; i <= end; i++) {
            if (minHeight > heights[i]) {
                minHeight = heights[i];
                minIndex = i;
            }
        }
        return max(minHeight * (end - begin + 1), max(dfs(heights, begin, minIndex - 1), dfs(heights, minIndex + 1, end)));
    }
};
```