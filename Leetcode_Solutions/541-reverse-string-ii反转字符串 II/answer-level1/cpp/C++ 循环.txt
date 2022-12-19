```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (i + k <= n) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
            i += 2 * k;
        }
        return s;
    }
};
```