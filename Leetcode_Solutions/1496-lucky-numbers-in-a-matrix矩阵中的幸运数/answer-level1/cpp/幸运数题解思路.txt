### 解题思路
此处撰写解题思路
按行找出每行的最小值作为数组minRow
按列找出每列的最大值作为数组maxCol
最后,遍历matrix, 满足条件:matrix[i][j] == rowMinVector[i] && matrix[i][j] == colMaxVector[j]
即为幸运数字.
### 代码

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
            vector<int> rowMinVector;
    for (int i = 0; i < matrix.size(); ++i)
    {
        int minValue = matrix[i][0];
        for (int j = 0; j <matrix[i].size(); ++j)
        {
            if (matrix[i][j] < minValue)
            {
                minValue = matrix[i][j];
            }
        }
        rowMinVector.push_back(minValue);
    }

    vector<int> colMaxVector;
    for (int j = 0; j < matrix[0].size(); ++j)
    {
        int maxValue = matrix[0][j];
        for (int i = 0; i < matrix.size(); ++i)
        {
            if (matrix[i][j] > maxValue)
            {
                maxValue = matrix[i][j];
            }
        }
        colMaxVector.push_back(maxValue);
    }

    vector<int> result;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j <matrix[i].size(); ++j)
        {
            if (matrix[i][j] == rowMinVector[i] && matrix[i][j] == colMaxVector[j])
            {
                result.push_back(matrix[i][j]);
            }
        }
    }

    return result;
    }
};
```