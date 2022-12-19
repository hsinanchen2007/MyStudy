### 解题思路
利用hash记录哪些文档对有交集，然后只计算这些文档对

### 代码

```cpp
class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        map<int, vector<int> > content_to_docs;
        map<pair<int, int>, int> inters;
        for (int i = 0; i < docs.size(); ++i) {
            for (auto x : docs[i]) {
                content_to_docs[x].push_back(i);
            }
        }
        for (const auto& [c, d] : content_to_docs) {
            for (int i = 0; i < d.size(); ++i) {
                for (int j = i + 1; j < d.size(); ++j) {
                    ++inters[{d[i], d[j]}];
                }
            }
        }
        vector<int> counts;
        for (const auto& doc : docs) {
            counts.push_back(doc.size());
        }
        vector<string> res;
        for (const auto& [p, inter] : inters) {
            int unio = counts[p.first] + counts[p.second] - inter;
            double sim = inter * 1.0 / unio;
            char s[20];
            sprintf(s, "%d,%d: %.4f", p.first, p.second, sim + 1e-9);
            res.push_back(string(s, s + 20));
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/2c4ac8644ac3d190d4f7141f854729b4d2ced5f2837af9fde84676fc80803a5c-image.png)
