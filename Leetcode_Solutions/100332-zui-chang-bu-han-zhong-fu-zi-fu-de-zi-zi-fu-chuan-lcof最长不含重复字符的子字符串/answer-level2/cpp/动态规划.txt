```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int len = s.size();
        if (len == 0)
            return 0;
        if (len == 1)
            return 1;
        int res = 0;
        int last = 1;
        map[s[0]] = 0;
        for (int i = 1; i < len; i++) {
            if (map.find(s[i]) == map.end()) {
                last = last + 1;
            } else {
                last = min<int>(i - map[s[i]], last + 1);
            }            
            map[s[i]] = i;
            res = max<int>(res, last);
        }
        return res;
    }
};
```
