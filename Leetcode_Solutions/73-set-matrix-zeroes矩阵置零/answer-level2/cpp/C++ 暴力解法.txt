### 解题思路
用multimap存储所给矩阵为0的位置，然后将这些位置的行列置零。

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int row=matrix.size();
        int colu=matrix[0].size();
        multimap<int,int> temp;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<colu;j++)
            {
                if(matrix[i][j]==0) temp.insert({i,j});
            }
        }
        for(auto iter=temp.begin();iter!=temp.end();iter++)
        {
            for(int i=0;i<colu;i++) matrix[iter->first][i]=0;
            for(int j=0;j<row;j++) matrix[j][iter->second]=0;
        }
    }
};
```