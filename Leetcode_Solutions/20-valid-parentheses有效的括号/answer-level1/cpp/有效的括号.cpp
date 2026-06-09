### 解题思路
首先判断字符串是否为空，如果为空，直接认为是有效字符串，返回true；然后利用stack的数据结构来解题。只要栈中的元素为空，就入栈，而且栈顶和目前的元素无法配对的时候，同样打入栈中。最后只需要判断栈中是不是为空就好了。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n == 0) return true;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(s[i]);
            }else if(st.top()=='('&&s[i]==')'||  
                     st.top()=='['&&s[i]==']'||  
                     st.top()=='{'&&s[i]=='}') {
                        st.pop();
                     }else {
                         st.push(s[i]);
                     }
        }
        return st.empty();
    }
};
```