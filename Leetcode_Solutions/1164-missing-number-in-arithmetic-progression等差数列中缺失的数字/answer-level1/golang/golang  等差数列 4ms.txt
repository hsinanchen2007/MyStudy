题目告诉我这个数组是一个等差数列，且缺失一项， 所以共有 `len(arr) + 1` 项， 且首项和尾项已经给出，所以：
公差 `d = (last - first) / n - 1`，且 `arr[i] - arr[i-1] = d`。
所以我们只需要计算连续两数之差是否等于d，如果不等于，说明中间少一个数字，且这个数字是我们要找的那个数字
这里要注意，如果公差为0时，需要特殊判断。
```
func missingNumber(arr []int) int {
    n := len(arr)
    d := (arr[n-1] - arr[0])/n
    if d == 0 {
        return arr[0]
    }
    for i := 1; i < len(arr); i++ {
        if arr[i] - arr[i-1] != d {
            return arr[i-1] + d
        }
    }
    return -1
}
```
