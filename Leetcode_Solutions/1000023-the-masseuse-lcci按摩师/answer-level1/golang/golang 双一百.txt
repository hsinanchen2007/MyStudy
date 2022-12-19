## 思路
针对每一个预约,做流式处理.

处理有两个选择, 接收当前预约和不接受当前预约

每一个选择会添加限制, 分析可知, 每一个限制影响不会超过三个元素的作用域.

## Code
```go
func massage(nums []int) int {
    var a, b, m = 0, 0 ,0
    for _, s := range nums{
        m = max(b, a+ s)
        a = b
        b = m
    }
    return b
}

func max (a, b int ) int {
    if a> b {
        return a
    }
    return b
}
```