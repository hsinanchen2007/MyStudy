### 解题思路
逐行遍历矩阵：对于某一行，若某一个元素为负数，则后面都为负数。

![image.png](https://pic.leetcode-cn.com/2bdd9c6f93d48b8399cf5df55c810e655d49bed8b23fdd987c8b917599c09d05-image.png)

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0, row = grid.size(), col = grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]<0) 
                {
                    cnt+=col-j;
                    break;
                }
            }
        }
        return cnt;
    }
};
```