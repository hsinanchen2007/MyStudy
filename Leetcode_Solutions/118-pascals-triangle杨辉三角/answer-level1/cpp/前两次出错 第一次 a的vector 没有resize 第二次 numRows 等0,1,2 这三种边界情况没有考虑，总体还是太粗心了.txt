### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    std::vector<int> GetTrige(const std::vector<int> &tmp_vec) {
        std::vector<int> res;
        res.resize(tmp_vec.size() + 1);
        res[0] = 1;
        res[res.size() - 1] = 1;
        for (int i = 0; i < tmp_vec.size() - 1; ++i) {
            res[i + 1] = tmp_vec[i] + tmp_vec[i + 1];
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> a;
        a.resize(numRows);
        if (numRows == 0) {
            return a;
        }
        if (numRows == 1) {
            a[0] = {1};
            return a;
        }
        if (numRows == 2) {
            a[0] = {1};
            a[1] = {1, 1};
        return a;
        }
        a[0] = {1};
        a[1] = {1, 1};
        std::vector<int> tmp_vec;
        for (int i = 2; i < numRows; ++i) {
            a[i] = GetTrige(a[i - 1]);
        }
        return a;
    }
};
```