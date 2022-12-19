### 解题思路
单调栈的使用
只要求当前位置，与栈中比它小的点，他们之间构成的矩形
![QQ截图20200407162036.png](https://pic.leetcode-cn.com/91e4ca83943ed06d684928a3561066f4236afd14c0e944d1d1760459cdbd6b9c-QQ%E6%88%AA%E5%9B%BE20200407162036.png)


### 代码

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stk;
        for(int i = 0; i < height.size();i++)
        { 
            int last = 0;
            while(stk.size() && height[stk.top()] <= height[i])
            {
                int t = stk.top();
                stk.pop();
                res += (i - t - 1) * (height[t] - last);
                last = height[t];
            }
            if(stk.size()) res += (i - stk.top() - 1) * (height[i] - last);
            stk.push(i);
        }
        return res;
    }
};
```