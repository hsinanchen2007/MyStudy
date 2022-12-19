先对角线元素互换，然后对每一行逆序
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int tmp = 0;
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(auto &k: matrix){
            reverse(k.begin(),k.end());
        }

    }
};
```
