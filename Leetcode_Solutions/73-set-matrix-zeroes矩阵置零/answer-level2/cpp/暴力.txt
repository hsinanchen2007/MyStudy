### 解题思路
首先遍历整个矩阵，存储元素0的坐标，然后再遍历坐标集，将元素0所在的行和列全部置为0.

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return;
        vector<pair<int,int>> zeroIndex;  //存储元素0的索引
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[0].size();++j)
            {
                if(matrix[i][j]==0)
                    zeroIndex.push_back(pair<int,int>(i,j));
            }
        }
        for(auto index:zeroIndex)
        {
            for(int i=0;i<matrix.size();++i)
            {
                matrix[i][index.second] = 0;
            }
            for(int j=0;j<matrix[0].size();++j)
            {
                matrix[index.first][j] = 0;
            }
        }
        return;
    }
};
```