还好的时间复杂度
![image.png](https://pic.leetcode-cn.com/b404a6e6aae372670ace5d093f082db27809e3a8b73e29b22d69a0de75abdca7-image.png)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        
        for(int i = 1; i < A.size(); i++){
            for(int j = 0; j < A.size(); j++){
                if (j == 0) {
                    A[i][j] = min(A[i-1][j], A[i-1][j+1]) + A[i][j];
                } else if (j == A.size() - 1) {
                    A[i][j] = min(A[i-1][j], A[i-1][j-1]) + A[i][j];
                } else {
                    A[i][j] = min(min(A[i-1][j], A[i-1][j+1]),A[i-1][j-1]) + A[i][j];
                }
            }
        }
        return *(min_element(A[A.size() - 1].begin(), A[A.size() - 1].end()));
    }
};