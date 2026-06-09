```c++
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> pat(26, 0);
        for (auto& c : chars) {
            pat[c - 'a']++;
        }

        int ans = 0;
        for (auto& word : words) {
            vector<int> tmp(pat);
            bool flag = true;
            for (auto& c : word) {
                if (--tmp[c - 'a'] < 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans += word.size();
        }
        return ans;
    }
};
```
