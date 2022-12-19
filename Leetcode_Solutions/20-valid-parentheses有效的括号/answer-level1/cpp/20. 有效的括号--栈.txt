### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了66.28%的用户
内存消耗 :6.4 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        int n = s.size();
        stack<char> stack;
        for(int i = 0; i < n; i++){
            if(stack.empty()){
                stack.push(s[i]);
            }
            else{
                if((s[i] == ')' && stack.top() == '(') || (s[i] == ']' && stack.top() == '[') || (s[i] == '}' && stack.top() == '{')){
                    stack.pop();
                }
                else{
                    stack.push(s[i]);
                }
            }
        }
        if(stack.empty()) return true;
        return false;
    }
};
```