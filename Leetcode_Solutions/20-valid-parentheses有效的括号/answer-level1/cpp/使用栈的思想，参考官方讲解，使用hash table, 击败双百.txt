class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        int table[128] = { 0 };
        table[')'] = '(';
        table['}'] = '{';
        table[']'] = '[';
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') { 
                mystack.push(s[i]); 
            }
            else {
                if (mystack.empty())return false;
                if (mystack.top() != table[s[i]]) return false;
                mystack.pop();
            } 
        }
        return mystack.empty();
    }
};