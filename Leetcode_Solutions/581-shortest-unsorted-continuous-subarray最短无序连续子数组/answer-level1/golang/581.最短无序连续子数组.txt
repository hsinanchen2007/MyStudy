### 解题思路

升序排序，与原数组比较，算出中间两数组不同的一段长度即可。

### 代码

```golang
func findUnsortedSubarray(nums []int) int {
	tmp := []int{}
	tmp = append(tmp,nums...)
	sort.Ints(tmp)
	start,end := 0,0
	for i := 0;i < len(nums);i++ {
		if nums[i] != tmp[i] {
			start = i
			break
		}
	}
	for j := len(nums) - 1;j >= 0;j-- {
		if nums[j] != tmp[j] {
			end = j
			break
		}
	}
	if end == 0 {
		return 0
	}else {
		return end - start + 1
	}
}
```