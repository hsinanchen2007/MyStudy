### 解题思路
具体可见代码
整体思路还是便利，使用了额外的空间，
唯一算的两点就是使用了set，这样可减少行列重复置0

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // 时间复杂度:O(m*n)
        // 空间复杂度：O(max(m,n))

        if(matrix.empty())
        {
            return;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        /*
            * 先找出所有元素为0所在的行列
            * 采用set来保存，这样规避重复的行列
        */
        set<int> setRow,setCol;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    setRow.insert(i);
                    setCol.insert(j);
                }
            }
        }

        // 开始置0
        set<int>::iterator rowIter = setRow.begin();
        set<int>::iterator colIter = setCol.begin();

        for(; rowIter!=setRow.end(); rowIter++)
        {
            for(int i=0; i<n; i++)
            {
                matrix[*rowIter][i] = 0;
            }
        }

        for(; colIter!=setCol.end(); colIter++)
        {
            for(int i=0; i<m; i++)
            {
                matrix[i][*colIter] = 0;
            }
        }

        return;
    }
};
```