# 解法1： 直接求最大值，遍历填值

```go
func printNumbers(n int) []int {
    max := int(math.Pow10(n)) - 1
    res := make([]int, max)
    for i:=0; i<max; i++ {
        res[i] = i+1
    }
    return res
}
```

# 解法2： 按数字进位处理，暂留空

ps: 其实返回字符串数组，把n调大，这道题就还行。现在这个太鸡贼了...
