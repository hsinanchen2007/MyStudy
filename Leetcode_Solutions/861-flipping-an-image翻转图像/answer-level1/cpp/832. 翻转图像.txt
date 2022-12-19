## 模拟法
**注意把水平翻转图像和反转像素值的操作放到一起**
```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r0 = A.size(), c0 = A[0].size();
        for(int i=0; i<r0; i++){
            for(int j=0, k=c0-1; j<k; j++, k--){
                swap(A[i][j], A[i][k]);
                A[i][j] = 1 - A[i][j];
                A[i][k] = 1 - A[i][k];
            }
            if(c0%2==1){
                A[i][c0/2] = 1 - A[i][c0/2];
            }
        }
        return A;
    }
};
```