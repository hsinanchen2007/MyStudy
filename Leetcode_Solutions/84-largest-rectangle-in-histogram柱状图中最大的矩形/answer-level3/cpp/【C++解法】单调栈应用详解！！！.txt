首先考虑最大面积的矩形X的左右边界的性质：

设其左边界为L，右边界为R，则其高H = min{h[i] | L <= i <= R}

此时最大面积为 (R - L + 1) * H

若此时左边界的左边那个矩形的高度 h[L-1] >= H
则左边界可以向左拓展，则新的面积为：

(R - (L-1) + 1) * H > 原面积

则与原假设条件冲突

故左边界左边的那个矩形的高度 :h[L-1] < H
同理右边界右边的那个矩形的高度： h[R+1] < H

设H = h[i]

所以左边界L是满足h[j-1] < h[i]的最大的j，即从i点向左遍历的第一个高度比i小的点的右边一个点

而右边界R是满足 h[j+1] < h[i]的最小的j，即从i点向右遍历第一个高度比i小的点的左边一个点

所以我们可以利用单调栈的性质得到每个确定点，即确定高度的最大面积矩形的左右边界，然后枚举取最大即可。
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0,n = heights.size();
        if(!n) return 0;
        int L[n],R[n];
        memset(L,0,sizeof L);
        memset(R,0,sizeof R);
        stack<int> s;
        while(!s.empty()) s.pop();
        for(int i = 0;i < n;i ++){
            while(s.size() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) L[i] = 0;
            else L[i] = s.top() + 1;
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n - 1;i >= 0;i --){
            while(s.size() && heights[s.top()] >= heights[i]) s.pop();
            if(s.empty()) R[i] = n;
            else R[i] = s.top();
            s.push(i);
        }
        for(int i = 0;i < n;i ++) maxArea = max(maxArea,heights[i]*(R[i]-L[i]));
        return maxArea;
    }
};
```
