思路与三数之和一样。固定两个数，双指针去寻找剩余两个数。

```
func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    n := len(nums)
    var res [][]int
    for i := 0; i < n-3; i++ {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }
        a := i+1
        for j := i+1; j < n-2; j++ {
            if j > a && nums[j] == nums[j-1] {
                continue
            }
            l, r := j + 1, n - 1
            for l < r {
                tmp := nums[i] + nums[j] + nums[l] + nums[r]
                if tmp == target {
                    res = append(res, []int{nums[i], nums[j], nums[l], nums[r]})
                    l++
                    r--
                    for l < r && nums[l] == nums[l-1] {
                        l++
                    }
                    for l < r && nums[r] == nums[r+1] {
                        r--
                    }
                } else if tmp < target {
                    l++
                    for l < r && nums[l] == nums[l-1] {
                        l++
                    }
                } else {
                    r--
                    for l < r && nums[r] == nums[r+1] {
                        r--
                    }
                }
            }
            
        }
    }
    return res
}
```
