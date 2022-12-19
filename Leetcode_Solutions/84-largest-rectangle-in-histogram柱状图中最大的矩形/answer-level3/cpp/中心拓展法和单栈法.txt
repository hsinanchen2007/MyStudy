### 解题思路
单栈法的核心在于面积公式：
1. 遍历过程中的面积公式。当计算面积时，是发生了heights[i]<heights[s.top()]，即栈发生降序。此时，从s[top-1] (该写法不规范，指的是栈顶底下的一个元素) 到i，即(s[top-1],i)这段左开右开范围是heights[s.top()]的宽。面积公式为：curArea = (i-s[top-1]-1)*heights[s.top()]；
2. 结束时，栈内可能还有元素，且栈顶元素一定是最后一个元素即len-1。此时需要len充当上公式中的i，退栈直到栈顶为-1。

### 代码

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 以某个柱子为中心，向两边扩展
        // int len = heights.size();
        // if(len<1) return 0;
        // int res = INT_MIN;
        // int l,r;
        // int temp;
        // for(int i=0;i<len;i++){
        //     if(i>0&&heights[i]==heights[i-1]) continue;
        //     l = i;
        //     r = i;
        //     while(l>0&&heights[l-1]>=heights[i]) l--;
        //     while(r<len-1&&heights[r+1]>=heights[i])r++;
        //     res = max(res,(r-l+1)*heights[i]);
        // }
        // return res;
        
        // 使用栈 下标进栈
        int len = heights.size();
        if(len<1) return 0;
        int res = INT_MIN;
        stack<int> s;
        s.push(-1);
        int top;
        for(int i=0;i<len;i++){
            while(s.top()!=-1&&heights[i]<heights[s.top()]){
                top = s.top();
                s.pop();
                res = max(res,heights[top]*(i-s.top()-1));
            }
            s.push(i);
        }
        while(s.top()!=-1){
            top = s.top();
            s.pop();
            res = max(res,heights[top]*(len-s.top()-1));
        }
        return res;
    }
};
```