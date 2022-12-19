### 解题思路
原理很简单，但是细节要注意。首先，每次左符号入栈，右符号比较的时候要考虑栈是不是已经空了，这时候返回false；其次，所有符号遍历完，栈中还有数据，也返回false。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty())
                    if((s[i] == ')' && st.top() == '(')||(s[i] == '}' && st.top() == '{')||(s[i] == ']' && st.top() == '['))
                        st.pop();
                    else
                        return false;
                else
                    return false; 
            }
        }
        if(!st.empty())
            return false;

        return true;
    }
};
```