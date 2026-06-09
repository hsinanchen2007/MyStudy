### 解题思路
![截图未命名.jpg](https://pic.leetcode-cn.com/be9d6f4e4f98d6d931b53ae2cfb5924b76ef57424936c535614d8dc4b8265f22-%E6%88%AA%E5%9B%BE%E6%9C%AA%E5%91%BD%E5%90%8D.jpg)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {//先转置再反转每一行
        int m=matrix.size();
        T(matrix,m);
        reverse_row(matrix,m);
    }
    void T(vector<vector<int>> &matrix,int m){
        for(int i=0;i<m;++i){
            for(int j=i+1;j<m;++j)
                swap(matrix[i][j],matrix[j][i]);
        }
    }
    void reverse_row(vector<vector<int>> &matrix,int m){
        for(int i=0;i<m;++i){
            for(int j=0;j<m/2;++j)
                swap(matrix[i][j],matrix[i][m-1-j]);
        }
    }
};
```