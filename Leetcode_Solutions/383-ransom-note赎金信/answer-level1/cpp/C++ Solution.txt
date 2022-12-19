```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mv(26, 0);
        for(char c:magazine) mv[c - 'a']++;
        for(char c:ransomNote) if (mv[c - 'a']-- == 0) return false;
        return true;
    }
};
```
