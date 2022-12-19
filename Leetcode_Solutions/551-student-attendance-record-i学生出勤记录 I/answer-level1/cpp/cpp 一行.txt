```
class Solution {
public:
    bool checkRecord(string s) {
        return s.find('A', s.find('A') + 1) == -1 && s.find("LLL") == -1;
    }
};
```
