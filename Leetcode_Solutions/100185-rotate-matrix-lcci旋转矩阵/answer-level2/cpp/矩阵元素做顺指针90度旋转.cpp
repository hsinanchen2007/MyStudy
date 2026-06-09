### 解题思路
此处撰写解题思路
首先将矩阵的行做对称交换，然后在将矩阵的元素做对角交换
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    if(matrix.empty())
        return;
    int start=0;
    int last=matrix.size()-1;
    //交换矩阵的行
    while(start<last)
        swap(matrix[start++],matrix[last--]);
    //将矩阵的对角元素进行交换
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    }
};
```