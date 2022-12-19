### 解题思路
此处撰写解题思路

### 代码

```golang
func twoSum(numbers []int, target int) []int {
    l := len(numbers)
    var res []int
    if l < 2 {
        return res
    }
    low := 0
    high := l - 1
    for low < high {
        tmp := numbers[low] + numbers[high]
        if tmp == target {
            res = append(res, low + 1, high + 1)
            break
        } else if tmp > target {
            high--
        } else {
            low++
        }
    }
    return res
}
```