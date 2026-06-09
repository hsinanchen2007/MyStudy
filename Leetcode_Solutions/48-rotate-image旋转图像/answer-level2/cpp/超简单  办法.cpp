首尾依次交换 意思是 原本Matrix 
比如n=3 则 matrix[0] 和 matrix[2] 交换
比如n=4 则 matrix[0] 和 matrix[3] 交换 matrix[1] 和 Matrix[2] 交换 以此类推
然后沿主对角线交换，ij 和 ji交换就行了 注意if 否则会重复交换相当于没换 
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //首尾依次交换  然后沿主对角线交换
        for(int i=0; i<n/2; i++){
            swap(matrix[i], matrix[n-1-i]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i>j)swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```
