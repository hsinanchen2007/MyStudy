### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(auto i:s){
            if(check.empty()&&(i==')'||i==']'||i=='}'))
                return false;
            else if(i==')'&&check.top()=='(')
                check.pop();
            else if(i==']'&&check.top()=='[')
                check.pop();
            else if(i=='}'&&check.top()=='{')
                check.pop();
            else 
                check.push(i);
        }
        return check.empty();
    }
};
```