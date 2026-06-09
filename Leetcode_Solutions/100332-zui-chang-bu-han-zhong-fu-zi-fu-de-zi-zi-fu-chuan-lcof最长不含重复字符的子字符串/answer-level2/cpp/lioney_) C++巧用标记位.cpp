```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int left = 0, res = 0;
        for(int i=0; i<s.size(); i++) {
            if(m.count(s[i])) 
                left = max(left, m[s[i]] + 1);
            m[s[i]] = i;
            res = max(res, i-left+1);
        }
        return res;
    }
};
```
