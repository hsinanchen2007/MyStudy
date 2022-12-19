**翻转每一行，对角线镜像换位**

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i =0 ; i<matrix.size()/2; i++)
        {
            auto tmp = matrix[i];
            matrix[i] = matrix[matrix.size()-i-1];
            matrix[matrix.size()-i-1] = tmp;
        }
        
        for (int i = 0; i<matrix.size(); i++)
            for (int j = i; j < matrix[0].size(); j++)
            {
                auto t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
    }
};
```
