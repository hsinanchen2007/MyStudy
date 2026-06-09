```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream input(s);
        string val;
        int res = 0;
        while(input>>val) res = val.size();
        return res;
    }
};
```
