### 解题思路
维持一个存储数组下标的按高度非递减栈，
如果当前元素的高度小于等于栈顶下标对应的元素高度则当前下标入栈，
否则记录栈顶元素，出栈，判断当前元素高度与出站后栈顶元素对应下标的高度大小，取小的减去刚才出栈元素对应的高度，乘以当前元素与栈顶元素的间距（下标差），加入res，重复，直到当前元素小于栈顶元素对应高度或者栈为空，当前元素下标入栈。
ps：储水是横向向res中加的，间距*最小高度与区间最大高度差


### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int res=0;
        for(int i=0;i<height.size();i++)
        {
            while(!s.empty() && height[s.top()]<height[i])
            {
                int low=s.top();
                s.pop();
                if(!s.empty()) res+=(i-s.top()-1)*(min(height[i],height[s.top()])-height[low]);
            }
            if(s.empty() || height[s.top()]>=height[i]) s.push(i);
        }
        return res;
    }
};
```