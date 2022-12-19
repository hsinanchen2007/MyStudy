```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int ti = 0;
        int bi = matrix.size()-1;
        int lj = 0;
        int rj = matrix[0].size()-1;
        int m;
        while(ti < bi)
        {
            m = (ti+bi+1)/2;
            if(matrix[m][0] <= target)
                ti = m;
            else
                bi = m-1;
        }
        if(matrix[ti][0] > target)
            return false;
        while(lj <= rj)
        {
            m = (lj+rj)/2;
            if(matrix[ti][m] == target)
                return true;
            else if(matrix[ti][m] < target)
                lj = m+1;
            else
                rj = m-1;
        }
        return false;
    }
};
```
