### 解题思路
此处撰写解题思路

### 代码

```golang
func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    var res [][]int
    len_ := len(nums)
    if nums == nil || len_ < 3 {
        return res
    } 

    for i := 0; i < len_-1; i++ {
        if nums[i] > 0 {
            break
        }
        if i > 0 && nums[i] == nums[i-1] {
            continue;
        }

        l, r := i+1, len_-1
        for l < r {
            sum := nums[i] + nums[l] + nums[r]
            if sum == 0 {
                res = append(res, []int{nums[i], nums[l], nums[r]})
                for l < r {
                    if nums[l+1] == nums[l] {
                        l++
                        continue
                    }
                    if nums[r] == nums[r-1]{
                        r--
                        continue
                    }
                    break
                }
                l++
                r--
            } else if sum < 0 {
                l++
            } else {
                r--
            }
        }
    }

    return res
}
```