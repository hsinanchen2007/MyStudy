### 解题思路
开始用的方法都是只考虑一种情况，没有完全考虑栈的情况。。。

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        map<char,char> stack={{'(',')'},{'[',']'},{'{','}'}};
        vector<char> temp;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                temp.push_back(s[i]);
            }
            else
            {
                if (temp.size()<1 || stack[temp.back()]!=s[i])  return false;
                %这句话一定要放在前面，因为可能一开始就是右边括号；栈顶元素和当前s[i]不                 匹配的情况（还要注意，map中第一位是键值）
                temp.pop_back();
            }
        }
        if (!temp.empty()) return false;   
        return true; 
    }
};
```