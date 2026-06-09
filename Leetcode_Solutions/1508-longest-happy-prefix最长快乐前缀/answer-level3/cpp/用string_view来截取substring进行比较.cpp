
直接substr会有内存问题，string_view 是只读的，不会进行复制，可以AC

```
class Solution {
public:
    string longestPrefix(string s) {
        if (s.empty() || s.size() == 1) {
            return "";
        }

        int res = 0;
        int n = s.size();
        for (int size = 1; size < n; size++) {
            if (string_view(s.c_str(), size) == string_view(s.c_str() + n - size, size)) {
                res = size;
            }
        }
        return s.substr(0, res);
    }
};
```
