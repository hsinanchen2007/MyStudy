```
class Solution {
public:
    bool canPermutePalindrome(string s) {
        string input = s;
        sort(input.begin(), input.end());
        
        stack<char> charStack;
        for (string::const_iterator iter = input.begin();
            iter != input.end();
            ++iter) {
            if (charStack.empty()) {
                charStack.push(*iter);
                continue;
            }
            char current = charStack.top();
            if (current == *iter) {
                charStack.pop();  
                continue;
            }
            charStack.push(*iter);
        }
        return charStack.size() > 1 ? false : true;
    }
};
```
