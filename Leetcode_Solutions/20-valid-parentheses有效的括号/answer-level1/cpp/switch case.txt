### 解题思路


### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len=s.size();
        if(len%2!=0) return false;
        int i=0;
        while(s[i]!=NULL){
            switch(s[i]){
                case '(':
                     st.push(s[i]);break;
                case '[':
                     st.push(s[i]);break;
                case '{':
                     st.push(s[i]);break;
                case ')':
                    if(st.empty()) return false;
                     if(st.top()!='(') return false;
                     st.pop();
                     break;
                case ']':
                    if(st.empty()) return false;
                     if(st.top()!='[') return false;
                     st.pop();
                     break;
                case '}':
                    if(st.empty()) return false;
                    if(st.top()!='{') return false;
                    st.pop();
                    break;
            }
            i++;
        }
        if(!st.empty()) return false;
        else return true;
    }
};
```