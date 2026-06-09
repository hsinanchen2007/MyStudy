```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{')
                st.push(ch);
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (st.empty()) return false;
                if (st.top() == '(' && ch == ')') st.pop();
                else if (st.top() == '[' && ch == ']') st.pop();
                else if (st.top() == '{' && ch == '}') st.pop();
                else return false;
            }
        }
        if (st.empty()) return true;
        else return false;
    }
};
```