首先说一下单调栈，我也是刚接触这种数据结构，单调栈顾名思义就是栈内元素或元素所指的值单调递增或者单调递减，本题每一个元素的值为矩形的高，向左向右分别找到元素值第一个小于当前元素值的下标，以此确定宽的长度。求所有矩形的最大值即可。用一个单调递增栈来保存元素下标值，每当栈顶元素的值大于当前元素的值时，弹出栈顶元素，之后的栈顶元素就是要找的小于当前元素值的下标，以此类推可以找到每一个元素向左向右的第一个小于当前元素值的下标。
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);

        stack<int> stk;
        for(int i = 0;i<n;i++)
        {
            while(stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if(stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }
        while(stk.size()) stk.pop();
        for(int i = n-1;i>=0;i--)
        {
            while(stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if(stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }

        int res = 0;
        for(int i = 0;i<n;i++) res = max(res,heights[i] * (right[i] - left[i] - 1));

        return res;
    }
};
```
小白的表达能力不太好，欢迎在评论区批评指正。
