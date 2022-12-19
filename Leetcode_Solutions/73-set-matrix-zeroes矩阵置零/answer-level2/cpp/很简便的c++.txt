```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0&&vis[i][j]==false){
                    vis[i][j]=true;
                    for(int k=0;k<row;k++){
                        if(matrix[k][j]!=0){
                        matrix[k][j]=0;
                        vis[k][j]=true;
                        }
                    }
                    for(int l=0;l<col;l++){
                        if(matrix[i][l]!=0){
                        matrix[i][l]=0;
                        vis[i][l]=true;
                        }
                    }
                }
            }
        }
    }
};
```
