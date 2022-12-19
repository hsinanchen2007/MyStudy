```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int k = 0; k < m/2; ++k){
            for(int i = k; i < (m-k-1); ++i){
                int a = m-i-1, b = k,p = a;
                int temp = matrix[a][b];
                for(int j = 0 ; j < 4; ++j,a=b,b=m-p-1){
                    int pre = matrix[b][m-a-1];
                    matrix[b][m-a-1] = temp;
                    temp = pre;
                    p = a;
                }
            }
        }
    }
};
```
