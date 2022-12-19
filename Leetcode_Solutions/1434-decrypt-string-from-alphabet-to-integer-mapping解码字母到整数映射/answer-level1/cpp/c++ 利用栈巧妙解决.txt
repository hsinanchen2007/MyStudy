### 解题思路
本题对数组做映射为字符，只在遇到'#'字符时，做特殊处理
1. j~z映射的字符串相等，故考虑将所有数字0-9映射为字符，当遇到'#'字符时，弹出之前的2个字符，压入正常的映射字符即可
### 代码

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        deque<char> dq;
        map<string, char> m;
        ostringstream oss;
        for (char c = 'j'; c <= 'z'; ++c) {
            oss << (int)(c - 'a' + 1) << '#';
            m[oss.str()] = c;
            oss.str("");
        }

        string tmp;
        for (int i = 0, sz = s.size(); i < sz; ++i) {
            if (s[i] != '#') {
                dq.push_back(s[i] - '1' + 'a');
            } else {
                dq.pop_back();
                dq.pop_back();
                tmp = string(s, i - 2, 3);
                dq.push_back(m[tmp]);
            }
        }
        return string(dq.begin(), dq.end());
    }
};
```