先转置矩阵，再调换列位置。

```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int temp[10000]={0}, tmp=0;
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                tmp=matrix[j][i];
                matrix[j][i]=matrix[i][j];
                matrix[i][j]=tmp;
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<n/2;j++)
            {
                tmp=matrix[i][j];
                matrix[i][j]= matrix[i][n-j-1];
                matrix[i][n-j-1]=tmp;
            }
    }
};
```
