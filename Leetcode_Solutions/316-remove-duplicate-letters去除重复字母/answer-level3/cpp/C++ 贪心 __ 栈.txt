## 思路一 贪心

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<char> tl;
        for (const auto c : s) {
            tl.insert(c);
        }
        const int size = tl.size();
        string ret(size, ' ');
        auto ss = s.size();
        for (int i = 0; i < size; i++) {
            for (auto c : tl) {
                auto pos = s.find(c);
                if (pos == s.npos)
                    cout << "npos!" << endl;
                unsigned long long mask = 0ULL;
                for (int i = 0; i < pos; i++)
                    mask |= 1 << (s[i] - 'a');
                for (int i = pos + 1; i < ss; i++)
                    mask &= ~(1 << (s[i] - 'a'));
                if (!mask) {
                    ret[i] = c;
                    int new_size = 0;
                    for (int i = pos + 1; i < ss; i++) {
                        if (s[i] != c && !(new_size > 1 && s[new_size - 1] == c)) {
                            s[new_size++] = s[i];
                        }
                    }
                    tl.erase(c);
                    ss = new_size;
                    break;
                }                
            }
        }
        return std::move(ret);
    }
};
```

## 思路二 栈 （看人别人题解之后写的）

```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[256] = {0};
        const int size = s.size();
        for (int i = 0; i < size; i++) {
            last[s[i]] = i;
        }
        bool vs[256] = {false};
        string ret(26, ' '); // 存储结果 && 充当栈使用
        int ret_size = 0;
        for (int i = 0; i < size; i++) {
            const auto c = s[i];
            if (vs[c])
                continue;
            while (ret_size && ret[ret_size - 1] > c && last[ret[ret_size - 1]] > i) {
                vs[ret[ret_size - 1]] = false;
                ret_size--;
            }
            ret[ret_size++] = c;
            vs[c] = true;
        }
        
        ret.resize(ret_size);
        return std::move(ret);
    }
};
```