暴力求解 o(n^2)

计算 j到i的劳累值。（0<=j<=i）,如果劳累值大于0，和最大值比较

优化点：如果最大值大于当前剩余长度，可以直接退出
```
if max > (i + 1 ) {
    break
}
```

完整代码：
```
func longestWPI(hours []int) int {
	max := 0
    for i := len(hours) - 1; i >= 0; i-- {
        if max > (i + 1 ) {
            break
        }
        tied := 0
        for j := i; j >= 0; j-- {
            if hours[j] > 8 {
                tied++
            } else {
                tied--
            }
            if tied > 0 && i - j + 1 > max {
                max = i - j + 1
            }
        } 
    }
	return max
}
```
