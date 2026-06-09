### 解题思路
算是一种dp思路吧，大佬没来我抛砖引玉了
比赛时不想用暴力法。
感觉这种思路比较好理解。

初始化dp把没两个的比较结果保存下来，避免了暴力法会出现的一些重复比较。

![image.png](https://pic.leetcode-cn.com/e929e3590f45778d7ee33eb846716e1fab368c609389cc073abdca0b09e17a88-image.png)



### 代码

```golang
func numTeams(rating []int) int {
    dp := make([][]int,len(rating))
    
    //dp[i][j]:表示rating[i]和rating[j]是否符合要求:
    //若rating[i] < rating[j] 且 i < j则为1
    //若rating[i] > rating[j] 且 i < j 则为2
    //否则为0
    
    res := 0
    
    for i,_ := range rating {
        t := make([]int,len(rating))
        dp[i] = t
        if i >= 1 {
            for j:=i+1;j<len(rating);j++ {
                if rating[i] < rating[j] {
                    dp[i][j] = 1
                } else if rating[i] > rating[j] {
                    dp[i][j] = 2
                }
            }
        }
    }
    
    // fmt.Println(dp)
    
    for k:=0;k<len(rating);k++ {
        for i:=k+1;i<len(rating);i++ {
            for j:=i+1;j<len(rating);j++ {
                if dp[i][j] == 1 && rating[k] < rating[i] {
                    res++
                }
                if dp[i][j] == 2 && rating[k] > rating[i] {
                    res++
                }
            }
        }
    }
    
    
    return res
}
```