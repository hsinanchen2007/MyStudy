### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0) return false;
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;

        while(m>0&&row<=n-1)
        {
            if(matrix[row][m-1]==target) return true;
            else if(matrix[row][m-1]>target) m--;
            else row++;
            

        }return false;
       
    }
};
```