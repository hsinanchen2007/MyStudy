执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户
# 思路
将如果字符串中的括号为左括号或者为右括号且此时栈为空时，将此字符压入栈中，如果是右括号，就看栈顶字符与当前字符是否匹配
```
class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char> st;
        int i=0;
        st.push(s[i++]);
        while(i<s.size()){
            if((s[i]=='('||s[i]=='['||s[i]=='{')||((s[i]==')'&&st.empty()))||((s[i]==']'&&st.empty()))||((s[i]=='}'&&st.empty())))
                st.push(s[i]);
            else if(s[i]==')'){
                if(st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]==']'){
                if(st.top()=='[')
                    st.pop();
                else
                    return false;
            }
            else if(s[i]=='}'){
                if(st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            i++;
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};
```
第一个完全自己做的双百，发个题解开心一下