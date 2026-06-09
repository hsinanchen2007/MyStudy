```
func threeSum(nums []int) [][]int {
   func threeSum(nums []int) [][]int {
     res := make([][]int, 0)
    sort.Ints(nums)
    for i := 0; i < len(nums); i++ {
        if i > 0 && nums[i] == nums[i-1] && len(nums) > 1 {
            continue
        }
        L := i + 1
        R := len(nums) - 1
        for L < R {
            sum := nums[i] + nums[L] + nums[R]
            if sum == 0 {
                res = append(res, []int{nums[i], nums[L], nums[R]})
                for L < R && nums[L] == nums[L+1] {
                    L++
                }
                for L < R && nums[R] == nums[R-1] {
                    R--
                }
                R--
                L++
            }
            if sum > 0 {
                R--
            }
            if sum < 0 {
                L++
            }
        }
    }
    return res
}

}
```
