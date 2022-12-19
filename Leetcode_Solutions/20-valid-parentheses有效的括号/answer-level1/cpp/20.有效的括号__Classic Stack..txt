HERYIX is here.

20.有效的括号

### 题目描述
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：
（1）左括号必须用相同类型的右括号闭合。
（2）左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

### 解题思路
经典**栈**问题。
使用vector模拟栈操作。

### 代码详解

```cpp
class Solution {
public:
    /*
        powered by Stack.
        C++: use vector simulate a classic Stack.
        Time Complexity: O(n), Space Complexity: O(1).
    */
    bool isValid(string s) {
        if (0 != s.size() % 2) { return false; }

        vector<char> stack;
        char c;
        for (int i = 0; i < s.size(); ++i) {            
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') { // char t = s[i];
                stack.push_back(s[i]);
            } else {
                if (stack.empty()) {
                    return false;
                } else {
                    c = stack[stack.size() - 1]; // c is element in Stack.
                }
                // Stack must be '(', '[', '{'.
                if (s[i] == ']' && c != '[') { return false; } // s is random, but c is cetained in the statck.
                if (s[i] == ')' && c != '(') { return false; }
                if (s[i] == '}' && c != '{') { return false; }

                stack.pop_back();
            }
        }

        return stack.empty(); // emtpy is TRUE.
    }
};
```