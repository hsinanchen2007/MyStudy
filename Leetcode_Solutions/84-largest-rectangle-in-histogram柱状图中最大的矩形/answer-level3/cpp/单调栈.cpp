### 解题思路
单调栈一般用来解决找到相对于当前位置的第一个满足某种关系的元素
单调队列一般用来解决在当前窗口中的最值
单调队列和单调栈实现的时候当前位置的元素都要push进去，pop的是当前位置之前的

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size());
        vector<int> right(heights.size());       
        stack<int> stk;
        for(int i = 0;i < heights.size();++i){
            while(!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            if(stk.empty())left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }
        while(!stk.empty())stk.pop();
        for(int i = heights.size()-1;i >= 0;--i){
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(stk.empty())right[i] = heights.size();
            else right[i] = stk.top();
            stk.push(i);
        }
        int res = 0;
        for(int i = 0;i < heights.size();++i){
            res = max(res,(right[i]-left[i]-1)*heights[i]);
        }
        return res;
    }
};
```