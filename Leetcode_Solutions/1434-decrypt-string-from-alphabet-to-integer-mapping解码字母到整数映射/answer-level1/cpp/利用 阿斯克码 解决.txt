### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int basic = '0', add = 'a' - '1', len_s = s.length();

        for (int i = len_s - 1; i >= 0; i--) {
            char c = s.at(i);

            if (c == '#') {
                c = s.at(--i);
                c += (s.at(--i) - basic) * 10;
                c += add;

                res.insert(res.begin(), c);
                continue;
            }

            c += add;
            res.insert(res.begin(), c);
        }

        return res;
    }
};
```