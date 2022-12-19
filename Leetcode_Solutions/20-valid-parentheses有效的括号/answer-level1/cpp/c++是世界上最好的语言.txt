### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
     stack<char> my;  
     for(int i=0;i<s.size();i++){
         if(s[i]==' ')continue;
         else if(s[i]=='('||s[i]=='['||s[i]=='{') my.push(s[i]);
         else {
              if(my.empty()==true) return false;
              if(s[i]==')'){if(my.top()!='(')return false; my.pop();}
              if(s[i]=='}'){if(my.top()!='{')return false; my.pop();}
              if(s[i]==']'){if(my.top()!='[')return false; my.pop();}                    
              }
     return my.empty();
    }
};
```