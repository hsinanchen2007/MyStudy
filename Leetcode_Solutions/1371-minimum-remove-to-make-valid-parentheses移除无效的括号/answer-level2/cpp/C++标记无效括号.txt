***Talk is cheap. Show me the code.***
```
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                if (!stk.empty()) stk.pop();
                else s[i] = '#';
            };
        }
        while (!stk.empty()) {
            s[stk.top()] = '#';
            stk.pop();
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#') result.push_back(s[i]);
        }
        return result;
    }
};
```
