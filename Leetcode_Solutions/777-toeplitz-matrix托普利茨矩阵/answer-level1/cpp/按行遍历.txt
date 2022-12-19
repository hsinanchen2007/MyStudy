### 解题思路
使用按行遍历，pair作为key保存不同对角线起始坐标
由于同一条对角线上(r,c)点的下一个坐标为(r+1, c+1)，即r,c递增相同次数
因此对于给定的坐标(R,C)， 使R,C同时减去min(R,C)即可找到对应的对角线首元素坐标
### 代码

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        map<pair<int,int>, bitset<100>> m;
        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                int d = min(r, c);
                m[make_pair(r - d, c - d)][matrix[r][c]] = 1;
            }
        }

        for (auto & p : m) {
            if (p.second.count() != 1) {
                return false;
            }
        }
        return true;
    }
};
```