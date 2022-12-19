```
class Solution {
public:
    bool canConstruct(string s, int k) {
        int len = s.size();
        if (len < k)
            return false;
        if (len == k)
            return true;
        vector<int> map(26, 0);
        for (char c : s) {
            map[c - 'a']++;
        }
        int num = 0;
        for (int i = 0; i < 26; i++) {
            if ((map[i] & 1) == 1)
                num++;
        }
        return num <= k;
    }
};
```
