双指针的go实现, 执行用时36ms
```go
targetSum := 0
numsLen := len(nums)
var result [][]int
sort.Ints(nums)
for i := 0; i < numsLen-2; i++ {
    if nums[i] > targetSum {
        break
    }
    if i > 0 && nums[i] == nums[i-1] {
        continue
    }
    l := i + 1
    r := numsLen - 1
    for l < r {
        temp := nums[i] + nums[l] + nums[r]
        if temp > targetSum {
            r--
        } else if temp < targetSum {
            l++
        } else {
            result = append(result, []int{nums[i], nums[l], nums[r]})
            for l < r && nums[l] == nums[l+1] {
                l++
            }
            for l < r && nums[r] == nums[r-1] {
                r--
            }
            l++
            r--
        }
    }
}
return result
```