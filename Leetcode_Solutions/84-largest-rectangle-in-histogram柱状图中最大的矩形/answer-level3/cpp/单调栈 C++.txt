
```C++ []
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;

        int cur = 0, ans = 0, len = heights.size();

        while (cur < len || !stk.empty()) {
            // 如果遍历时发现栈顶不小于当前高度 或者 已经遍历完但是栈非空，需要弹出并更新ans
            if (!stk.empty() && (cur == len || heights[stk.top()] >= heights[cur])) {
                int top = stk.top(); 
                stk.pop();
                // 如果栈空，此时矩形可以延伸到最左，宽度是cur，否则长度由栈顶的位置确定
                ans = max(ans, (stk.empty() ? cur : cur - stk.top() - 1) * heights[top]);
            } 
            // 遍历时维持栈递增
            else if (cur < len) stk.push(cur++);
        }

        return ans;
    }
};
```