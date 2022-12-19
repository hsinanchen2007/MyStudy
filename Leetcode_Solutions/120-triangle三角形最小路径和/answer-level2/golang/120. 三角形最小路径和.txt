自顶向下记忆化搜索
```
func minimumTotal(triangle [][]int) int {
    storeMem := make(map[string]int,)
    return findMax(triangle,0,0,storeMem)
}

func findMax(triangle [][]int,level int,index int,storeMem map[string]int) int{
    key :=strconv.Itoa(level)+"-"+strconv.Itoa(index)
    if value,ok := storeMem[key]; ok {
        return value
    }
    if level == len(triangle)-1 {
        storeMem[key] = triangle[level][index]
        return triangle[level][index]
    }
   
    left := findMax(triangle,level+1,index,storeMem)
    right := findMax(triangle,level+1,index+1,storeMem)
    if left < right {
        storeMem[key] = left+triangle[level][index]
        return  left+triangle[level][index]
    }else{
        storeMem[key] = right+triangle[level][index]
        return  right+triangle[level][index]
    }
}
```

//DP方程
// dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+dp[i][j]

```
func minimumTotal(triangle [][]int) int {
    //初始化状态数组
    dp := triangle
    for i:=len(triangle)-2 ; i>=0  ;i-- {
        for j:= 0 ; j < len(triangle[i]); j++ {
           if dp[i+1][j] < dp[i+1][j+1] {
                dp[i][j] += dp[i+1][j]
           }else{
                dp[i][j] += dp[i+1][j+1]
           }
        }
    }
    return dp[0][0]
}

```
