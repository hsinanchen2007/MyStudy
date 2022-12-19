### 解题思路
如何枚举所有情况？
枚举所有柱形的上边界，作为整个矩形的上边界。然后求出左右边界。
然后求出左右边界：
        1.找出左边离它最近的，比它小的柱形
        2.找出右边离它最近的，比它小的柱形
### 代码

```cpp
class Solution {
public:
    /*

    */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n),right(n);
        stack<int>stk;
        for(int i = 0; i < n; i++)
        {
            while(stk.size() && heights[stk.top()] >= heights[i]) stk.pop();//栈不空，栈顶若大于上边界，弹出
            if(stk.empty())left[i] = -1;//栈若为空，说明左边一直到边界都没有最小的，令其值为 -1. 最小为0
            else left[i] = stk.top();//栈不为空，说明左边找到边界最小，即栈顶
            stk.push(i);//压入当前值
        }
        while(stk.size())stk.pop();
        for(int i = n - 1; i >= 0; i--)
        {
            while(stk.size() && heights[stk.top()] >= heights[i])stk.pop();
            if(stk.empty())right[i] = n;//栈若为空，说明右边一直到边界都没有最小的，令其值为n，最大为n
            else right[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++)res = max(res, heights[i] * (right[i] - left[i] - 1));//n - (-1) -1 最大长度为n
        return res;
    }
};
```