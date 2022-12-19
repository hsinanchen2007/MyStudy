### 解题思路
执行用时：4 ms,击败了81.00%
内存消耗：8.7 MB,击败了100.00%
我发现栈在节省空间方面十分有用

### 代码

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> start = {};
        stack<int> need_deleted = {};
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                start.push(i);
                need_deleted.push(i);
            }
            if(s[i] == ')')
            {
                reverse(s.begin()+start.top()+1, s.begin()+i);
                start.pop();
                s.erase(s.begin()+i);
                s.erase(s.begin()+need_deleted.top());
                need_deleted.pop();
                i = i - 2;
            }
        }
        return s;
    }
};
```