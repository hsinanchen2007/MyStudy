不得不说go的性能就是优秀
执行用时 :0 ms, 在所有 golang 提交中击败了100.00%的用户
内存消耗 :1.9 MB, 在所有 golang 提交中击败了100.00%的用户
### 解题思路
4个一组, 头尾单独处理

### 代码

```golang
func clumsy(N int) int {
    m := []int{0, 1, 2, 6}
    // 单独处理下长度很短的情况
    if N < 4{
        return m[N]
    }
    
    // 第一轮单独处理
    re := N * (N-1) / (N-2) + (N-3)
    N = N - 4
    
    // 处理中间部分
    for N > 3{
        re = re - N * (N-1) / (N-2) + (N-3)
        N = N - 4
    }
    
    // 剩余单独处理
    if N > 0 {
        re = re - m[N]
    }
    
    return re
}
```