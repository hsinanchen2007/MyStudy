### 解题思路
每次取出一个字符放在首位，然后剩下的字符全排列后拼接上第一个字符。
使用递归完成全排列操作。

### 代码

```cpp
class Solution {
public:
    set<string> do_permutation(string s) {
        if (s.size() == 0) {
            return {};
        }
        if (s.size() == 1) {
            return {s};
        }
        set<string> res;
        for (int i=0; i<s.size(); i++) {
            auto c = string(1, s[i]);
            auto s1 = s.substr(0, i) + s.substr(i+1, s.size() - 1 - i);
            auto r = do_permutation(s1);
            for (auto ss : r) {
                res.emplace(c + ss);
            }
        }
        return res;
    }

    vector<string> permutation(string s) {
        auto sset = do_permutation(s);
        return vector<string>(sset.begin(), sset.end());
    }
};
```