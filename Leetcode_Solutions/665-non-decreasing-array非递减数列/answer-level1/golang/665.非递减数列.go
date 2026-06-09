### 解题思路

借鉴大佬的解法，遍历数组，当找到nums[i]>nums[i+1]时flag记录一次，同时调整一下nums[i]，使当前下标为0到i的数组非递减。若第二次再找到nums[i]>nums，说明一次变换无法使真个数组非递减，返回false。

### 代码

```golang
func checkPossibility(nums []int) bool {
	flag := 0
	for i := 0; i < len(nums) - 1; i++ {
		if(nums[i] > nums[i + 1]) {
			tmp := nums[i]
			if(i >= 1) {
				nums[i] = nums[i - 1]
			} else {
				nums[i] = nums[i + 1]
				}
			if(nums[i] > nums[i + 1]) {
				nums[i] = tmp
				nums[i + 1] = nums[i]
			}
			flag++
			if flag == 2 {
				return false
			}
		}
	}
return true
}
```