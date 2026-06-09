```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> hash(256);
        for (int i = 0; i < s.size(); i ++) 
            hash[s[i]] ++;
        for (int i = 0; i < t.size(); i ++) {
            if (hash[t[i]] == 0) return false;
            hash[t[i]] --;
        }
        return true;
    }
};
```