从后向前dp

```
var cache []int//存储dp后的值，防止对同一个index重复计算

func mincostTickets(days []int, costs []int) int {
    cache = make([]int,len(days))
    return dp(days ,costs,0)
}

func dp(days,cost[]int,i int)int{
    if i>= len(days){//j++可能会越界
        return 0
    }
    if cache [i]!= 0{//已有不再重复计算
        return cache[i]
    }
    j := i
    re := 2<<31 
    re = min(re,dp(days,cost,j+1)+cost[0])//计算当前按一天买票
    for ;j<len(days)&&days[j]-days[i]<7;j++{}//周票方案dp
    re = min(re,dp(days,cost,j)+cost[1])
    for ;j<len(days)&&days[j]-days[i]<30;j++{}//月票方案dp
    re = min(re,dp(days,cost,j)+cost[2])
    cache [i] = re
    return re
}

func min(a,b int)int{
    if a>b {
        return b
    }
    return a
}
```
