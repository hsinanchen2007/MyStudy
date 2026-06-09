### 解题思路
参考大佬的想法
每次删除首行元素，并逆时针旋转一次即可实现。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        while(matrix.size()>0)
        {
            for(int i:matrix[0])
                res.push_back(i);
            matrix.erase(matrix.begin());
            rotate(matrix);
        }
        return res;
        
    }

    void rotate(vector<vector<int>>& matrix)
    {
        vector<vector<int>> new_matrix;
        for(int i=matrix[0].size()-1;i>=0;i--)
        {
            vector<int> tmp;
            for(int j=0;j<matrix.size();j++)
                {
                    tmp.push_back(matrix[j][i]);
                }
            new_matrix.push_back(tmp);
        }
        matrix=new_matrix;
    }

};
```