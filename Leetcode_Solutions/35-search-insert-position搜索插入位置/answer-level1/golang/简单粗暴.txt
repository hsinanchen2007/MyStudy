### 解题思路
此处撰写解题思路

### 代码

```golang
func searchInsert(nums []int, target int) int {
    for i,v := range(nums) {
        if v >= target{
            return i
        }
    }

    return len(nums)
}
```