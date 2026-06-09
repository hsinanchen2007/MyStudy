话说这周的题都好友好，两个解法，暴力穷举无限超时（被问我怎么知道的）。
DP算法很容易的，作为hard真的有点丢人啊...
附上代码，这个arrLen长度真的是个坑，不处理会爆内存...
```
func numWays(steps int, arrLen int) int {
    ans:=make([][]int,steps)
    if steps<arrLen{
        arrLen=steps
    }
    for i:=0;i<steps;i++{
        ans[i]=make([]int,arrLen+2)
    }
    ans[0][1]=1
    for i:=1;i<steps;i++{
        for j:=1;j<=arrLen;j++{
            ans[i][j]=ans[i-1][j]+ans[i-1][j-1]+ans[i-1][j+1]
            ans[i][j]=ans[i][j]%(1000000000+7)
        }       
    }
    return (ans[steps-1][1]+ans[steps-1][2])%(1000000000+7)
}
```
最后一行没必要全算的...
