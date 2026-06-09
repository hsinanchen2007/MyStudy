
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stack;
        int max = 0;
        stack.push(-1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                stack.push(i);
            }else{
                stack.pop();
                if(stack.empty()){
                    stack.push(i);
                }else{
                    max = max > i - stack.top() ? max : i - stack.top();
                }
            }
        }
        return max;
    }
};
```