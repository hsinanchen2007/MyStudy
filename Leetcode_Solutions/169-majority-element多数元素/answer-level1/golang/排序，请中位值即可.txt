### 解题思路
此处撰写解题思路

### 代码

```golang
func majorityElement(nums []int) int {
    sort.Ints(nums)
    i := len(nums)/2
    return nums[i]
    
}
```