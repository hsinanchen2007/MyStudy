### 解题思路
只需要在两端元素相等的情况下取反.

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size(),n = A[0].size();
        for(int i=0;i<m;i++){
            int j = 0, r = n-1;
            while(j<=r){
                if(A[i][j] == A[i][r]){
                    A[i][j] = !A[i][j];
                    A[i][r] = A[i][j];
                }
                j++;
                r--;
            }
        }
        return A;
    }
};
```