行转成字符串，转的时候，如果行以0开头，则将行中所有数取反，如果是1开头，保持不变
然后看有多少个相同的字符串，选择其中个数最大的
```
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int res = 0;
        for (auto& r : matrix) {
            string s;
            int d = 1 ^ r[0];
            for (auto x : r) {
                s += (d ^ x) + '0';
            }
            ++m[s];
            res = max(res, m[s]);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/ddda2bdb548c57930ef674db6ce544fa277c424bb32a3995fae498670ecff4c5-image.png)
