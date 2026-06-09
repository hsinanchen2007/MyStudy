```
class Solution {
public:
    string defangIPaddr(string address) {
        const int n = address.length();
        string s(n+6,'0');
        for (int si = 0, i = 0; i < n; ++i) {
            if (address[i] == '.') {
                s[si++] = '[';
                s[si++] = '.';
                s[si++] = ']';
            } else {
                s[si++] = address[i];
            }
        }
        return std::move(s);
    }
};
```
