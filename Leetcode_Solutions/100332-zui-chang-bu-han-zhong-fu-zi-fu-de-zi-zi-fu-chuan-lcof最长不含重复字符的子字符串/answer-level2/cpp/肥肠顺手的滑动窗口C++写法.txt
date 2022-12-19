
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int l = 0, res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
            while(m[s[i]] > 1)
                m[s[l++]]--;
            res = max(res, i - l + 1);
        }
        return res;
    }
};
```