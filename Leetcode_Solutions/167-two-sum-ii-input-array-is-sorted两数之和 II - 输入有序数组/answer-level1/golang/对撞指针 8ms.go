```go
func twoSum(numbers []int, target int) []int {
    l := 0
    r := len(numbers) -1
    for l < r{
        if numbers[l] + numbers[r] == target{
            return []int{l+1,r+1}
        }
        if numbers[l] + numbers[r] > target{
            r--
        }else{
            l++
        }
    }
    return []int{l+1,r+1}
}
```
通过调整l,r索引值来不断逼近target