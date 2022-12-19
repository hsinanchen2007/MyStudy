选择第一个为0的行和列作为存储0的行row和列col,然后置0,但排除选择的行列row, col.最后把选中的row,col置0.
```
// Time 68ms, 89%, Space 11.3MB, 93%
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return;
        int m=matrix.size(), n=matrix[0].size(), row=-1, col=-1;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j){
                if(matrix[i][j]!=0) continue;
                if(row==-1) row=i, col=j;
                matrix[i][col]=matrix[row][j]=0;
            }
        if(row==-1) return;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n && i!=row; ++j)
                if(j!=col && (matrix[i][col]==0||matrix[row][j]==0))
                    matrix[i][j]=0;
        for(int i=0; i<m; matrix[i++][col]=0);
        for(int j=0; j<n; matrix[row][j++]=0);
    }
};
```