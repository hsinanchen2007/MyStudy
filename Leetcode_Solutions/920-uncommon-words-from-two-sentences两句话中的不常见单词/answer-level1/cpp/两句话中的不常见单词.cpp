```
class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> record;
        string sum = A + " " + B;
        int i = 0;
        while (i < sum.size()) {
            if (sum[i] != ' ') {
                int loc = i, len = 0;
                while (i < sum.size() && sum[i] != ' ') {
                    ++len;
                    ++i;
                }
                ++record[sum.substr(loc, len)];
            }
            ++i;
        }
        vector<string> res;
        for (auto v : record) {
            if (v.second == 1) res.push_back(v.first);
        }
        return res;
    }
};
```
