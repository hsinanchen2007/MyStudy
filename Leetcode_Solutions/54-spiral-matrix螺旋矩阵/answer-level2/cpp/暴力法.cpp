### 解题思路
循环

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if(m==0) return res;
        int n = matrix[0].size();
        if(n==0) return res;

        int count = m<n?(m+1)/2:(n+1)/2;
        for(int i=0;i<count;++i)
        {
            if(n-2*i>1&&m-2*i>1){
                for(int j=i;j<n-i;++j)
                    res.push_back(matrix[i][j]);  
                for(int j=i+1;j<m-i;++j)
                    res.push_back(matrix[j][n-i-1]); 
                for(int j=n-i-2;j>=i;--j)
                    res.push_back(matrix[m-i-1][j]); 
                for(int j=m-i-2;j>i;--j)
                    res.push_back(matrix[j][i]); 
            }
            else if(n-2*i==1){
                for(int j=i;j<m-i;++j)
                    res.push_back(matrix[j][i]);
            }
            else if(m-2*i==1){
                for(int j=i;j<n-i;++j)
                    res.push_back(matrix[i][j]);
            }

        }
        return res;
    }
};


```