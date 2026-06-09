![image.png](https://pic.leetcode-cn.com/bb65db63892661c950549f2fcc59febf0e8e17be90d660972ea9a863b0b9cd08-image.png)

遍历字符串
- ([{ 前括号直接入栈
- )]} 栈不空的情况下,后括号的前一个不是与之对应 返回false, 返回将栈中对应的出栈
最后栈不空返回false

```c
class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        map<char,char> corresp;
        corresp['}']='{';
        corresp[']']='[';
        corresp[')']='('; 
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push_back(s[i]);
            else{
                if(st.size()<1||corresp[s[i]]!=st.back()) return false;        
                st.pop_back();               
            }            
        }
        if(!st.empty()) return false;
        return true;
    }
};
```
