```go
func createTargetArray(nums []int, index []int) []int {
    var target []int

    for i := 0; i < len(nums); i++ {
        target = append(target, 0)
        for j := len(target) - 1; j > index[i]; j-- {
            target[j] = target[j-1];
        }
        target[index[i]] = nums[i];
    }

    return target
}
```