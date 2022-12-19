### 解题思路
先这样再那样就好了。   -  -

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     int n=matrix.size();
     auto matrix1=matrix;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
          matrix[j][n-i-1]=matrix1[i][j];
         }
     }
    }
};
```