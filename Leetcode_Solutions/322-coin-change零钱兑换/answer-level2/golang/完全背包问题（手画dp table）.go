### 做这个题有一阵子了，当时直接套用了完全背包的模板了，最近发现，直接套模板容易让自己走捷径，但是对于背包的实质理解不清楚，特意推一下完全背包执行过程
#### 大佬就不要看了（我太菜了）

1. 完全背包：有一个背包，体积为V，有物品（vi--体积 ， wi--价值），问该如何拿，才能得到最高的价值。其中，如果每个物品最多只能拿一次，则称之为01背包。反之，如果每个物品可以无限制拿，则为完全背包

2. 完全背包的状态可以定义为如下：dp[i][j]:当考虑放入第i个物品时，占用空间j所能得到的最大的价值；状态转移方程为：dp[i][j]=Max(dp[i-1][j],dp[i][j-vi]+wi)

3. 状态转移方程之所以写为上述，是因为，当考虑新放第i个物品时，此时的选择有两种，1：不放，那么就是dp[i-1][j] 2：放，那么就需要把背包从当前容量为j的状态给它掏出去vi的容量，这样才能将物品i放进去，即dp[i][j-vi],那么dp[i][j]=Max(dp[i-1][j],dp[i][j-vi]+wi)

4. 分析本题，可以很明确的看出来，这就是一个完全背包的问题

5. 总金额就是背包容量，硬币就是物品，可以表示为，物品（vi--coins[i], wi--1(价值就是数量，每个硬币的数量就是1)）

6. 定义状态：dp[i][j]:当考虑放入第i枚硬币时，所凑成金额j时的最小硬币数。仿照上面，状态转移方程为：dp[i][j]=Min(dp[i-1][j],dp[i][j-conins[i]]+1)

7. 现在需要思考初始条件了，求的是最小值，那么我们在最开始时，需要将值设为最大，同时dp[0][0]=0

![QQ图片20200308212821.jpg](https://pic.leetcode-cn.com/248a4f59f7ff99a5388c23fccfea3c919b3d85da4fbdd0039db40a70b413482f-QQ%E5%9B%BE%E7%89%8720200308212821.jpg)

```
//动态规划（不压缩空间）
func coinChange(coins []int, amount int) int {
    dp:=make([][]int,len(coins)+1)//定义状态
    for i:=0;i<=len(coins);i++{
        dp[i]=make([]int,amount+1)
    }
    //初始条件
    for j:=0;j<=amount;j++{
        dp[0][j]=amount+1
    }
    dp[0][0]=0
    for i:=1;i<=len(coins);i++{
        for j:=0;j<=amount;j++{
            //状态转移方程
            if j >= coins[i-1]{
                dp[i][j]=int(math.Min(float64(dp[i-1][j]),float64(dp[i][j-coins[i-1]]+1)))
            }else{
                dp[i][j]=dp[i-1][j]
            }
        }
    }
    if dp[len(coins)][amount]>amount{
        return -1
    }else{
        return dp[len(coins)][amount]
    }
}
```

8. 背包问题是可以优化空间的，从上面可以知道，dp[i][j]只和dp[i-1][j] 和 dp[i][j-vi]有关，和其有关的是它的上一个，以及前j-vi那个，那完全可以用一维数组表示即dp[j]=Min(dp[j],dp[j-vi]),解释：外面的dp[j]表示当前行要更新的dp[j],而里边的dp[j]是指上一行的值,即dp[j]=dp[i-1][j],因为dp在更新时，是从前向后开始的，所以，dp[j-vi]肯定是当前行已经更新过的。也即dp[j-vi]=dp[i][j-vi]

9. 代码写起来和之前的一致，只是二维变为一维

![QQ图片20200308215219.jpg](https://pic.leetcode-cn.com/d48815811a470465793a493d401af10732e2ab4b3b4ae4817fc84f6107cd6c1e-QQ%E5%9B%BE%E7%89%8720200308215219.jpg)

```
//动态规划（压缩空间）
func coinChange(coins []int, amount int) int {
    dp:=make([]int,amount+1)
    //初始值
    for i:=0;i<=amount;i++{
        dp[i]=amount+1
    }
    dp[0]=0
    
    for i:=1;i<=len(coins);i++{
        for j:=0;j<=amount;j++{
            if j >= coins[i-1]{
                dp[j]=int(math.Min(float64(dp[j]),float64(dp[j-coins[i-1]]+1)))
            }
        }
    }
    if dp[amount] > amount{
        return -1
    }else{
        return dp[amount]
    }  
}
```

### 推荐一个up主，叫"一俩三四五"，对于dp讲解的很不错，这是真大神，每周定期更新周赛










