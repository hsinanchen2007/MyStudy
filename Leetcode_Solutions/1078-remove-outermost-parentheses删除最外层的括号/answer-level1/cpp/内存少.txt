### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> primitive;
        string ret;
        for(char& s: S)
        {
            if(primitive.empty() && s=='('){
                primitive.push(s);
            }
            else if(!primitive.empty() &&s=='('){
                primitive.push(s);
                ret+=s;
            }
            else if(primitive.size()>1 && s==')'){
                primitive.pop();
                ret+=s;
            }
            else if(primitive.size()==1 && s==')')
                primitive.pop();
                
        }
        return ret;
    
    }
};
```