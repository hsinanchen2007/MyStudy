```
class Solution {
public:
    string reverseWords(string s) {
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        if (s.empty()) return "";
        stack<string> sstack; s += " ";
        for (int i = 0, j = 1; j < s.length(); ) {
            if (s[i] == ' ' && (s[j] == ' ' || s[j] != ' ')) {
                i++; j++;
                continue;
            }
            if (s[i] != ' ' && s[j] != ' ') {
                j++;
                continue;
            }
            if (s[i] != ' ' && s[j] == ' ') {
                sstack.push(s.substr(i, j - i));
                i = j;
            }
        }
        string ans;
        while (!sstack.empty()) {
            ans += (sstack.top() + " ");
            sstack.pop();
        }
        ans.erase(ans.length() - 1);
        return ans;
    }
};
```
