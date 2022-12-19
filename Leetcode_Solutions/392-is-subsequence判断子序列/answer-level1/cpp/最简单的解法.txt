```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0;
        for(auto c : t)
        {
            if(c == s[idx])
            {
                idx++;
            }
        }
        return idx == s.length();
    }
};
```