### 解题思路
数组中的数字每次由先手的人（fir）选择一个（头或者尾），然后在剩下的数组中，原来后手的人变为了先手。
dp数组用二维数组：dp[i][j]表示取数组的第i到j个数字的时候先手和后手最后拿到的数字和
用dp的方法要知道basecase：当然就是数组中只有一个数字的时候，先手一定会将其取走。
状态转换：dp[i+1][j]表示先手取前面的那个数字（i位置的数字piles[i]），，dp[i][j-1]表示先手取后面的那个数字。

### 代码

```golang
type node struct {
    fir int
    sec int
}

func stoneGame(piles []int) bool {
    if len(piles) == 0 {
        return true
    }
    var (
        dp = make([][]*node,len(piles))
    )
    for i := 0;i < len(piles);i++ {
        dp[i] = make([]*node,len(piles))
    }
    for i := 0;i < len(piles); i++ {
        dp[i][i] = &node{fir:piles[i],sec:0}
    }
    for i := 1; i < len(piles); i ++ {
        line := 0
        col := i
        for col < len(piles) {
            tleft := &node{fir:dp[line][col-1].sec+piles[col],sec:dp[line][col-1].fir}
            tright := &node{fir:dp[line+1][col].sec+piles[line],sec:dp[line+1][col].fir}
            if tleft.fir > tright.fir {
                dp[line][col] = tleft
            }else {
                dp[line][col] = tright
            }
            line++
            col++
        }
    }
    if dp[0][len(piles)-1].fir > dp[0][len(piles)-1].sec {
        return true
    }
    return false
}
```