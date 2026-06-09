### 解题思路
堆栈的经典例题

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n==0) return true;
        
        stack<char> stack;
        stack.push('0');
        for(int i=0;i<n;i++){
            if((s[i]=='}'&& stack.top()== '{')||(s[i]==']'&& stack.top()== '[')||(s[i]==')'&& stack.top()== '(')){
                stack.pop(); continue;} 
             stack.push(s[i]);
        }
        return (stack.size()==1)?true:false;
    }
};
```