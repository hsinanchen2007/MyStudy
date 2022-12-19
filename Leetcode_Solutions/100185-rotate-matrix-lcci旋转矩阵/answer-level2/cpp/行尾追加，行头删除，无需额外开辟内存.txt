### 解题思路
此处撰写解题思路
对于矩阵
[[1,2,3],
 [4,5,6],
 [7,8,9]]
1. 在每一行尾追加每一行头的元素，如下
    [[1,2,3,7,4,1],
     [4,5,6,8,5,2],
     [7,8,9,9,6,3]]
2. 从每一行头删除原始元素，即得：
    [[7,4,1],
     [8,5,2],
     [9,6,3]]
**erase操作写在第一个for循环中得到错误结果(代码注释行)，我对c++不是很熟，求问大佬是什么原因**

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        int n = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j >= 0; j--)
            {
                matrix[i].push_back(matrix[j][n]);
            }
            n++;
            //matrix[i].erase(std::begin(matrix[i]), std::begin(matrix[i]) + 3);
        }
        for (int i = 0; i < size; i++)
        {
            matrix[i].erase(std::begin(matrix[i]), std::begin(matrix[i]) + size);
        }
    }
};
```