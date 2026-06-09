### 解题思路
栈括号匹配，易于理解。

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        vector<char> stack;
        stack.push_back(S[0]); //由于S不为空，初始将左括号压入栈中
        string ret;
        for(int i = 1 ;i < S.length();){
            if(S[i] == '('){
                stack.push_back(S[i]); //左括号入栈
            }else{
                stack.pop_back(); //右括号出栈
            }   
            if(!stack.empty()){
                ret.push_back(S[i++]); //栈不空，说明不是最外层
            }else{
                // 栈空，表明匹配到了一个完整的原语(*****)，若未到字符串末尾，将下一原语的左括号压入栈中
                // 同时将指针后移一位，继续匹配
                if(i + 1 < S.length()){ 
                    stack.push_back(S[++i]);
                    i++;
                }else{
                    break;
                }
            }
        }
        return ret;
    }
};
```