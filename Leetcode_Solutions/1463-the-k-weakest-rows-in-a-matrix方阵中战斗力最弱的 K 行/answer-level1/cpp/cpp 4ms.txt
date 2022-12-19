![image.png](https://pic.leetcode-cn.com/b0a440c34dc9c2cea280de984bb5ce7b111b953c6d33cf362773104510e18a33-image.png)

思路：
1.遍历，每一行保存两个值，总和与序号
2.按照题意排序
3.输出到结果

```
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int order = 0;
        for (auto& line : mat) {
            line = { accumulate(line.begin(), line.end(), 0), order++ };
        }
        sort(mat.begin(), mat.end(), [] (const auto& a, const auto& b) { return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]); });
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.emplace_back(mat[i][1]);
        }
        return result;
    }
};
```
