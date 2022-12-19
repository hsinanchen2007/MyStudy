### 解题思路
行遍历，然后找头尾，再找每一行间的数字

### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        if(matrix[0].empty()) return false;
        int temp=0;
        bool res = false;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++)
        { 
            if(target==matrix[i][0]) 
            {
                res = true;
                break;
            }
            else if(target>matrix[i][0]&&target<matrix[i][col-1]) 
            {
               temp=i;
               break;
            }
            else if(target==matrix[i][col-1])
            {
                res = true;
                break;
            }
            
        }
       
            for(int z=0;z<col;z++)
            {
                if(target==matrix[temp][z])
                {
                    res = true;
                    break;
                } 
            }
        
        
        return res;
    }
};
```![image.png](https://pic.leetcode-cn.com/33eb196a2f44ce050241f6b4f80c049b49012a4ca41feab6f7fee5cfcce72936-image.png)
