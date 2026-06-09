### 解题思路
打卡

### 代码

```golang
func lengthOfLIS(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    d := []int{nums[0]}

    for i:=1;i<len(nums);i++ {
        if nums[i] <= d[len(d)-1] {
            low := 0
            height := len(d)-1
            pos := 0
            for low<=height{
                mid := (height+low)/2
                if nums[i] <= d[mid] {
                    pos = mid
                    height = mid - 1
                } else {
                    low = mid + 1
                }
            }
            d[pos] = nums[i]
        } else {
            d = append(d,nums[i])
        }
    }
    return len(d)
}
```