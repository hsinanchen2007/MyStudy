### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(0+heights.begin(), 0);
        heights.push_back(0);
        int res = 0;
        stack<int> s;
        for(int i=0; i<heights.size(); i++){
            while(s.size()!=0 && heights[s.top()] > heights[i]){
                int tmp = s.top();
                s.pop();
                res = max(res, (i - s.top() - 1) * heights[tmp]);
            }
            s.push(i);
        }
        return res;
    }
};
```