### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string str;
        stack<string> stk;
        istringstream ss(s);
        while(ss>>str)stk.push(str);
        if(stk.empty())return "";
        str=stk.top();
        stk.pop();
        while(!stk.empty()){
            str+=" "+stk.top();
            stk.pop();
        }
        return str;
    }
};
```