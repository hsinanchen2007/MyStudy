### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int > > rac;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                rac.push_back(make_pair(i,j));
            }
        }
        for(int i=0;i<rac.size();i++){
            int row=rac[i].first;
            int col=rac[i].second;
            for(int i=0;i<matrix[0].size();i++)
                matrix[row][i]=0;
            for(int i=0;i<matrix.size();i++)
                matrix[i][col]=0;
        }
    }
};
```