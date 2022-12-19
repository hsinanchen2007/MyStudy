思路：
观察题目发现：旋转90度实际就是将第i行变为第n-1-i列。
于是使用辅助数组得以下解。
```class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int *a = new int[matrix.size()*matrix.size()];
        int k = 0;
        for(int i = 0;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                a[k] = matrix[i][j];
                cout<<a[k]<<' ';
                k++;
            }
        }
        
        int n = matrix.size()-1;
        int z = 0;
        while(n>=0){
        for(int i =0;i<matrix.size();i++){
            matrix[i][n] = a[z];
            z++;
        }
        n--;
        }
    }
};```