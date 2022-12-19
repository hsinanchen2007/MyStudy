```
class Solution {
public:
    int minimumLengthEncoding(vector<string> &words) {
        for (string &word:words) {
            reverse(word.begin(), word.end());
        }
        sort(words.begin(), words.end());
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            if (i + 1 < words.size() && words[i + 1].find(words[i]) == 0) {
                continue;
            } else {
                res += words[i].size() + 1;
            }

        }
        return res;
    }
};
```
