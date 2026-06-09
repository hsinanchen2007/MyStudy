题目解法多，我有点犹疑 
```
func climbStairs(n int) int {
    // memory := make(map[int]int)
    // return climb(0,n,memory)
    // return climb_dt(n)
    return dt_update(n)
}
//递归记忆
func climb(i int,n int,memory map[int]int) int{
    if(i == n){
        return 1
    }
    if (i> n){
        return 0
    }
    if(memory[i]==0){
        memory[i] = climb(i+1,n,memory) + climb(i+2,n,memory)
    }
    return memory[i]
}
//dt[n] = dt[n-1] + dt[n-2]
func climb_dt(n int) int{
    tmpMap := make(map[int]int)
    tmpMap[1] = 1
    tmpMap[2] = 2
    for i:=3;i<=n;i++{
        tmpMap[i]= tmpMap[i-1] + tmpMap[i-2]
    }
    return tmpMap[n]
}
//这个只是上面的优化，内存实际只要2个值 并不需要存储整个map
func dt_update(n int) int{
    x,y := 1,1
    for i:=2;i<=n;i++{
        x,y = y,y+x
    }
    return y
}
```