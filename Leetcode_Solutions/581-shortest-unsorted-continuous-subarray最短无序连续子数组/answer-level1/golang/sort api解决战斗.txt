### 解题思路
解法很简单，sort一遍，找出头尾不一样的坐标，相减可得结果。
注意区分坐标是否相同。

### 代码

```golang
func findUnsortedSubarray(nums []int) int {
    tmp := make([]int,len(nums))
	start, end := -1, -1
	copy(tmp,nums)
	sort.Ints(tmp)
	for i:=0;i<len(nums);i++{
		if nums[i] != tmp[i]{
			start = i
            break
		}
	}
    for i := len(nums)-1; i >= 0; i-- {
        if nums[i] != tmp[i]{
			end = i
            break
		}
    }
    if start == end {
        return 0
    }
	return end-start+1
}
```