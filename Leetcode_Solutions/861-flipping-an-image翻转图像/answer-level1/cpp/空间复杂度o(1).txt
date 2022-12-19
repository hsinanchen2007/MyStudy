### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                int temp=A[i][j];
                A[i][j]=A[i][n-1-j];
                A[i][n-1-j]=temp;
                A[i][j]=abs(A[i][j]-1);
                A[i][n-1-j]=abs(A[i][n-1-j]-1);
            }
            if(n%2==1){
                A[i][n/2]=abs(A[i][n/2]-1);
            }
        }
        return A;
    }
};
```