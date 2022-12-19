### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res;
        for (int i = 1; i <= numRows; i++) {
            vector<int> current_row(i, 1);
            for (int j = 1; j < i - 1; j++) {
                current_row[j] = res[i - 2][j - 1] + res[i - 2][j];
            }
            res.push_back(current_row);
        }
        return res;
    }
};
```