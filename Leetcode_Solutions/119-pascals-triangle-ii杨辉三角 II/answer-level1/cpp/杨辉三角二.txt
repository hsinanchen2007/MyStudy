### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了95.91%的用户
普通思路, 先构造再返回
### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        if (rowIndex >= 0)
        {
            vector<int> row0 = {1};
            triangle.push_back(row0);
            if(rowIndex == 0)
                return row0;
        }

        for (int i = 1; i <= rowIndex; i++)
        {
            vector<int> prevRow = triangle[i - 1];
            vector<int> row;
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                    row.push_back(1);
                else
                {
                    row.push_back(prevRow[j] + prevRow[j - 1]);
                }
            }

            if (i == rowIndex)
            {
                return row;
            }
            triangle.push_back(row);
        }
        return {-1};
    }
};
```