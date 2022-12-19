```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, res=0;
        unordered_map<char, int> map;
        while (j < s.size()) {
            auto it = map.find(s[j]);
            if (it != map.end() && it->second >= i) {
                i = it->second + 1;
            }
            map[s[j]] = j;
            res = max(j-i+1, res);
            j++;
        }
        return res;
    }
};
```


