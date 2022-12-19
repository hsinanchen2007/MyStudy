### 解题思路
顺序数组，每次比较和前一个元素的值即可，设置一个标识no，用来标记下一个该插入的位置，依次计算即可

### 代码

```golang
func removeDuplicates(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}
	no := 1
	for i , v := range nums {
		if i == 0 {
			continue
		}
		if v == nums[i-1] {
			continue
		}else {
			nums[no] = v
			no ++
		}
	}
	return no
}
```