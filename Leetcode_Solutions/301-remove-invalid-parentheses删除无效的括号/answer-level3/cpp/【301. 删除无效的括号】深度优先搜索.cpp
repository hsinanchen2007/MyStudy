### 思路一
将给定字符串放入队列，取出队列中元素，如果合法，则加入结果集继续取出队列元素，否则，遍历给定字符串每个字符，如果是左右括号，则去除括号后生成新的字符串，如果新字符串没有在队列中出现过（使用set查看是否出现）则加入队列。

### 代码

```cpp
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited{{s}};
        queue<string> que{{s}};
        bool found = false;
        while (!que.empty()) {
            string t = que.front();
            que.pop();
            if (isValid(t)) {
                res.push_back(t);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < t.size(); ++i) {
                if (t[i] != '(' && t[i] != ')') continue;
                string str = t.substr(0, i) + t.substr(i + 1);
                if (!visited.count(str)) {
                    que.push(str);
                    visited.insert(str);
                }
            }
        }
        return res;
    }

    bool isValid(string str) {
        int cnt = 0;
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] == '(') ++cnt;
            else if (str[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }
};
```