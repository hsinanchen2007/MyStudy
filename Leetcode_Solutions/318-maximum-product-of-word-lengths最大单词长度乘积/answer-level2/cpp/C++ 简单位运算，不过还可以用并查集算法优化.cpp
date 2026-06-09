```
class Solution {
public:
    int str2int(const string& s) {
        int res = 0;
        for (auto c : s)
            res |= 1 << (c - 'a');
        return res;
    }
    int maxProduct(vector<string>& words) {
        int N = words.size();
        vector<int> m(N, 0);
        for (int i = 0; i < N; ++i)
            m[i] = str2int(words[i]);
        int res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((m[i] & m[j]) == 0 && words[i].size() * words[j].size() > res)
                    res = words[i].size() * words[j].size();
            }
        }
        return res;
    }
};

```
