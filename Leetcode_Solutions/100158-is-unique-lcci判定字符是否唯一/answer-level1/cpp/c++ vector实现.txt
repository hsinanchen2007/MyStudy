
```
class Solution {
public:
    bool isUnique(string astr) {
        vector<char> m(128, 0);
        for (auto c: astr) {
            if (m[c - 'a'] == 0) {
                m[c-'a'] =1;
            } else {
                return false;
            }
        }
        return true;
    }
};
```
