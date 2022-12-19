首先二分查找找到当前行,然后对当前行再二分查找.4ms解决
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int m=matrix.size(), n=matrix[0].size(), begin=0;
        for(int end=m; begin<end;){
            int row=(begin+end)/2;
            if(matrix[row][n-1]==target) return true;
            else if(matrix[row][n-1]>target) end=row;
            else begin=row+1;
        }
        return begin==m?false:binary_search(matrix[begin].begin(),matrix[begin].end(),target);
    }
};
```
