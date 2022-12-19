### 解题思路
执行用时击败17.15%，
**内存击败100.00%**（原地操作）
实现矩阵的顺时针旋转90度，只需要先做矩阵转置，然后再把矩阵左边的值和右边的值互换即可；
即实现了原地操作（不增加额外的矩阵）。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //先作转置，然后左右互换
        int n=matrix.size();
        int t;
        for(int i=0; i<n; i++){//矩阵转置
            for(int j=i+1; j<n ;j++){
                t=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=t;
            }
        }
        for(int i=0; i<n; i++){//左右互换
            for(int j=0; j<n/2; j++){
                t=matrix[i][j];
                matrix[i][j]=matrix[i][n-1-j];
                matrix[i][n-1-j]=t;
            }
        }
        return;
    }
};
```