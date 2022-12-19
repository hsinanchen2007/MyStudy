模拟编辑，遇到 # 删除尾部字符。

输出的时候，按照顺序输出即可。

```c++
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return edit(s) == edit(t);
    }
    
    string edit(const string& s) {
        std::deque<char> dq;
        for (auto c : s) {
            if (c == '#') {
                if (!dq.empty()) dq.pop_back();
            } else {
                dq.push_back(c);
            }
        }
        return string(dq.begin(), dq.end());
    }
};
```
