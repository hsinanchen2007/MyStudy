### 解题思路
此处撰写解题思路

### 代码

```golang
func fourSum(nums []int, target int) [][]int {
    results := make([][]int, 0)
    exits := map[string]struct{}{}
    for i := 0; i < len(nums); i++ {
        if items := threeSum(nums[i+1:], target-nums[i]); len(items) > 0 {
            for _, item := range items {
                result := []int{nums[i]}
                result = append(result, item...)
                sort.Ints(result)
                key := fmt.Sprintf("%d-%d-%d-%d", result[0], result[1], result[2], result[3])
                if _, ok := exits[key]; ok {
                    continue
                } else {
                    exits[key] = struct{}{}
                }
                results = append(results, result)
            }
        }
    }
    return results
}

func threeSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    result := make([][]int, 0)
    for i := 0; i < len(nums); i++ {
        start, end := i+1, len(nums) - 1
        for start < end {
            if nums[start] + nums[end] > target - nums[i] {
                end -= 1
            } else if nums[start] + nums[end] < target - nums[i] {
                start += 1
            } else {
                item := []int{nums[i], nums[start], nums[end]}
                result = append(result, item)
                start += 1
            }
        }
    }
    return result
}
```