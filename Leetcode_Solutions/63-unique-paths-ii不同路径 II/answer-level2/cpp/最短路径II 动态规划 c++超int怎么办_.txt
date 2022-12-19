### 解题思路
其实很简单 和最短路径I没多大区别 方法,思想都很一致 就是有点数据坑

dp[i][j] 表示到达[i][j]的方法总数
转移方程: `dp[i][j] = dp[i][j-1] + dp[i-1][j];`

我在这里没有新开一个数组用于存放dp值 而是直接存入obstacleGrid向量中 
是为了降低空间复杂度

首先和最短路径I类似 将第一行及第一列标记为1, 但要注意:如果中途出现了障碍 后面的都变成0了
我这里是用了一个 flag 变量来实现
然后遍历地图 dp[i][j] = dp[i][j-1] + dp[i-1][j] 但是如果dp[i][j]是障碍(即obstacleGrid[i][j]初值是1) 就把它变为0 代表这里0条路能走
最后返回数据 然后就没了
但是有个数据对c++非常不友好
那个数据应该是这样的 有一个点的dp值很大 大到超过了int的范围 但是这个点的右边和下面都是障碍
(其实可以通过新开一个long的数组用来存dp值 但是我这里就用了另一种方法,,属于投机取巧吧)
这个点的值实际上对答案没有帮助
因为返回值的类型是int 所以中途超过int的都是没有用的点 否则不断累加 最终的返回值也一定会超过int的 就不合题意了 所以只要计算到超过INT_MAX的值 我就直接令他等于0了 (投机取巧)
(INT_MAX是宏定义在<limits.h>头文件中的,表示int能储存的最大值 当然也可以用别的方法表示 懒得了)
### 代码

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0; //特判 起点是障碍直接return 0
        int flag = 1; 
        for(int i=0;i<obstacleGrid.size();i++){
            if(obstacleGrid[i][0] == 1)
                flag = 0;
            obstacleGrid[i][0] = flag;
        }
        flag = 1;
        for(int i=1;i<obstacleGrid[0].size();i++){
            if(obstacleGrid[0][i] == 1)
                flag = 0;
            obstacleGrid[0][i] = flag;
        }

        for(int i=1;i<obstacleGrid.size();i++)
            for(int j=1;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[i][j] == 1){
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if(long(obstacleGrid[i][j-1]) + obstacleGrid[i-1][j] > INT_MAX){ //要先把一个数类型转换为long才能计算 这步应该浪费了很多时间吧....?
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
            }

        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
```