### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() == 0 && popped.size() == 0)return true;  //两个序列都为空
        if(pushed.size() == 0 || popped.size() == 0)return false;  //只有一个序列为空
        stack<int> st;
        int j = 0;  //用于popped的index
        for(auto c : pushed)
        {
            //首先压栈
            st.push(c);
            while(!st.empty() && j < popped.size() && st.top() == popped[j])
            {
                //栈非空才能出栈
                //j<popped.size()才能判断是否越界
                //st.top()==popped[j]才能判断是否能出栈
                st.pop();  //出栈
                ++j;  //指向下一个popped的值
            }
        }
        return st.empty();  //最后判断是否栈空
    }
};
```