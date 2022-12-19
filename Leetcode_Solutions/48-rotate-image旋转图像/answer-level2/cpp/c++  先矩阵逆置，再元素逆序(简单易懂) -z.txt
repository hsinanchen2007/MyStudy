### 解题思路
参考了官方写法1，
对矩阵先进行逆置，再每一行的元素进行逆序

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

      int n=matrix.size();
      for(int i=0;i<n;i++)      //先矩阵逆置
      for(int j=i+1;j<n;j++)        
      swap(matrix[i][j],matrix[j][i]);

      for(int i=0;i<n;i++)       //再每行逆序
      reverse(matrix[i].begin(),matrix[i].end());
    }
};
```

### 自己实现

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

      int n=matrix.size();
      for(int i=0;i<n;i++)      //先矩阵逆置
      for(int j=i;j<n;j++)        
      {
          int t=matrix[i][j];
          matrix[i][j]=matrix[j][i];
          matrix[j][i]=t;
      }     

      for(int i=0;i<n;i++)        //再每行元素逆序
      for(int j=0;j<n/2;j++)  
      {
          int t=matrix[i][j];
          matrix[i][j]=matrix[i][n-1-j];
          matrix[i][n-1-j]=t;
      }
    }
};
```