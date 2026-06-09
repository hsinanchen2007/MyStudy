class Solution {
public:
    
    bool isValid(string s) {
        stack<char> stack1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack1.push('(');
            } else if (!stack1.empty() && stack1.top() == '(') {
                stack1.pop();
            } else {
                return false;
            }
        }
        return stack1.empty();
    }
    int longestValidParentheses(string s) {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j+=2) {
                if (isValid(s.substr(i, j))) {
                    maxlen = max(maxlen, j - i);
                }
            }
        }
        return maxlen;
    }
};


