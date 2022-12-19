```
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        map<string, vector<int> > m;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                m[word1].push_back(i);
            } else if (words[i] == word2) {
                m[word2].push_back(i);
            }
        }
        int res = INT_MAX;
        if (m.size() == 1) {
            for (int i = 1; i < m[word1].size(); ++i) {
                res = min(res, m[word1][i] - m[word1][i - 1]);
            }
            return res;
        }
        auto& v1 = m[word1];
        auto& v2 = m[word2];
        int i = 0;
        int j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                res = min(res, v2[j] - v1[i]);
                ++i;
            } else {
                res = min(res, v1[i] - v2[j]);
                ++j;
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/c81c028d55627326a1682c6eab2fc5945290f04ff55c6fc574b1c5494bae6ad6-image.png)
