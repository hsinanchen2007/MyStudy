***Talk is cheap. Show me the code.***
```
class Solution {
public:
    bool isValid(string S) {
        stack<char> stk;
        for (char c : S) {
            if (c != 'c') {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != 'b') return false;
                stk.pop();
                if (stk.empty() || stk.top() != 'a') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};
```
![1107.png](https://pic.leetcode-cn.com/5f0d0391c2721f2faca267e6cafd7dec20dfefc8a2cdea20ec83c5e05cf5080f-1107.png)

