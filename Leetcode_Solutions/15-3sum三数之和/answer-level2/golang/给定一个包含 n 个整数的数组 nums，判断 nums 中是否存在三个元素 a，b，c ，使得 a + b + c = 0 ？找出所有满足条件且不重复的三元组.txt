```
func threeSum(nums []int) [][]int {
    //capLen := int( len(nums) / 12)
    result := make([][]int, 0, 0 )
    sortInt := sort.IntSlice(nums)
    sortInt.Sort()
    // k是开始位置
    // i是中间位置
    // j是结束位置

    for k := 0; k < len(nums) - 2; k++ {
        if nums[k] > 0 {
            break
        }

        if k > 0 && nums[k] == nums[k - 1] { // 如果重复字段，则第二个就不用重复了
            continue
        }

        j := len(nums) - 1
        i := k + 1
        for {
            if nums[k] + nums[i] > 0 { // 前两数相加已经大于0了
                break
            }
            if i >= j { // 移动到头了
                break
            }
            if nums[k] + nums[i] + nums[j] < 0 {
                i++
                continue
            }
            if nums[k] + nums[i]  + nums[j] > 0 {
                j--
                continue
            }
            if nums[k] + nums[i] + nums[j] == 0 {
                if len(result) > 0 && result[len(result) - 1][0] == nums[k] && result[len(result) - 1][1] == nums[i] && result[len(result) - 1][2] == nums[j]{
                    i++
                    j--
                    continue
                }
                result = append(result,[]int{
                        nums[k],
                        nums[i],
                        nums[j],
                })
                i++
                j--
                continue
            }
        }
    }
    return result
}
```
