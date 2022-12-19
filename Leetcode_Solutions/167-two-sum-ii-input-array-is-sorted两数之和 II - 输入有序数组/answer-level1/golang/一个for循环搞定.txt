利用两个指针，往中间收拢查找。
10 分钟前	通过	8 ms	3.2 MB	golang
```
func twoSum(numbers []int, target int) []int {
    alen := len(numbers)
    arr := make([]int, 0)
    if alen <= 1 {
        return arr
    }
    j := alen-1
    i := 0
    for i>=0 && i<alen && j>=0 && j<alen {
        if numbers[i]+numbers[j]==target {
            return []int{i+1, j+1}
        } else if numbers[i]+numbers[j]>target {
            j--
        } else {
            i++
        }
    }
    return arr
}
```