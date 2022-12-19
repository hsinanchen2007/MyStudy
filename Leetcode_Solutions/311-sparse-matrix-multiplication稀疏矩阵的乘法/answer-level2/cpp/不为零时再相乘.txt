```
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans(A.size(), vector<int>(B[0].size(), 0));
        // 不为0时再相乘
        for(int i = 0; i < A.size(); i++){
            for(int k = 0; k < A[0].size(); k++){
                if(A[i][k] != 0){
                    for(int j = 0; j < B[0].size(); j++){
                        if(B[k][j] != 0) ans[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

        }
    return ans;
    }
};
```
time : 8ms
