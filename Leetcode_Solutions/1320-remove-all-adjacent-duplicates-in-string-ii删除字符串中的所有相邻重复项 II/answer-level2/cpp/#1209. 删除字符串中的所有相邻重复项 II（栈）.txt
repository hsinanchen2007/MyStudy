***Talk is cheap. Show me the code.***
```
class Solution {
public:
    string removeDuplicates(string s, int k) {
        string result;
        stack<pair<char, int>> stk;
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (!stk.empty() && stk.top().first == s[i]) {
                stk.top().second++;
                if (stk.top().second == k) {
                    stk.pop();
                }
            } else {
                stk.push(make_pair(s[i], 1));
            }
        }
        while (!stk.empty()) {
            auto && top = stk.top();
            result += string(top.second, top.first);
            stk.pop();
        }
        return result;
    }
};
```
![image.png](https://pic.leetcode-cn.com/c84397e49baec9cb620110c99c09590b90b412e3a613f0d29a9de416c39584cc-image.png)

