从右上角开始寻找，也可从左下角开始
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return 0;
        for(int i=0,j=matrix[0].size()-1;j>=0 && i<matrix.size();){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};
```
