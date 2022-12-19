简单做法：记录原矩阵中值为0元素的行和列数值，然后秋后算账,以免伤及无辜
```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>rows;
        set<int>cols;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(auto row:rows){
            for(int j=0;j<n;j++){
                matrix[row][j]=0;
            }
        }
        for(auto col:cols){
            for(int i=0;i<m;i++){
                matrix[i][col]=0;
            }
        }
    }
};
```
