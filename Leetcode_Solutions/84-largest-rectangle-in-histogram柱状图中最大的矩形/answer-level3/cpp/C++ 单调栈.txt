### 解题思路
这题和接水的一样，都可以使用单调栈进行解决。而且代码几乎都一样。。。

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) {
            return 0;
        } else if(heights.size() == 1) {
            return heights[0];
        } else {
            heights.emplace_back(0);
        }
        stack<int> sta;
        int res=0;
        heights.emplace_back(0);
        for (int i=0; i<heights.size(); i++) {
            if (sta.empty() || heights[i] >= heights[sta.top()] ) {
                sta.push(i);
            } else {
                int j = sta.top();
                sta.pop();
                res = max(res, heights[j] * (sta.empty() ? i : i - 1 - sta.top()));
                i--;
            }
        }
        return res;
    }
};
```