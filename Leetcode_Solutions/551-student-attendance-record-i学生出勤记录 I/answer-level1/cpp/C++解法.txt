```
class Solution {
public:
    bool checkRecord(string s) {
        int cnt = count(s.begin(), s.end(), 'A');
        if (cnt > 1) {
            return false;
        } else {
            if (count(s.begin(), s.end(), 'L') < 3) {
                return true;
            } else {
                return s.find("LLL") == string::npos;
            }
        }
    }
};
```
