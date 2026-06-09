# 标题
执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :6.1 MB, 在所有 Go 提交中击败了100.00%的用户

做了一些小小的优化，空间复杂度O（1） 时间复杂度O（n）

```
func leastInterval(tasks []byte, n int) int {
    charSlice := [26]int{}
    max := 0
    count := 0
    for i:=0;i<len(tasks);i++{
        charSlice[tasks[i]-'A']++
        if max < charSlice[tasks[i]-'A']{
            max = charSlice[tasks[i]-'A']
            count = 1
        } else if charSlice[tasks[i]-'A']==max{
            count++
        }
    }
    if n== 0 || (max-1)*(n+1)+count < len(tasks){
        return len(tasks)
    }
    return (max-1)*(n+1)+count
}
```


