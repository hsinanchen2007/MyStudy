```
class Solution {
public:
    int balancedStringSplit(const string& s) {
        int ans = 0, cnt = 0;
        for (const auto ch : s) {
            ch == 'L' ? ++cnt : --cnt;
            cnt == 0 ? ++ans : 0;
        }
        return ans;
    }
};
```
