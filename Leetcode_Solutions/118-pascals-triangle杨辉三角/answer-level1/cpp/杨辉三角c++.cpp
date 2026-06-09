### 解题思路
执行用时:0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗:8.3 MB, 在所有 C++ 提交中击败了100.00%的用户
按照公式直接生成即可，注意首末检查和row为0
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows > 0)
        {
            vector<int> row0 = {1};
            triangle.push_back(row0);
        }

        for (int i = 1; i < numRows; i++)
        {
            vector<int> row;
            vector<int> formerRow = triangle[i - 1];
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || (j == i && j != 0))
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(formerRow[j] + formerRow[j - 1]);
                }
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};
```