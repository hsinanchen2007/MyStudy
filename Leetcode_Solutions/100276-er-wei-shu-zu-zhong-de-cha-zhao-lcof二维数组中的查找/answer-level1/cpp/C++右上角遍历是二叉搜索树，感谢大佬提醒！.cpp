### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    /*评论区有大佬提醒，站在右上角为二叉搜索树，感谢这位大佬,跪拜感谢*/
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        if(matrix[0].size() == 0) return false;
        int col = matrix[0].size()-1;
        int row = matrix.size()-1;
        /*从右上角开始遍历*/
        int row1 =0;
        int col1 = col;
        while(!(row1<0 ||col1<0||row1>row||col1>col))
        {
            if(matrix[row1][col1] == target)
            {
                return true;
            }
            else if(matrix[row1][col1] >target)
            {
                col1--;
            }
            else if(matrix[row1][col1]<target)
            {
                row1++;
            }
        }
        return false;
    }
    
};
```