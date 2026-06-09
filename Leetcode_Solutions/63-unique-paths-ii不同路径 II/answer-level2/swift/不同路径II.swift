1.如果第一个格子点是obstacleGrid[0][0] 是 1, 说明有障碍物,那么机器人就不能做任何的移动,我们就直接返回0;
2.否则如果obstacleGrid[0][0] 是 0, 我们初始化这个值为1,然后继续算法;
3.遍历第一行,如果有个格子是为1,说明当前节点有障碍物,没有路径可走,设置为0;否则设这个值是前一个节点的值,如下:
let verticalValue = (obstacleGrid[0][i] == 0 && dp[0][i - 1] == 1) ? 1 : 0

dp[0].append(verticalValue)

4.遍历第一列,如果有一个格子初始值是1, 说明当前节点为障碍物,没有路径可以通过, 设置为0; 否则这个值为前一个节点的值
(dp[i-1][0]) == 0 || (obstacleGrid[i][0] == 1)判断为0或者1,加入进去
5.现在从obstacleGrid[1][1]开始遍历整个数组,如果某个个字初始化不包含任何障碍物,就把值赋予上方和左侧两个格子方案之和
　　　　let value = dp[i - 1][j] + dp[i][j - 1]
　　　　dp[i].append(value)
　　　　不包含障碍物上面.
6.如果这个点是障碍物设置为0, 保证对后面的路径不产生贡献.
```

func uniquePathsWithObstacles(_ obstacleGrid: [[Int]]) -> Int {
        guard obstacleGrid.count > 0 else {return -1}
        let rowLength = obstacleGrid.count //显示多少行
        let verticalLength = obstacleGrid[0].count //显示多少列
        var dp = [[Int]]()
        if obstacleGrid[0][0] == 1 {//1代表有障碍
            return 0
        }
        
        //初始化第一个元素,也就是dp[0][0]
        var rowArr = [Int]()
        for i in 0..<rowLength {
            if  i == 0 {
                for j in 0..<verticalLength {
                    if j == 0 {
                        rowArr.append(1)
                    }
                }
            }
        }
        dp.append(rowArr)
        
        //初始化第一列
        for i in 1..<rowLength {
            var vertical = [Int]()
            let rowValue = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0
            for j in 0..<verticalLength {
                if j == 0 {
                    vertical.append(rowValue)
                }
            }
            dp.append(vertical)
        }
        //初始化第一行
        for i in 1..<verticalLength {
            let verticalValue = (obstacleGrid[0][i] == 0 && dp[0][i - 1] == 1) ? 1 : 0
            dp[0].append(verticalValue)
        }
        //初始化其它元素
        for i in 1..<rowLength {
            for j in 1..<verticalLength {
                if obstacleGrid[i][j] == 0 {
                    let value = dp[i - 1][j] + dp[i][j - 1]
                    dp[i].append(value)
                } else {
                    dp[i].append(0)
                }
            }
        }
        return dp[rowLength-1][verticalLength-1]
    }
```
