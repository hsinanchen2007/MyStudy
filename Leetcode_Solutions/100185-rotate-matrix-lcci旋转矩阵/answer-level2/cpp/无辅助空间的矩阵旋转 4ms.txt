### 解题思路
解题思路：以反对称轴，将对称元素交换 得到的结果是旋转矩阵的逆序矩阵
         最后将每一行矩阵逆序排列就行了。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {int n=matrix.size();
    int m;
        for(int i=0;i<n;i++)//遍历反对称轴的上三角，与下三角交换。
        for(int j=0;j<n-(i+1);j++)
        {
            m=matrix[i][j];
            matrix[i][j]=matrix[n-j-1][n-i-1];
            matrix[n-j-1][n-i-1]=m;
        }
        for(int k=0;k<n/2;k++)//逆序排列
        matrix[k].swap(matrix[n-k-1]);
    }
};
```