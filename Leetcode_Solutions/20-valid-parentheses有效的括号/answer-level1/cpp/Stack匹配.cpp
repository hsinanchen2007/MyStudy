### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isMatch(char c1, char c2){
        if(c1 == '(' && c2 == ')')
            return true;
        if(c1 == '[' && c2 == ']')
            return true;
        if(c1 == '{' && c2 == '}')
            return true;
        return false;
    }
    bool isValid(string s) {
        if(s.length() == 0) return true;
        if(s.length() < 2) return false;

        stack<char> stk;
        int len = s.length();
        stk.push(s[0]);
        for(int i = 1; i < len; i++){
            if(stk.empty()){
                stk.push(s[i]);
                continue;
            }
            
            bool res = isMatch(stk.top(), s[i]);
            if(res == true){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
        if(stk.empty())
            return  true;
        return false;
    }
};
```