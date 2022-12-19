解法： 栈

思路： 使用括号栈rm_stack， 记录“(”的下标。使用vector记录无效的括号下标rm_index。

1. 遇到“)”,  如果括号栈大小非空， 则栈pop。 即遇到了合理的括号对。
2. 遇到“)”,  如果括号栈大小为空， 则说明“）”无效，存储到rm_index中。
3. 遇到"(", 压入括号栈中。
4. 当遍历完数组，括号栈非空，说明是多出来的无效"(", 将下标存入rm_index.
5. 根据rm_index ， 重构有效的string

```
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> rm_index;
        vector<int> rm_stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                rm_stack.push_back(i);
            } else if (s[i] == ')') {
                if (rm_stack.empty()) {
                    rm_index.push_back(i);
                } else {
                    rm_stack.pop_back();
                }
            }
        }
        for (int i = 0; i < rm_stack.size(); i++) {
            rm_index.push_back(rm_stack[i]);
        }
        string res = "";
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < rm_index.size() && i == rm_index[j]) {
                j++;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
```
