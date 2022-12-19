### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> col;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it=row.begin();it!=row.end();it++){
            int k=*it;
            for(int j=0;j<matrix[0].size();j++){
                matrix[k][j]=0;
            }
        }
        for(auto it=col.begin();it!=col.end();it++){
            int k=*it;
            for(int j=0;j<matrix.size();j++){
                matrix[j][k]=0;
            }
        }
    }
};
```