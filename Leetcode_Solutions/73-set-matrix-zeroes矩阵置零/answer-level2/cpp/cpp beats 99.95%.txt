### 解题思路
将row 0,column 0之外的0,转移到映射的row 0,row 1区间上，例如magic[4][7]=0， 泽magic[4][0]=0,magic[0][7]=0。
分三批转换，详见代码

### 代码

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
        return;
        int rowsize=matrix.size(),columnsize=matrix[0].size();
        bool zerorow=false,zerocolumn=false;
        for(int i=0;i<rowsize;++i){
            for(int j=0;j<columnsize;++j)
            {
                if(matrix[i][j]==0)
                {
                    if(i==0) zerorow=true;
                    if(j==0) zerocolumn=true;
                    if(i>0&&j>0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                    }
                }
            }
        }
        for(int i=1;i<rowsize;++i){
            if(matrix[i][0]==0)
            for(int j=1;j<columnsize;++j)
                matrix[i][j]=0;
        }
        for(int i=1;i<columnsize;++i)
        {
            if(matrix[0][i]==0)
            for(int j=1;j<rowsize;++j)
                matrix[j][i]=0;
        }
        if(zerocolumn)
        for(int i=0;i<rowsize;++i)
            matrix[i][0]=0;
        if(zerorow)
        for(int i=0;i<columnsize;++i)
            matrix[0][i]=0;
        
    }
};
```