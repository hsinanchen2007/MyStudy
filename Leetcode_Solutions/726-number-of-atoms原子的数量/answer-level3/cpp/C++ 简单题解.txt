```
class Solution {
public:
    bool isUpper(char c) { return c >= 'A' && c <= 'Z';}
    bool isLower(char c) { return c >= 'a' && c <= 'z';}
    bool isDigit(char c) { return c >= '0' && c <= '9';}
    map<string, int> parse(const string exp, int l, int r) {
        string atom;
        int count = 0;
        map<string, int> m;
        int i = l;
        while (i <= r) {
            char c = exp[i];
            if (isUpper(c)) {
                if (!atom.empty()) {
                    m[atom] += max(count, 1);
                    atom.clear();
                    count = 0;
                }
                atom += c;
            } else if (isLower(c)) {
                atom += c;
            } else if (isDigit(c)) {
                count *= 10;
                count += c - '0';
            } else if (c == '(') {
                if (!atom.empty()) {
                    m[atom] += max(count, 1);
                    atom.clear();
                    count = 0;
                }
                int tl = ++i;
                int bucket = 1;
                while (i <= r && bucket != 0) {
                    if (exp[i] == '(') ++bucket;
                    if (exp[i] == ')') --bucket;
                    if (bucket == 0) break;
                    ++i;
                }
                auto m1 = parse(exp, tl, i - 1);
                count = 0;
                while (i + 1 <= r && isDigit(exp[i + 1])) {
                    count *= 10;
                    count += exp[++i] - '0';
                }
                count = max(count, 1);
                for (auto& p : m1) {
                    m[p.first] += p.second * count;
                }
                count = 0;
            }
            ++i;
        }
        if (!atom.empty()) m[atom] += max(count, 1);
        return m;
    }
    string countOfAtoms(string formula) {
        auto m = parse(formula, 0, formula.size() - 1);
        string s;
        for (auto& p : m) {
            s += p.first;
            if (p.second > 1) {
                s += to_string(p.second);
            }
        }
        return s;
    }
};
```


![image.png](https://pic.leetcode-cn.com/4c3bac0b5da7c9f0319d58f8e837a92e41fd485c09223e5a1a521a3781b918b7-image.png)
