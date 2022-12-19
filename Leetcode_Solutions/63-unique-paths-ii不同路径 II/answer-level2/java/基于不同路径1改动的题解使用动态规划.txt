### 解题思路
这一题和不同路径一相似，建议先做不同路径1，这里有两个不同：
（1）由于加入了障碍物，使得在进行边界化时，一旦有一个为障碍物，后面的节点都会呈不可访问状态
（2）由于加入了障碍物，dp方程发生了变化，只有state[i-1][j]和state[i][j-1]不为-1时，才相加

### 代码

```java
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        //状态数组
        int state[][]=new int[obstacleGrid.length][obstacleGrid[0].length];
        //确定初始状态和边界情况
        boolean flag=false;
        for(int i=0;i<obstacleGrid.length;i++) 
        {
                if(obstacleGrid[i][0]==1)
                {
                    flag=true;
                }
                if(flag)
                {
                    state[i][0]=-1;
                }else
                {
                    state[i][0]=1;
                }
        }
        flag=false;
         for(int i=0;i<obstacleGrid[0].length;i++) 
        {
             
            if(obstacleGrid[0][i]==1)
            {
               flag=true;
            }
            if(flag)
            {
                state[0][i]=-1;
            }else
            {
                state[0][i]=1;
            }
        }
        //记忆数组
        for(int i=1;i<obstacleGrid.length;i++)
        {
            for(int j=1;j<obstacleGrid[0].length;j++)
            {
                //当为障碍物时，不记录这里的值
                if(obstacleGrid[i][j]==1)
                {
                    state[i][j]=-1;
                    continue;
                }
                //dp方程发生了变化，当state[i-1][j]和state[i][j-1]不为-1时，才加上
                int pre1=0;
                if(state[i-1][j]!=-1)
                {
                    pre1=state[i-1][j];
                }
                int pre2=0;
                if(state[i][j-1]!=-1)
                {
                    pre2=state[i][j-1];
                }
                state[i][j]=pre1+pre2;
            }
        }
        if(state[state.length-1][state[0].length-1]==-1)
        {
            return 0;
        }
        return state[state.length-1][state[0].length-1];
    }
}
```