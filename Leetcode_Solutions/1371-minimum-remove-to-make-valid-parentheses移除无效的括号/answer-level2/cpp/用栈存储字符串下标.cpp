### 解题思路
用栈存储字符串下标

### 代码

```cpp
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //stack<char> s1;
        stack<int> s2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                //s1.push(s[i]);
                s2.push(i);
            }
            else if (s[i] == ')'&&!s2.empty()&&s[s2.top()]=='(') {//括号匹配则消去
                //s1.pop();
                s2.pop();
            }
            else if (s[i] == ')') {
                s2.push(i);
            }
            
        }
        while (!s2.empty()) {//栈中剩余的下表则为需要删去的括号
            s.erase(s2.top(), 1);
            s2.pop();
        }
        return s;
    }
};
```