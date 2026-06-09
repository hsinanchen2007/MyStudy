### 解题思路
双指针

### 代码

```golang
//双指针， O(n),O(1)
func twoSum(numbers []int, target int) []int {
    if numbers == nil {
        return nil
    }
    i, j := 0, len(numbers)-1
    for i<j {
        sum := numbers[i]+numbers[j]
        if sum == target{
            return []int{i+1, j+1}
        } else if sum > target {
            j --
        } else {
            i ++
        }
    }
    return nil
}
```