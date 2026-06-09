### 解题思路
此处撰写解题思路
这个题，直接暴力即可，但是一定要注意，能用hash就不要用map，能用数组就不要用vector，性能差距还是很大的

![image.png](https://pic.leetcode-cn.com/3490e47635405dc5de0e700fd576852bae92a52d15fff40ff44b9ecd1f6e10b1-image.png)


### 代码

```cpp
# define DUMP(args...)
// 最多10种字符，每个字符最多10种选择{0-9}，那么直接dfs暴力搜索即可
class Solution {
    vector<string> words;
    string result;
    // vector<bool> n0;  // 不能取0的字符集
    bool n0[128];
    set<char> allset;  // 所有字符集
    vector<char> all;  // 所有字符集，allset的拷贝
    // vector<bool> dup;
    bool dup[10];
    // vector<int> c2d;
    int c2d[128];
    bool flag{false};  // 是否已经找到答案
    void init(vector<string>& words, string& result) {
        // n0.resize(128);
        std::fill(n0, n0+128, false);
        for (auto& w : words) {
            n0[w[0]] = true;
            for (auto c : w) allset.insert(c);
        }
        n0[result[0]] = true;
        for (auto c : result) allset.insert(c);
        all.assign(allset.begin(), allset.end());

        // dup.resize(10);
        std::fill(dup, dup+10, false);
        // c2d.resize(128);
        // std::fill(c2d.begin(), c2d.end(), -1);
        std::fill(c2d, c2d+128, -1);

        DUMP(n0, allset, all, words, result);

        this->words.swap(words);
        this->result.swap(result);
    }
    void dump() {
        for (auto& w : words) {
            int v = 0;
            for (auto c : w) v = 10*v + c2d[c];
            DUMP(w, v);
        }
        int r = 0;
        for (auto c : result) r = 10*r + c2d[c];
        DUMP(result, r);
    }
    bool check() {
        // return false;
        int l = 0;
        for (int i = 0; i < result.size(); ++i) {
            for (auto& w : words) {
                if (w.size() > i) l += c2d[w[w.size()-1-i]];
            }
            int r = c2d[result[result.size()-1-i]];
            if (l % 10 != r) {
                return false; 
            }
            l /= 10;
        }
        return l == 0;
    }
    void dfs(size_t k) {
        if (flag) return;
        if (k == all.size()) {
            if (check()) flag = true;
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            if (i == 0 && n0[all[k]]) continue;
            if (dup[i]) continue;
            dup[i] = true;
            c2d[all[k]] = i;
            // DUMP("try", k, all[k], i);
            dfs(k+1);
            if (flag) return;
            c2d[all[k]] = -1;
            dup[i] = false;
        }
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        init(words, result);
        dfs(0);
        if (flag) {
            dump();
        }
        return flag;
    }
};
```