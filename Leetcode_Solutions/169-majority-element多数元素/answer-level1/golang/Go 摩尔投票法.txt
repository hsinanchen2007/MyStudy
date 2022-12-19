### 解题思路

### 代码

```golang
func majorityElement(nums []int) int {
    if len(nums) == 0 {
        return -1
    }
    var (
        count = 1
        num = nums[0]
    )
    for i := 1; i < len(nums); i ++ {
        if num == nums[i] {
            count ++
        }else {
            count --
            if count == 0 {
                num = nums[i+1]
                count ++
                i ++
            }
        }
    }
    return num
}
```