### 解题思路

![image.png](https://pic.leetcode-cn.com/8f00ab6763f1fb711237e248df3e6cd9667a5ee04620194b270f3853f2a32003-image.png)

暴力枚举

### 代码

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                bool flag=true;
                for(int k=0;flag&&k<matrix[i].size();k++)
                {
                    if(matrix[i][k]<matrix[i][j]) flag=false;
                }
                for(int k=0;flag&&k<matrix.size();k++)
                {
                    if(matrix[k][j]>matrix[i][j]) flag=false; 
                }
                if(flag) res.emplace_back(matrix[i][j]);
            }
        }
        return res;
    }
};
```