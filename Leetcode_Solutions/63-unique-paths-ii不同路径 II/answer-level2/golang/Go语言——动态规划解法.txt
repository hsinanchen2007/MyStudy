### 解题思路
这道题是在"不同路径"题目上加大了难度，增加了一些不可走的点，"不同路径"的题目提供了一种递归+剪枝的接法，参考链接如下：https://leetcode-cn.com/problems/unique-paths/solution/goyu-yan-di-gui-he-jian-zhi-jie-fa-by-zhang-xu-don/

这种题的特点是：如果用遍历的方式搜索，一个状态和前面的状态满足线性关系，此时可以用动态规划求解。初始条件：第一行和第一列的状态可直接求得(1/0).递推公式：
dp[i][j]=dp[i-1][j]+dp[i][j-1]，即每个点的路径和是其上和左路径和的和。
算法思路：
 1. 设定初始条件。第一行中obstacleGrid第一个1之前的每个点的路径和均为1，此点之后为0；第一列同理
 2. 开始动态规划。遍历obstacleGrid中的每一个点。对于obstacleGrid[i][j]==1的点，说明不能到此点，dp[i][j]=0;对于obstacleGrid[i][j]==0的点，说明可以到达这一点，则使用递推公式。
 3. 返回dp[row-1][col-1]
### 代码

```golang
func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    if len(obstacleGrid)==0{
        return 0
    }
    row:=len(obstacleGrid)
    col:=len(obstacleGrid[0])

    dp:=make([][]int,row)
    for i:=0;i<row;i++{
        dp[i]=make([]int,col)
    }
    //1 设定初始条件
    i:=0
    for i<row && obstacleGrid[i][0]==0{
        dp[i][0] = 1
        i++
    }
    if i!=row{
        for j:=i;j<row;j++{
            dp[j][0]=0
        }
    }

    i=0
    for i<col && obstacleGrid[0][i]==0{
        dp[0][i] = 1
        i++
    }
    if i!=col{
        for j:=i;j<col;j++{
            dp[0][j]=0
        }
    }   

    //2 开启动态规划
    for i:=1;i<row;i++{
        for j:=1;j<col;j++{
            if obstacleGrid[i][j]==1{ //对于不能走的点，dp为0
                dp[i][j]=0
            }else{                    //对于可以走的点，dp用地推公式求解
                dp[i][j]=dp[i-1][j]+dp[i][j-1]
            }           
        }
    }

    return dp[row-1][col-1]
}
```