```
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> m;
        for(char c : s) m[c]++;
        for(char c : s) {
            if(m[c] == 1)
                return c;
        }
        return ' ';
    }
};
```
