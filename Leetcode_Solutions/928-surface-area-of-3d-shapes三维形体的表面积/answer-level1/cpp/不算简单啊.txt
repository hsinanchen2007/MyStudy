### 解题思路
emm,首先，比较考验理解题目的能力，理解题目之后解题思路不难。我从这道题中就是学到vector[]这种形式效率低，重复使用的部分可以赋值给一个变量！
### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int CoincidenceCount = 0;
        int count = 0;
        //按顺序判断每个块的前，上，左三个面，如果有，则去掉两个面，按顺序不会重复
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                int current = grid[i][j];
                count += current;
                //上下方向
                CoincidenceCount += (current>0)?(current-1)*2:0;
                //左右方向
                if(j<grid[i].size()-1)
                    CoincidenceCount +=2*((current>grid[i][j+1])?grid[i][j+1]:current);
                //前后方向
                if(i<grid.size()-1)
                    CoincidenceCount +=2*((current>grid[i+1][j])?grid[i+1][j]:current);
            }
        }
        return count*6-CoincidenceCount;
    }
};
```