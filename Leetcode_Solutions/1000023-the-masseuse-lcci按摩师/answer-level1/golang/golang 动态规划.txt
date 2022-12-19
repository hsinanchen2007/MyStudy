### 解题思路

适合使用动态规划来解决的问题，具有的特点

1. 最优子结构

问题的最优解包含的子问题的解也是最优解。
拥有此性质，也就是说，问题拆分成子问题可以很方便的解决。

2. 无后效性
未来与过去无关。

3. 重叠子问题
动态规划主要用于解决重叠子问题。子问题的解存到表中，使得子问题不必重复计算。因此，当没有重叠子问题，就不需要使用动态规划解决。是不是用表存储，要看问题的复杂性。此问题使用两个临时变量就可以解决。

```
func massage(nums []int) int {
    pre, curr := 0, 0
    for _, m := range nums {
        curr, pre = max(pre+m, curr), curr
    }
    return curr
}
func max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```