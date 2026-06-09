
```golang
func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    ln := len(nums)
    ans := [][]int{}
    for i:=0;i<ln;i++{
        if nums[i] > 0 {
            break
        }
        //去重, 注意 nums[i-1] 而不是 nums[i+1]
        if i>0 && nums[i] == nums[i-1]{
            continue
        }
        //双指针
        l := i+1
        r := ln-1
        for l < r{
            sum := nums[i] + nums[l] + nums[r]
            if sum == 0 {
                ans = append(ans,[]int{nums[i] , nums[l],nums[r]})
                //去重注意方向l+1
                for l<r && nums[l] == nums[l+1]{
                    l++
                }
                //去重注意方向r-1
                for l<r && nums[r] == nums[r-1]{
                    r--
                }
                r--
                l++
            }else if sum > 0 {
                r--
            }else {
                l++
            }
        }
    }
    return ans
}

```