### 解题思路
本题首先想到的思路是递归+剪枝。对于二维数组的递归，需要传递一个完整坐标点作为参数(x,y)
暴力递归思路：
    1. 先给出结束条件：搜索到最后一行
    2. 递归过程是将每一点距离加上下一行两个脚上的距离的最小值
暴力递归代码如下：

```
func traceBack(x,y int triangle [][]int) int{
    if x == len(triangle){
        return 0
    }

    return triangle[x][y]+min(traceBack(x+1,y),traceBack(x+1,y+1))
} 
```
显然，中间有些点被重复计算，所以可以用一个与triangle同维度的数组记录下已经查找过的最小路径，下次直接返回最小距离即可，不用再重复计算，也就是剪枝操作。
递归+剪枝代码：

```
func traceBack(x,y int triangle [][]int,flagArr [][]int) int{
    if x == len(triangle){
        return 0
    }
    if flagArr[x][y]>0{
        return flagArr[x][y]
    }
    minLen:=triangle[x][y]+min(traceBack(x+1,y),traceBack(x+1,y+1))
    flagArr[x][y]=minLen
    return minLen
} 
```
加入剪枝操作后还是时间超范围，但是理解了剪枝操作，对理解下面动态规划算法很有帮助。

动态规划思路：
动态规划一般需要不断修改原数组的值，达到每一步都是最有的效果，本题自底向上的动态规划解法如下：
算法思路：
    1.先锁定到倒数第二行最右边的点，从这里开始计算
    2.计算每个店到低端的最小值，覆盖掉triangle中的原值，这一步非常重要。接下来triangle中的值就代表距离低端最近的距离。

### 代码

```golang
func minimumTotal(triangle [][]int) int {
    tLen:=len(triangle)
    if tLen<=0{
        return 0
    }

    for i:=tLen-2;i>=0;i--{
        for j:=len(triangle[i])-1;j>=0;j--{
            triangle[i][j]=triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1])
        }
    }

    return triangle[0][0]
}

func min(a,b int) int{
    if a>b{
        return b
    }

    return a
}
```