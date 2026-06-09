### 解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      if(matrix.size()==0)
      return vector<int>();
      int m=matrix.size(),n=matrix[0].size();
      int i=0,j=0;
      int ilevel=0,jlevel=0;
      while(res.size()<m*n)
      {
            res.push_back(matrix[i][j]);

            if(i==ilevel&&j<n-jlevel-1)
                j++;
            else
            if(j==n-1-jlevel&&i<m-ilevel-1)
                i++;
            else
            if(i==m-1-ilevel&&j>jlevel)
                j--;
            else
            if(j==jlevel&&i>ilevel)
                i--;
            else
            break;
    
            if(i==ilevel&&j==jlevel)
            {
                i=++ilevel;
                j=++jlevel;
            }
      }   
      return res;
    }
};
```