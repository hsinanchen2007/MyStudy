### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        //先扫描第一行
        for(int j=0;j<col;j++)
        {
            int temp=j;
            int n=0;
            while(n<row&&temp<col)
            {
                if(matrix[n][temp]!=matrix[0][j])
                {
                    return false;
                }
                else
                {
                    temp++;
                    n++;
                }
            }
        }
        //在扫描第一列
        for(int i=1;i<row;i++)
        {
            int temp=i;
            int m=0;
            while(temp<row&&m<col)
            {
                if(matrix[temp][m]!=matrix[i][0])
                {
                    return false;
                }
                else
                {
                    temp++;
                    m++;
                }
            }
        }
        return true;
    }
};
```