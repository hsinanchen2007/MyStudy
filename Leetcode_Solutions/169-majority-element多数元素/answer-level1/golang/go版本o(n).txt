### 解题思路
此处撰写解题思路

### 代码

```golang
func majorityElement(nums []int) int {
    var candidate int = nums[0]
    var count int = 1

    for i:=1; i<len(nums); i++ {
        if count == 0 {
            candidate = nums[i]
            count = 1
        } else if candidate == nums[i] {
            count++
        } else {
            count--
        }
    }

    return candidate
}
```