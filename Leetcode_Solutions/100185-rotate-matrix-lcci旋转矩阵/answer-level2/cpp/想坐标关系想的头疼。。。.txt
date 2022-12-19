### 解题思路
一层一层得拨开你的心
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int first;
        for(int i=0;i<n/2;++i)
        {
            for(int j=i;j<n-i-1;++j)
            {
                first=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-i-1][n-1-j];
                matrix[n-i-1][n-1-j]=matrix[j][n-i-1];
                matrix[j][n-i-1]=first;
            }
        }
    }
};
```