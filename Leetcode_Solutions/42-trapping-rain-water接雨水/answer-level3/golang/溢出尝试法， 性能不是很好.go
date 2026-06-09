当前位置 寻找左边的位置 最大值(leftMax)
当前位置 寻找右边的位置 最大值(rigtMax)

获取最小的值min(leftMax, rightMax)
和当前的值比较出算出该位置应该需要存的量


```go
func trap(height []int) int {
    var start, total int
    for i, v := range height {
        if v == 0 && start == 0 {continue}
        if v != 0 && start == 0 {start = v; continue}

        left := leftMax(i, height)
        right := rightMax(i, height)

        if left > v && right > v && left != 0 && right != 0 {
            if left > right {
                total = total + right - v
            } else {
                total = total + left  - v
            }
        }
    }

    return total
}

func leftMax(i int, s  []int) int{
    current := s[i]
    tmpMax := 0
    for j := i - 1 ; j >= 0; j-- {
        if tmpMax < s[j] {tmpMax = s[j]}
    }

    if tmpMax > current {return tmpMax}
    return 0
}

func rightMax(i int,  s []int) int{
    current := s[i]
    tmpMax := 0
    for j := i + 1 ; j < len(s); j++ {
        if tmpMax < s[j] { tmpMax = s[j] }
    }

    if tmpMax > current { return tmpMax}
    return 0
}
```
