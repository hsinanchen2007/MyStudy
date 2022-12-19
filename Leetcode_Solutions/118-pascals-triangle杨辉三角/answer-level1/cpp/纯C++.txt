### 解题思路
纯C++

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int row = 0; row <= numRows - 1; row++)
        {
            res.push_back({});
            for (int col = 0; col <= row; col++)
            {
                if (0 == col || row == col)
                {
                    res[row].push_back(1);
                }
                else
                {
                    res[row].push_back(res[row - 1][col - 1] + res[row - 1][col]);
                }
            }
        }

        return res;
    }
};
```