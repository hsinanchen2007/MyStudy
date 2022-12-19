### 解题思路
题目理解着实费劲，还是看了题解的示意图才明白输入表示什么！！！！
以其中一个柱形做分析grid[i][j]，如果上面有n个立方体，每个立方体6个面，则一共6n个面，去掉中间重叠的面但是要保留上下各一个面，所以是减掉(n-1)*2个，
再考虑上下左右都有相邻立方体的情况，减掉的面是相邻个数少的立方体个数，因为所有柱体都会遍历计算一遍，也就是如果两个柱体相邻，那么就会减两次，所以一次只需要把自己这边相邻的面数减掉，所以是减掉min(grid[i][j], grid[i][j-1])个就行，当计算到相邻的柱体还会再减一遍。
如果当前是空的则不需要进行计算。

### 代码

```cpp
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 0)
                    continue;
                int cur = grid[i][j]* 6 - (grid[i][j] - 1)*2;
                if(j-1 >= 0) 
                {
                    int minGridNum = grid[i][j] < grid[i][j-1] ? grid[i][j] : grid[i][j-1];
                    cur -= minGridNum; 
                }
                if(j+1 < grid[i].size()) 
                {
                    int minGridNum = grid[i][j] < grid[i][j+1] ? grid[i][j] : grid[i][j+1];
                    cur -= minGridNum; 
                }
                if(i-1 >= 0) 
                {
                    int minGridNum = grid[i][j] < grid[i-1][j] ? grid[i][j] : grid[i-1][j];
                    cur -= minGridNum; 
                }
                if(i+1 < grid.size()) 
                {
                    int minGridNum = grid[i][j] < grid[i+1][j] ? grid[i][j] : grid[i+1][j];
                    cur -= minGridNum; 
                }
                sum += cur;
            }
        }
        return sum;
    }
};
```