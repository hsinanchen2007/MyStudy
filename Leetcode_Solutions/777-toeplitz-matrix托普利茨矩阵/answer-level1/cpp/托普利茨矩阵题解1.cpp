### 解题思路
此处撰写解题思路
首先：划去第一行和第一列，
第二：检查剩下的元素是否等于左上角元素，通过遍历元素实现。
第三：遍历完k等于rows+cols-(rows-1)*(cols-1)
第四：判定k-1是否等于rows*cols;是，则输出true

### 代码

```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows =matrix.size();
        int cols = matrix[0].size();
        int k=rows+cols;
        for(int i=1;i<rows;i++)
        {
            for(int j= 1;j<cols;j++)
            {
                if(matrix[i-1][j-1]==matrix[i][j])
                {
                    k++;
                }
            }
        }
        if((k-1)==rows*cols)
       {
           return true;

        } 
        else 
        {
            return false;
        }
        
    }
};
```