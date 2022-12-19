```go
func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i, v := range nums {
        _, isExists := m[target - v]
        if isExists {
            return []int{m[target - v], i}
        }
        m[v] = i;
    }
    return nil
}
```
