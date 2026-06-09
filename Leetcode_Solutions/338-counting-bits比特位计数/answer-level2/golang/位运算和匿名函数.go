大家肯定知道 n & (n-1) 这个操作可以把n的最后一个二进制1变成0吧。所以解题方法很简单，与操作进行几次，就有几个1.
为了达到最有效率，初始化用于返回结果的切片res的时候，指定一下size，这种方式比从空切片一个个append要快。
这里还使用了go的匿名函数。

```go
func countBits(num int) []int {
    f:= func (n int) int{
        var c int
        for n != 0 {
            c++
            n &= n-1
        }
        return c
    }
    res := make([]int,num+1)
    for i:=0;i<=num;i++{
        res[i]= f(i)
    }
    return res
}

```
