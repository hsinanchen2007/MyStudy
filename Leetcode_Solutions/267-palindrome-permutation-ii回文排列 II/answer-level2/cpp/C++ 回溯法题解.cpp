```C++ []
class Solution {
public:
    void dfs(map<char, int> counts, int i, int K, string odds, string& s, vector<string>& res) {
        if (i == K) {
            string t = s;
            reverse(t.begin(), t.end());
            t += odds + s;
            res.push_back(t);
            return;
        }
        for (auto& p : counts) {
            if (p.second == 0) continue;
            --p.second;
            s += p.first;
            dfs(counts, i + 1, K, odds, s, res);
            s.pop_back();
            ++p.second;
        }
    }
    vector<string> generatePalindromes(string s) {
        if (s.size() < 2) return {s};
        int N = s.size();
        map<char, int> counts;
        for (auto c : s) ++counts[c];
        string odds;
        for (auto& p : counts) {
            if (p.second & 1) {
                odds += p.first;
            }
        }
        if ((odds.size() > 1 && (N & 1)) || (odds.size() > 0 && !(N & 1))) {
            return {};
        }
        int K = 0;
        for (auto& p : counts) {
            p.second >>= 1;
            K += p.second;
        }
        string t;
        vector<string> res;
        dfs(counts, 0, K, odds, t, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/872633c85f314a801089a00498851438a0e9270f113152f57b768b54cd4dd564-image.png)
