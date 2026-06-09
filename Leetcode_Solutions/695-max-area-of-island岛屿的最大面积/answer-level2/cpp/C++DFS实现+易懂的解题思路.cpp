

### 解题思路
此处撰写解题思路
1.解题思路:计算出最大面积的岛屿，即相邻不为0的最大面积。哪一块相邻的1最多，那面积最大。
2.代码思路：两层遍历，算出每个格子的相邻面积。如果这个格子本身值为1才计算，为0不计算。需要返回最大的相邻面积，因此用max（）取最大值。
    //只有不为0的格子，才进入DFS计算。可以巧妙省下不必要的计算
                if(grid[i][j]==1){
                    //算出每个格子的面积，取最大的
                    result=max(result,dfs(grid,i,j));
                }
3.注意点：
    （1）避免面积被累加了的格子被重复累加面积，因此算过了的当下的格子，其值需要赋值为0，再进入算其上下左右格子的面积。
    （2）避免跨界移出，在用DFS函数算面积时，需要判断i,j是否跨界了，跨界了，就返回0.
    （3）保证当下格子及其上下左右的格子的面积（即值）为1，才进行面积计算的累加。因此dfs(vector<vector<int>>& grid,int i,int j)函数也需要进行次判断if(grid[i][j]==1)
### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                //只有不为0的格子，才进入DFS计算。可以巧妙省下不必要的计算
                if(grid[i][j]==1){
                    //算出每个格子的面积，取最大的
                    result=max(result,dfs(grid,i,j));
                }

            }
        }
        return result;
    }
    //i--高度，weigh--宽度
    int dfs(vector<vector<int>>& grid,int i,int j){
        //这种情况下的grid[i][j]不存在，所以要把这个if放在前面。
        if(i<0||j<0||i>=grid.size()||j>=grid[i].size()) return 0;
        if(grid[i][j]==0) return 0;
        //当下格子在外层保障了该格子值为1，但是该格子计算上下左右的面积时也会进入这个dfs函数，此处保证上下左右格子的值为1才会进行后面面积计算的累加。
        if(grid[i][j]==1){
             //避免重复被计算
             grid[i][j]=0;
             //自己本身的1+上下左右格子的面积,外层遍历时就判断了
            return 1+dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1);
        }
        return 0;
       
    }
};
```
执行结果：
    通过
显示详情
    执行用时 :
    12 ms, 在所有 C++ 提交中击败了95.81%的用户
内存消耗 :
    24.9 MB, 在所有 C++ 提交中击败了5.71%的用户