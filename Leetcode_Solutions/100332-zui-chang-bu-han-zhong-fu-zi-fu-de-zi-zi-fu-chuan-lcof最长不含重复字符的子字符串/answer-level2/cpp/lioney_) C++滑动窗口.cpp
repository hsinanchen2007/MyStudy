```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int left = 0, res = 0;
        for(int i=0; i<s.size(); i++) {
            if(!m.count(s[i])) {
                res = max(res, i-left+1);
            }
            else {
                for(int j=left; j<=m[s[i]]; j++) {
                    m.erase(s[j]);
                    left++;
                }
            }
            m[s[i]] = i;
        }
        return res;
    }
};
```
