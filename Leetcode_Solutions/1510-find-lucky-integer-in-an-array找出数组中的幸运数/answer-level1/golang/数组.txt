### 解题思路
倒序查找

### 代码

```golang
func findLucky(arr []int) int {
    max := getMax(arr)
    res := make([]int, max+1)
    for _, num := range arr{
        res[num]++
    }
    for i := max; i > 0; i--{
        if res[i] == i {
            return i
        }
    }
    return -1
}
func getMax(nums []int) int {
    left, right := 0, len(nums)-1
    for left < right {
        if nums[left] < nums[right] {
            left++
        } else {
            right--
        }
    }
    return nums[left]
}
```