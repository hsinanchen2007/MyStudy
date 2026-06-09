简单的数组切割，主要理解题意
```
func dietPlanPerformance(calories []int, k int, lower int, upper int) int {
    sum, count := 0, 0
    if len(calories) < k {
        return 0
    }
    for i := 0; i < k; i++ {
        sum += calories[i]
    }
    if sum < lower {
        count--
    } else if sum > upper {
        count++
    }
    for i := k; i < len(calories); i++ {
        sum += calories[i] - calories[i - k]
        if sum < lower {
            count--
        } else if sum > upper {
            count++
        }
    }
    return count
}
```
