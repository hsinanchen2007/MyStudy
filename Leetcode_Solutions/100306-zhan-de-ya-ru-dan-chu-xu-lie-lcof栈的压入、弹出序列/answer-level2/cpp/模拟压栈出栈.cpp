### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0 && popped.size()==0)return true;
        if(pushed.size()==0 || popped.size()==0)return false;
        stack<int> st;
        int j = 0;  //popped的序号
        for(auto c : pushed)
        {
            st.push(c);  //首先压栈
            while(!st.empty() && j < popped.size() && st.top()==popped[j])
            {
                //短路求值
                //如果这三个条件同时满足，弹出栈顶
                st.pop();
                ++j;
            }
        }
        return st.empty();  //最后判断是否栈空，栈空则返回true
    }
};
```